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
	Contact con;//ͨѶ¼
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��:>");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
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
