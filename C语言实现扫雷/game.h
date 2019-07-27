#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


#define EASY_COUNT 80//����һ��ʮ������

#define ROW 9//������泤�ȵ���9
#define COL 9//��������ȵ���9

#define ROWS ROW+2//����ʱ�����治�������ⶨ��
#define COLS COL+2//����ʱ�����治�������ⶨ��

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char arr[ROWS][COLS], int row, int col);
void SetMine(char arr[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int GetMineCount(char mine[ROWS][COLS], int x, int y);

#endif