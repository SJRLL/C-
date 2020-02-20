#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>
using namespace std;

 void Swap(int* x1, int* x2)
{
	int tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}

void BubbleSort(int* nums, int n)//Ã°ÅÝÅÅÐò£¨ÉýÐò£©
{
	int end = n - 1;
	while (end >= 0)
	{
		int flag = 0;
		for (int i = 0; i < end; ++i)
		{

			if (nums[i]>nums[i + 1])
			{
				flag = 1;
				Swap(&nums[i], &nums[i + 1]);
			}
		}
		if (flag == 0)
		{
			break;
		}
		--end;
	}
}

int main()
{
	int nums[10] = {1,3,3,7,2,5,1,2,4,6};
	int n,k;
	cin >> n>>k;
	BubbleSort(nums, n);
	cout << nums[k] << endl;
	system("pause");
	return 0;
}
