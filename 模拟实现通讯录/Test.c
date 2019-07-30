#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
void menu()
{
	printf("***************************************************\n");
	printf("****************1.add          2.del     **********\n");
	printf("****************3.search       4.modify  **********\n");
	printf("****************5.show         6.empty   **********\n");
	printf("****************7.sort         0.exit    **********\n");
	printf("***************************************************\n");

}
void test()
{
	int input = 0;
	Contact con;//通讯录
	InitContact(&con);

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case EMPTY:
			EmptyContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case MODIFY:
			break;
		case DEL:
			DelContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}
