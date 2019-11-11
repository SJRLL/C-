#define _CRT_SECURE_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS

// ConsoleApplication9.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ConsoleApplication9.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;


#define SERVER_PORT "27015"
#define BUFFER_LEN 512


#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#pragma comment (lib,"ws2_32.lib")
using namespace std;

UINT duoxiancheng_server_fun(LPVOID pParam)
{
	int iSendResult = 0;
	char sendbuf[BUFFER_LEN];
	char recvbuf[BUFFER_LEN];
	int iResult = 0;
	int err = 0;

	//���������ת��Ϊ�����׽���
	SOCKET s = *((SOCKET *)pParam);
	do {
		memset(recvbuf, 0, BUFFER_LEN);
		//��������
		iResult = recv(s, recvbuf, BUFFER_LEN, 0);
		if (iResult > 0){
			printf("�������˽��յ�����%s\n", recvbuf);

			//��ͻ��˷�������
			memset(sendbuf, 0, BUFFER_LEN);
			strcat_s(sendbuf, "Back from server!");
			iResult = send(s, sendbuf, BUFFER_LEN, 0);
			if (iResult == SOCKET_ERROR)
			{
				printf("send �������ô��󣬴����: %ld\n", WSAGetLastError());
				err = closesocket(s);
				if (err == SOCKET_ERROR){
					printf("closesocket �������ô��󣬴���ţ�%d\n", WSAGetLastError());
				}
				iResult = -1;
			}
			else
				printf("�������˷�������%s\n", sendbuf);
		}
		else{
			if (iResult == 0)
				printf("�Է����ӹرգ��˳�\n");
			else{
				printf("recv �������ô��󣬴����: %d\n", WSAGetLastError());
				iResult = -1;
			}
			err = closesocket(s);
			if (err == SOCKET_ERROR){
				printf("closesocket �������ô��󣬴���ţ�%d\n", WSAGetLastError());
			}
			break;
		}
	} while (iResult > 0);

	return iResult;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{

	int nRetCode = 0;
	int iResult = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: ���Ĵ�������Է���������Ҫ
			_tprintf(_T("����: MFC ��ʼ��ʧ��\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: �ڴ˴�ΪӦ�ó������Ϊ��д���롣
		}
	}
	else
	{
		// TODO: ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����: GetModuleHandle ʧ��\n"));
		nRetCode = 1;
	}


	SOCKET ListenSocket, ConnectSocket;
	//CWinThread *pThread= NULL;
	WSADATA wsaData;
	struct addrinfo hints, *result = NULL;

	struct sockaddr_in clientaddr;


	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("WSAStartup failed with error %d\n", iResult);
		return 1;
	}

	ListenSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ListenSocket == INVALID_SOCKET)
	{
		printf("socket failed with error %ld\n", GetLastError());
		WSACleanup();
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;
	iResult = getaddrinfo(NULL, SERVER_PORT, &hints, &result);
	if (iResult != 0)
	{
		printf("getaddrinfo failed with error %d\n", iResult);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR)
	{
		printf("bind failed with error %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		freeaddrinfo(result);
		return 1;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR)
	{
		printf("listen failed with error %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	printf("������׼����ͬʱΪ����ͻ����ṩ���񡣡���\n");
	HANDLE pThread[20];
	listen(ListenSocket, 20);
	//��ʼ
	for (int i = 0; i<20; i++)
	{
		int addrlenth = sizeof(clientaddr);
		ConnectSocket = accept(ListenSocket, (sockaddr*)&clientaddr, &addrlenth);
		if (ConnectSocket == INVALID_SOCKET){
			printf("accept failed with error %d\n", WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();
			return -1;
		}
		char *peeraddr = inet_ntoa(clientaddr.sin_addr);
		//�������ӳɹ�
		printf("\r\n������%s�Ŀͻ��˳ɹ���������\n\n", peeraddr);
		//���������߳�
		pThread[i] = AfxBeginThread(duoxiancheng_server_fun, &ConnectSocket);
	}
	closesocket(ListenSocket);
	printf("�߳�ȫ��ִ�����\n");
	system("pause");
	//��ֹ DLL ��ʹ��  
	WSACleanup();
	return nRetCode;
}
