#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


#define EASY_COUNT 80//定义一共十个地雷

#define ROW 9//定义界面长度等于9
#define COL 9//定义界面宽度等于9

#define ROWS ROW+2//找雷时若界面不够，虚拟定义
#define COLS COL+2//找雷时若界面不够，虚拟定义

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char arr[ROWS][COLS], int row, int col);
void SetMine(char arr[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int GetMineCount(char mine[ROWS][COLS], int x, int y);

#endif