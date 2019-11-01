#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[20] = { 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//保存单独出现元素的异或结果
	int ret = 0;
	//保存异或结果中出现1的位置
	int pos;
	//保存单独的元素的位置
	int x = 0;
	int y = 0;
	int i;
	//求所有元素的的异或结果
	for (i = 0; i < len; i++)
	{
		ret ^= arr[i];
	}
	//寻找异或结果中出现1的位置
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			//保存出现1的位置
			pos = i;
			break;
		}
	}
	//根据pos位置是否为1，把数组分成两个子数组
	//这两个子数组中肯定有一个元素只出现一次
	for (i = 0; i < len; i++)
	{
		//判断pos位是否为；
		if (((arr[i] >> pos) & 1) == 1)
		{
			//pos位为1的子数组元素
			x ^= arr[i];
		}
		else
		{
			//pos为0的子数组元素
			y ^= arr[i];
		}
	}
	printf("%d,%d\n", x, y);
	system("pause");
	return 0;
}
