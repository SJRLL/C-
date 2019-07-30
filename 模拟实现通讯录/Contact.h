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
	EXIT,//�˳�����
	ADD,//������ϵ��
	DEL,//ɾ����ϵ��
	SEARCH,//������ϵ��
	MODIFY,//�޸���ϵ����Ϣ
	SHOW,//չʾ��ϵ��
	EMPTY,//���ͨѶ¼
	SORT,//����������ͨѶ¼
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
	Peolnfo data[MAX];//�������
	int sz;//ͨѶ¼����Ч��Ϣ����
}Contact;


void InitContact(Contact* pcon);//��ʼ��ͨѶ¼
void AddContact(Contact* pcon);//����ͨѶ¼��Ϣ
void ShowContact(const Contact* pcon);//չʾͨѶ¼��Ϣ
void DelContact(Contact* pcon);//ɾ��ͨѶ¼��Ϣ
void SearchContact(Contact* pcon);//����ͨѶ¼������Ϣ
void EmptyContact(Contact* pcon); //���ͨѶ¼
void SortContact(Contact* pcon);//����������ͨѶ¼



#endif //__CONTACT_H__