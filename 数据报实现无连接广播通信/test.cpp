#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <winsock.h>
#pragma comment(lib,"ws2_32.lib")

void main()
{
	//��Ű汾
	WORD wversion;
	//ָ�룬�������ִ����Ϣ
	WSADATA wsadata;
	//������󣬱��
	int err;

	//�ͻ����׽���,��������
	SOCKET sockclient;
	//��������ַ
	SOCKADDR_IN  addrserver;
	//�ͻ��˵�ַ
	SOCKADDR_IN  addrclienet;

	//����
	int length = 0;
	//����
	char recvstr[256] = { 0 };
	//��ʾ
	const char bflags = 1;
	//�趨�汾
	wversion = MAKEWORD(2, 2);
	err = WSAStartup(wversion, &wsadata);
	if (err != 0)
	{
		printf("��ȡ�汾ʧ��");
		return;
	}

	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2)
	{
		printf("�汾�Ա�ʧ�ܣ���һ��");
		return;
	}
	//UDP���Ĵ���
	sockclient = socket(AF_INET, SOCK_DGRAM, 0);
	//setsockopt()�����������������͡�����״̬�׽ӿڵ�����ѡ��ֵ��
	//�����ڲ�ͬЭ����ϴ���ѡ�������������������ߵġ��׽ӿڡ�����ϵ�ѡ�
	//�ಥ����ָ���Ĳ���
	//flags�趨��1����㲥��0��ֹ�㲥
	setsockopt(sockclient, SOL_SOCKET, SO_REUSEADDR, &bflags, sizeof(bflags));

	//��ſͻ���ip��ַ
	addrclienet.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrclienet.sin_family = AF_INET;
	addrclienet.sin_port = htons(9999);//�˿�
	//�ͻ����׽�����ͻ�����Ϣ��
	bind(sockclient, (SOCKADDR*)&addrclienet, sizeof(SOCKADDR));
	//���ڵ�ַ����
	length = sizeof(SOCKADDR);
	while (1)
	{
		printf("wait-----------------\n");
		//�ӿͻ��˽�����Ϣ,��ַ��Ϣ�����addrserver��
		recvfrom(sockclient, recvstr, 256, 0, (SOCKADDR*)&addrserver, &length);
		if (WSAGetLastError() != 0)
		{
			puts("��ȡʧ��");
		}
		//�ĸ����������͵�
		printf("%s speak %s\n", inet_ntoa(addrserver.sin_addr), recvstr);
	}
	closesocket(sockclient);
	WSACleanup();
	system("pause");
}
