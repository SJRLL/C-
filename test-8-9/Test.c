#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 9999

typedef struct node{
	char *English;
	char *Chinese;
	struct node *next;
}linklist;
void insert(char *str1, char *str2, linklist **linkhash);

void openDict(linklist **linkhash)
{
	FILE *fp = fopen("dict.txt", "r");
	char buf[1024];
	int len = 0;
	int i = 0;

	while (!feof(fp))
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), fp);
		len = strlen(buf);

		char eng[50] = { 0 };
		char cha[50] = { 0 };

		char* str = buf;
		char* E = eng;
		char* C = cha;

		while (*str != '\0')
		{
			while (*str != ' ')
			{
				*E = *str;
				str++;
				E++;
			}
			*E = '\0';

			while (*str == ' ')
			{
				*str++;
			}
			while (*str != '\0')
			{
				*C = *str;
				str++;
				C++;
			}
			*C = '\0';
		}


		insert(eng, cha, linkhash);

		memset(eng, 0, sizeof(eng));
		memset(cha, 0, sizeof(cha));

	}
}

int Hash(char* str)
{
	int max = 0, n = 0;
	while (*str != '\0')
	{
		n = *str - 'a';
		max += n;
		*str++;
	}
	return max;
}


void insert(char *str1, char *str2, linklist **linkhash)
{
	int pos = Hash(str1);

	linklist *p = (linklist *)malloc(sizeof(linklist));
	if (p == NULL)
		return;
	p->English = str1;
	p->Chinese = str2;
	p->next = NULL;

	if (linkhash[pos] == NULL)
		linkhash[pos] = p;
	else
	{
		p->next = linkhash[pos];
		linkhash[pos] = p;
	}

}


char* findhash(char* str, linklist** linkhash)
{
	int pos = Hash(str);
	linklist* p = linkhash[pos];
	while (p != NULL)
	{
		if (p->English == str)
			return p->Chinese;
		else
			p = p->next;
	}
	return NULL;
}

int main()
{
	char str[32];
	linklist *linkhash[MAXSIZE] = { NULL };

	gets(str);
	openDict(linkhash);

	printf("%s\n", findhash(str, linkhash));

	return 0;
}
