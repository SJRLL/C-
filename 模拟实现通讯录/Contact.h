#ifndef __CONTACT_H__
#define __CONTACT_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<errno.h>
#include<string.h>

enum Option
{
	EXIT,//退出程序
	ADD,//增添联系人
	DEL,//删除联系人
	SEARCH,//查找联系人
	MODIFY,//修改联系人信息
	SHOW,//展示联系人
	EMPTY,//清空通讯录
	SORT,//按名字排序通讯录
};

#define MAX 1000

#define MAX_NAME 20
#define SEX_MAX 5
#define NATION_MAX 10
#define TALE_MAX 12
#define ADDR_MAX 30
#define REALTION_MAX 20



typedef struct Peolnfo
{
	char name[MAX_NAME];
	char sex[SEX_MAX];
	short int  age;
	char nation[NATION_MAX];
	char tale[TALE_MAX];
	char addr[ADDR_MAX];
	char realtion[REALTION_MAX];
}Peolnfo;


typedef struct Contact
{
	Peolnfo data[MAX];//存放数据
	int sz;//通讯录的有效信息个数
}Contact;


void InitContact(Contact* pcon);//初始化通讯录
void AddContact(Contact* pcon);//增加通讯录信息
void ShowContact(const Contact* pcon);//展示通讯录信息
void DelContact(Contact* pcon);//删除通讯录信息
void SearchContact(Contact* pcon);//查找通讯录个人信息
void EmptyContact(Contact* pcon); //清空通讯录
void SortContact(Contact* pcon);//按名字排序通讯录



#endif //__CONTACT_H__