#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i;
	int c = 0;
	int max = 0;
	int min = 0;
	int a[10];
	scanf("%d", &a[0]);
	max = min = a[0];
	for (i = 1; i<10; i++)
	{
		scanf("%d", &a[i]);
		if (max<a[i])
		{
			max = a[i];
		}
		if (min>a[i])
		{
			min = a[i];
		}
	}
	printf("%d\n", c = max);
	printf("%d\n", min);
	system("pause");
	return 0;
}
