#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <winsock.h>
#pragma comment(lib,"ws2_32.lib")

void main()
{
	WORD wversion;//��Ű汾
	WSADATA wsadata;//ָ�룬�������ִ����Ϣ
	int err;//������󣬱��

	SOCKET socksever;//�������׽���
	//��¼��������Ϣ
	SOCKADDR_IN  addrserver;
	//��¼�ͻ�����Ϣ
	SOCKADDR_IN  addrclienet;

	int length = 0;
	char sendstr[256] = { 0 };
	BOOL bflags = 1;//��ʾ
	wversion = MAKEWORD(2, 2);//�趨�汾
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

	socksever = socket(AF_INET, SOCK_DGRAM, 0);//����
	// SO_BROADCAST�ಥ����ָ���Ĳ���
	//flags�趨��1����㲥��0��ֹ�㲥
	setsockopt(socksever, SOL_SOCKET, SO_BROADCAST, (const char*)&bflags, sizeof((const char*)bflags));//��

	addrserver.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//��������
	addrserver.sin_family = AF_INET;
	addrserver.sin_port = htons(7888);//�˿�

	//��������Ϣ���׽��ְ�
	bind(socksever, (SOCKADDR*)&addrserver, sizeof(SOCKADDR));//��

	//��д�㲥��255.255.255.255,�㲥
	addrclienet.sin_addr.S_un.S_addr = inet_addr("255.255.255.255");
	addrclienet.sin_family = AF_INET;
	addrclienet.sin_port = htons(9999);//�˿�

	length = sizeof(SOCKADDR);//�����ַ����

	while (1)
	{
		memset(sendstr, 0, 256);
		scanf("%s", sendstr);//��ȡ��ȡ
		//������Ϣ���ͻ���(�㲥)
		sendto(socksever, sendstr, strlen(sendstr), 0, (SOCKADDR*)&addrclienet, length);
	}
	closesocket(socksever);
	WSACleanup();
	system("pause");
}
