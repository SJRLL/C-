#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N sizeof(struct stu)

void clearscreen()  /*��������*/
{
	getchar();
	system("cls");
}

struct date   /*������������յĽṹ��*/
{
	int year;
	int mouth;
	int day;
};
struct stu     /*����ѧ����Ϣ�Ľṹ��*/
{
	int number;
	char name[30];
	char sex[5];
	struct date birthday;
	char mail[30];
	char phone[30];
	int structure, company;
	struct stu *next;
};



/*�������*/
int print(struct stu *p)
{
	while (p != NULL)    /*���P��ָ�Ľ�㲻Ϊ�� ִ��ѭ��*/
	{
		printf("ѧ��  ����  �Ա�    ��������    E-mail        �绰    ���ݽṹ  ��ҵ��˾\n");
		printf(" %2d%6s%6s%8d-%2d-%2d%11s%11s%6d%8d\n", p->number, p->name, p->sex, p->birthday.year, p->birthday.mouth, p->birthday.day, p->mail, p->phone, p->structure, p->company
			);
		p = p->next;
	}
	printf("\n\n���س�������\n\n");
	getchar();
	return 0;
}

/*��������*/
struct stu *creat()
{
	struct stu *p, *head;
	int i, k;
	printf("������ѧ��������\n");
	scanf("%d", &k);
	p = head = (struct stu *)malloc(N);
	printf("������ѧ��\n");
	scanf("%d", &p->number);
	printf("����\n");
	scanf("%s", &p->name);
	printf("�Ա�\n");
	scanf("%s", &p->sex);
	printf("��������\n");
	scanf("%d-%d-%d", &p->birthday.year, &p->birthday.mouth, &p->birthday.day);
	printf("E-mail\n");
	scanf("%s", &p->mail);
	printf("�绰\n");
	scanf("%s", &p->phone);
	printf("���ݽṹ\n");
	scanf("%d", &p->structure);
	printf("��ҵ��˾\n");
	scanf("%d", &p->company);
	if (k>1)
	for (i = 1; i<k; i++)
	{
		p->next = (struct stu *)malloc(N);
		p = p->next;
		printf("������ѧ��	\n");
		scanf("%d", &p->number);
		printf("����\n");
		scanf("%s", &p->name);
		printf("�Ա�\n");
		scanf("%s", &p->sex);
		printf("��������\n");
		scanf("%d-%d-%d", &p->birthday.year, &p->birthday.mouth, &p->birthday.day);
		printf("E-mail\n");
		scanf("%s", &p->mail);
		printf("�绰\n");
		scanf("%s", &p->phone);
		printf("���ݽṹ\n");
		scanf("%d", &p->structure);
		printf("��ҵ��˾\n");
		scanf("%d", &p->company);
	}
	p->next = NULL;

	return head;
}


/*��������*/
struct stu *find1(struct stu *p)
{
	int number;
	if (p == NULL)
	{
		printf("\n��ʾ:û�����Ͽ��Բ�ѯ!\n");
		return  0;
	}
	printf("������Ҫ���ҵ�ѧ��ѧ��:");
	scanf("%d", &number);
	while (p != NULL)
	{
		if (p->number == number)
		{
			return(p);
			break;
		}
		else
			p = p->next;
	}
	return NULL;
}

struct stu *find2(struct stu *p)
{
	char name[30];
	if (p == NULL)
	{
		printf("\n��ʾ:û�����Ͽ��Բ�ѯ!\n");
		return  0;
	}
	printf("������Ҫ���ҵ�ѧ������:");
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(p->name, name) == 0)
			return(p);
		else
			p = p->next;
	}

	return NULL;
}


/*ɾ������*/
int  del(struct stu **h)
{
	int number;
	struct stu *p, *p0;
	if (*h == NULL)
		return 0;
	printf("������Ҫɾ����ѧ��\n");
	scanf("%d", &number);
	p0 = *h;
	if (p0->number == number)
	{
		*h = p0->next;
		free(p0);
		return 1;
	}
	p = p0->next;
	while (p != NULL)
	{
		if (p->number == number)
		{
			p0->next = p->next;
			free(p);
			return 1;

		}
		p0 = p;
		p = p->next;
	}
	printf("\n���س�������\n");
	getchar();
	return 0;
}

/*��������*/
int insert(struct stu **h)
{
	struct stu *p, *p0;
	p = (struct stu *)malloc(N);
	printf("������Ҫ�����ѧ��\n");
	scanf("%ld", &p->number);
	p0 = *h;
	if (p0->number == p->number)
		return 0;
	printf("����\n");
	scanf("%s", &p->name);
	printf("�Ա�\n");
	scanf("%s", &p->sex);
	printf("��������\n");
	scanf("%d%d%d", &p->birthday.year, &p->birthday.mouth, &p->birthday.day);
	printf("E-mail\n");
	scanf("%s", &p->mail);
	printf("�绰\n");
	scanf("%s", &p->phone);
	printf("���ݽṹ\n");
	scanf("%d", &p->structure);
	printf("��ҵ��˾\n");
	scanf("%d", &p->company);
	p->next = NULL;
	if (*h == NULL)
	{
		*h = p;
		return 1;
	}
	p0 = *h;
	if (p0->number>p->number)
	{
		p->next = *h;
		*h = p;
		return 1;
	}
	while (p0->next != NULL&&p0->next->number<p->number)
		p0 = p0->next;
	if (p0->next == NULL)
	{
		p0->next = p;
		return 1;
	}

	p->next = p0->next;
	p0->next = p;
	printf("\n\n���س�������\n\n");
	getchar();
	return 1;
}


/*����*/
struct stu* sort(struct stu *p0)
{
	struct stu *t, *p, *q, *z;
	if (p0 == NULL)
	{
		printf("û��ѧ����Ϣ������!\n");
		return 0;
	}

	if ((p0 == NULL) || (p0->next == NULL))/*���ڵ㲻���ڻ���ֻ��һ���ڵ�ʱ*/
	{
		return p0;
	}
	t = p0;
	p = t->next;
	t->next = NULL;		/*��ͷ�ڵ��������*/
	while (p)		/*tʼ��ָ��ͷ�ڵ�*/
	{
		q = p->next;
		if (p->structure>t->structure)		/*��ͷ�ڵ�ĺ�һ���ڵ���ͷ�ڵ���бȽ�*/
		{
			p->next = t;		/*��������ķ���ǰ��*/
			t = p;			/*tʼ��ָ��ǰ��һ���ڵ�*/
		}
		else
		{
			z = t;
			while (z->next&&z->next->structure >= p->structure)
				z = z->next;
			p->next = z->next;
			z->next = p;
		}

		p = q;
	}
	p0 = t;
	return p0;

}

void main()
{
	struct stu *head=NULL;
	struct stu *p=NULL;
	int a;
	int b;
	printf("*****************************�����ƾ���ѧ��ҵ����ҵ����ϵͳ***************************\n");
	printf("Ҫ����ϵͳ�밴�����\n");
	getchar();
	printf("*****************************��ӭ�������ѽ������ϵͳ***************************\n");
	printf("*********************************��ҵ����ҵ����ϵͳ����ϵͳ*******************************\n");
	do
	{
		clearscreen();
		printf("ѧ����¼����:\n");
		printf("1:�����ҵѧ����ҵ��Ϣ\n");
		printf("2:���ұ�ҵѧ����ҵ��Ϣ\n");
		printf("3:ɾ����ҵѧ����ҵ��Ϣ\n");
		printf("4:�����ҵѧ����ҵ��Ϣ\n");
		printf("5:��ʾ��ҵѧ����ҵ��Ϣ\n");
		printf("6:�����ݽṹ�ɼ�����\n");
		printf("0:�˳�ϵͳ\n");
		printf("��ѡ��(0~6)��");
		scanf("%d", &b);
		switch (b)
		{
		case 1:head = creat();
			print(head);
			break;
		case 2:printf("������Ҫ���ҵ����ࣺ��Ϊѧ������1����Ϊ��������2��\n");
			scanf("%d", &a);
			switch (a)
			{
			case 1:p = find1(head); break;
			case 2:p = find2(head); break;
			}
			if (p)
			{
				printf("�ҵ�������£�\n");
				getchar();
				printf("ѧ��:%d ����:%s �Ա�:%s ��������:%d-%d-%d E-mail:%s    �绰:%s ���ݽṹ:%d ��ҵ��˾:%d\n", p->number, p->name, p->sex, p->birthday.year, p->birthday.mouth, p->birthday.day, p->mail, p->phone, p->structure, p->company);
			}
			else
				printf("û���ҵ���\n");
			getchar();
			break;
		case 3:if (del(&head))
			printf("����ȷɾ����\n");
			   else
				   printf("Ҫɾ���Ľ�㲻���ڣ�\n");
			getchar();
			break;
		case 4:if (insert(&head))
			printf("�ѳɹ����룡\n");
			   else
				   printf("��ѧ���Ѵ��ڣ�����ʧ�ܣ�\n");
			getchar();
			break;
		case 5:print(head);
			break;
		case 6:p = sort(head);
			print(p);
			break;
		case 0:break;
		default: printf(" ����������������룡\n");
		}
	} while (b != 0);
}