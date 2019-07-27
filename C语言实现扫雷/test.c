#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include "game.h"
void menu()
{
	printf("************************************\n");
	printf("*****           1. play         ****\n");
	printf("*****           0. exit         ****\n");
	printf("************************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//'0'
	char show[ROWS][COLS] = { 0 };//'*'
	InitBoard(mine, ROWS, COLS, '0');//�����ս��桮0��
	InitBoard(show, ROWS, COLS, '*');//�������桮*��
	DisplayBoard(show, ROW, COL);//��ӡ����
	SetMine(mine, ROW, COL);//������
	DisplayBoard(mine, ROW, COL);//��ӡ��
	FindMine(mine, show, ROW, COL);//�ҵ���
}

int main()
{
	int a = 0;
	srand((unsigned int)time(NULL));//���������
	do
	{
		menu();//�����溯��
		printf("��ѡ��:>");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (a);
	system("pause");
	return 0;
}