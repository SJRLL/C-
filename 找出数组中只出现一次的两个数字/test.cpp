#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[20] = { 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//���浥������Ԫ�ص������
	int ret = 0;
	//����������г���1��λ��
	int pos;
	//���浥����Ԫ�ص�λ��
	int x = 0;
	int y = 0;
	int i;
	//������Ԫ�صĵ������
	for (i = 0; i < len; i++)
	{
		ret ^= arr[i];
	}
	//Ѱ��������г���1��λ��
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			//�������1��λ��
			pos = i;
			break;
		}
	}
	//����posλ���Ƿ�Ϊ1��������ֳ�����������
	//�������������п϶���һ��Ԫ��ֻ����һ��
	for (i = 0; i < len; i++)
	{
		//�ж�posλ�Ƿ�Ϊ��
		if (((arr[i] >> pos) & 1) == 1)
		{
			//posλΪ1��������Ԫ��
			x ^= arr[i];
		}
		else
		{
			//posΪ0��������Ԫ��
			y ^= arr[i];
		}
	}
	printf("%d,%d\n", x, y);
	system("pause");
	return 0;
}
