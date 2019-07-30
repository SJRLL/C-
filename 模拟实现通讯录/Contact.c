#define _CRT_SECURE_NO_WARNINGS 1

#include"Contact.h"

void InitContact(Contact* pcon)
{
	assert(pcon);
	pcon->sz = 0;
	memset(pcon->data, 0, sizeof(pcon->data));//��ʼ������
}

void AddContact(Contact* pcon)
{
	if (pcon->sz == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
	}
	else
	{
		printf("����������:>\n");
		scanf("%s", pcon->data[pcon->sz].name);
		printf("����������:>\n");
		scanf("%d", &(pcon->data[pcon->sz].age));
		printf("�������Ա�:>\n");
		scanf("%s", pcon->data[pcon->sz].sex);
		printf("����������:>\n");
		scanf("%s", pcon->data[pcon->sz].nation);
		printf("������绰:>\n");
		scanf("%s", pcon->data[pcon->sz].tale);
		printf("�������ͥסַ:>\n");
		scanf("%s", pcon->data[pcon->sz].addr);
		printf("�������ϵ:>\n");
		scanf("%s", pcon->data[pcon->sz].realtion);

		pcon->sz++;
		printf("��ӳɹ�\n");
	}
}


void ShowContact(const Contact* pcon)
{
	int i = 0;
	printf("%-15s\t%-5s\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "����", "�绰", "��ַ", "��ϵ");
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%-15s\t%-5d\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\n",
			pcon->data[i].name,
			pcon->data[i].age,
			pcon->data[i].sex,
			pcon->data[i].nation,
			pcon->data[i].tale,
			pcon->data[i].addr,
			pcon->data[i].realtion);
	}
}

static int FindEnty(Contact* pcon, char name[])
{
	int i = 0;
	assert(pcon);
	for (i = 0; i < pcon->sz; i++)
	{
		if (strcmp(pcon->data[i].name, name)==0)
		{
			return i;
		}
	}
	return -1;

}
void SearchContact(Contact* pcon)
{
	assert(pcon);
	char name[MAX_NAME] = { 0 };
	int pos = 0;
	printf("��������Ҫ���ҵ���ϵ��\n");
	scanf("%s", &name);
	pos = FindEnty(pcon, name);
	int i = 0;
	if (pos == -1)
	{
		printf("����ϵ�˲����ڣ��޷�����\n");
	}
	else
	{
		printf("%-15s\t%-5s\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "����", "�绰", "��ַ", "��ϵ");

		printf("%-15s\t%-5d\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\n",
			pcon->data[i].name,
			pcon->data[i].age,
			pcon->data[i].sex,
			pcon->data[i].nation,
			pcon->data[i].tale,
			pcon->data[i].addr,
			pcon->data[i].realtion);

	}
}

void DelContact(Contact* pcon)
{
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	assert(pcon);
	if (pcon->sz == 0)
	{
		printf("��ͨѶ¼Ϊ�գ��޷�ɾ��\n");
	}
	else
	{
		printf("��������Ҫɾ������ϵ��;>");
		scanf("%s", &name);
		pos = FindEnty(pcon, name);
		if (pos == -1)
		{
			printf("����ϵ�˲����ڣ��޷�ʵ��ɾ��\n");
		}
		else
		{

			int i = 0;
			for (i = 0; i < pcon->sz - 1; i++)
			{
				pcon->data[i] = pcon->data[i + 1];
			}
			pcon->sz--;
			printf("ɾ���ɹ�\n");
		}
	}
}

void EmptyContact(Contact* pcon)//���ͨѶ¼
{
	assert(pcon);
	int i = 0;
	while (pcon->sz)
	{
		pcon->sz--;
	}
	if (pcon->sz == 0)
	{
		printf("��ճɹ�\n");
	}
}


//void SortContact(Contact* pcon)//����������
//{
//	assert(pcon);
//	int b = 0;
//	int i = 0;
//	int e = 0;
//	int temp = 0;
//	char name[MAX_NAME] = { 0 };
//	char sex[SEX_MAX] = { 0 };
//	short int  age = { 0 };
//	char nation[NATION_MAX] = { 0 };
//	char tale[TALE_MAX] = { 0 };
//	char addr[ADDR_MAX] = { 0 };
//	char realtion[REALTION_MAX] = { 0 };
//	int a = pcon->sz-1;
//	for (b = 0; b < a; b++)
//	{
//		for (i = 0; i< a  - b; i++)
//		{
//			int c = strcmp(pcon->data[i].name, pcon->data[i + 1].name);
//			if (c == 1)
//			{
//				strcpy(name, pcon->data[i].name);
//				strcpy(pcon->data[i].name, pcon->data[i + 1].name);
//				strcpy(pcon->data[i + 1].name, name);
//
//				strcpy(sex, pcon->data[i].sex);
//				strcpy(pcon->data[i].sex, pcon->data[i + 1].sex);
//				strcpy(pcon->data[i + 1].sex, sex);
//
//				e = pcon->data[i].age;
//				pcon->data[i].age = pcon->data[i + 1].age;;
//				pcon->data[i + 1].age = e;
//
//				strcpy(nation, pcon->data[i].nation);
//				strcpy(pcon->data[i].nation, pcon->data[i + 1].nation);
//				strcpy(pcon->data[i + 1].nation, nation);
//
//				strcpy(tale, pcon->data[i].tale);
//				strcpy(pcon->data[i].tale, pcon->data[i + 1].tale);
//				strcpy(pcon->data[i + 1].tale, tale);
//
//				strcpy(addr, pcon->data[i].addr);
//				strcpy(pcon->data[i].addr, pcon->data[i + 1].addr);
//				strcpy(pcon->data[i + 1].addr, addr);
//
//				strcpy(realtion, pcon->data[i].realtion);
//				strcpy(pcon->data[i].realtion, pcon->data[i + 1].realtion);
//				strcpy(pcon->data[i + 1].realtion, realtion);
//			}
//		}
//
//	}
//
//}


void SortContact(Contact* pcon)
{
	assert(pcon);
	qsort(pcon - data, pcon->sz, size(addr), cmp_age);
	printf("����ɹ�\n");
}

