#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N sizeof(struct stu)

void clearscreen()  /*清屏函数*/
{
	getchar();
	system("cls");
}

struct date   /*定义出生年月日的结构体*/
{
	int year;
	int mouth;
	int day;
};
struct stu     /*定义学生信息的结构体*/
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



/*输出函数*/
int print(struct stu *p)
{
	while (p != NULL)    /*如果P所指的结点不为空 执行循环*/
	{
		printf("学号  姓名  性别    出生日期    E-mail        电话    数据结构  就业公司\n");
		printf(" %2d%6s%6s%8d-%2d-%2d%11s%11s%6d%8d\n", p->number, p->name, p->sex, p->birthday.year, p->birthday.mouth, p->birthday.day, p->mail, p->phone, p->structure, p->company
			);
		p = p->next;
	}
	printf("\n\n按回车键返回\n\n");
	getchar();
	return 0;
}

/*创建链表*/
struct stu *creat()
{
	struct stu *p, *head;
	int i, k;
	printf("请输入学生的数：\n");
	scanf("%d", &k);
	p = head = (struct stu *)malloc(N);
	printf("请输入学号\n");
	scanf("%d", &p->number);
	printf("姓名\n");
	scanf("%s", &p->name);
	printf("性别\n");
	scanf("%s", &p->sex);
	printf("出生日期\n");
	scanf("%d-%d-%d", &p->birthday.year, &p->birthday.mouth, &p->birthday.day);
	printf("E-mail\n");
	scanf("%s", &p->mail);
	printf("电话\n");
	scanf("%s", &p->phone);
	printf("数据结构\n");
	scanf("%d", &p->structure);
	printf("就业公司\n");
	scanf("%d", &p->company);
	if (k>1)
	for (i = 1; i<k; i++)
	{
		p->next = (struct stu *)malloc(N);
		p = p->next;
		printf("请输入学号	\n");
		scanf("%d", &p->number);
		printf("姓名\n");
		scanf("%s", &p->name);
		printf("性别\n");
		scanf("%s", &p->sex);
		printf("出生日期\n");
		scanf("%d-%d-%d", &p->birthday.year, &p->birthday.mouth, &p->birthday.day);
		printf("E-mail\n");
		scanf("%s", &p->mail);
		printf("电话\n");
		scanf("%s", &p->phone);
		printf("数据结构\n");
		scanf("%d", &p->structure);
		printf("就业公司\n");
		scanf("%d", &p->company);
	}
	p->next = NULL;

	return head;
}


/*查找链表*/
struct stu *find1(struct stu *p)
{
	int number;
	if (p == NULL)
	{
		printf("\n提示:没有资料可以查询!\n");
		return  0;
	}
	printf("请输入要查找的学生学号:");
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
		printf("\n提示:没有资料可以查询!\n");
		return  0;
	}
	printf("请输入要查找的学生姓名:");
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


/*删除链表*/
int  del(struct stu **h)
{
	int number;
	struct stu *p, *p0;
	if (*h == NULL)
		return 0;
	printf("请输入要删除的学号\n");
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
	printf("\n按回车键返回\n");
	getchar();
	return 0;
}

/*插入链表*/
int insert(struct stu **h)
{
	struct stu *p, *p0;
	p = (struct stu *)malloc(N);
	printf("请输入要插入的学号\n");
	scanf("%ld", &p->number);
	p0 = *h;
	if (p0->number == p->number)
		return 0;
	printf("姓名\n");
	scanf("%s", &p->name);
	printf("性别\n");
	scanf("%s", &p->sex);
	printf("出生日期\n");
	scanf("%d%d%d", &p->birthday.year, &p->birthday.mouth, &p->birthday.day);
	printf("E-mail\n");
	scanf("%s", &p->mail);
	printf("电话\n");
	scanf("%s", &p->phone);
	printf("数据结构\n");
	scanf("%d", &p->structure);
	printf("就业公司\n");
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
	printf("\n\n按回车键返回\n\n");
	getchar();
	return 1;
}


/*排序*/
struct stu* sort(struct stu *p0)
{
	struct stu *t, *p, *q, *z;
	if (p0 == NULL)
	{
		printf("没有学生信息可排序!\n");
		return 0;
	}

	if ((p0 == NULL) || (p0->next == NULL))/*当节点不存在或者只有一个节点时*/
	{
		return p0;
	}
	t = p0;
	p = t->next;
	t->next = NULL;		/*将头节点孤立出来*/
	while (p)		/*t始终指向头节点*/
	{
		q = p->next;
		if (p->structure>t->structure)		/*用头节点的后一个节点与头节点进行比较*/
		{
			p->next = t;		/*将分数大的放在前面*/
			t = p;			/*t始终指向当前第一个节点*/
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
	printf("*****************************西安财经大学毕业生就业管理系统***************************\n");
	printf("要进入系统请按任意键\n");
	getchar();
	printf("*****************************欢迎您！您已进入管理系统***************************\n");
	printf("*********************************毕业生就业管理系统管理系统*******************************\n");
	do
	{
		clearscreen();
		printf("学生纪录操作:\n");
		printf("1:输入毕业学生就业信息\n");
		printf("2:查找毕业学生就业信息\n");
		printf("3:删除毕业学生就业信息\n");
		printf("4:插入毕业学生就业信息\n");
		printf("5:显示毕业学生就业信息\n");
		printf("6:按数据结构成绩排序\n");
		printf("0:退出系统\n");
		printf("请选择(0~6)：");
		scanf("%d", &b);
		switch (b)
		{
		case 1:head = creat();
			print(head);
			break;
		case 2:printf("请输入要查找的种类：如为学号请输1，如为姓名请输2：\n");
			scanf("%d", &a);
			switch (a)
			{
			case 1:p = find1(head); break;
			case 2:p = find2(head); break;
			}
			if (p)
			{
				printf("找到情况如下：\n");
				getchar();
				printf("学号:%d 姓名:%s 性别:%s 出生日期:%d-%d-%d E-mail:%s    电话:%s 数据结构:%d 就业公司:%d\n", p->number, p->name, p->sex, p->birthday.year, p->birthday.mouth, p->birthday.day, p->mail, p->phone, p->structure, p->company);
			}
			else
				printf("没有找到！\n");
			getchar();
			break;
		case 3:if (del(&head))
			printf("已正确删除！\n");
			   else
				   printf("要删除的结点不存在！\n");
			getchar();
			break;
		case 4:if (insert(&head))
			printf("已成功插入！\n");
			   else
				   printf("此学生已存在，插入失败！\n");
			getchar();
			break;
		case 5:print(head);
			break;
		case 6:p = sort(head);
			print(p);
			break;
		case 0:break;
		default: printf(" 输入错误！请重新输入！\n");
		}
	} while (b != 0);
}