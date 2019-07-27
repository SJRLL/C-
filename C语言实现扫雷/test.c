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
	InitBoard(mine, ROWS, COLS, '0');//创建空界面‘0’
	InitBoard(show, ROWS, COLS, '*');//创建界面‘*’
	DisplayBoard(show, ROW, COL);//打印界面
	SetMine(mine, ROW, COL);//创建雷
	DisplayBoard(mine, ROW, COL);//打印雷
	FindMine(mine, show, ROW, COL);//找到雷
}

int main()
{
	int a = 0;
	srand((unsigned int)time(NULL));//生成随机数
	do
	{
		menu();//主界面函数
		printf("请选择:>");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (a);
	system("pause");
	return 0;
}