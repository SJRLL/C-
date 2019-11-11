#define _CRT_SECURE_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS

// ConsoleApplication9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ConsoleApplication9.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

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

	//将输入参数转换为连接套接字
	SOCKET s = *((SOCKET *)pParam);
	do {
		memset(recvbuf, 0, BUFFER_LEN);
		//接收数据
		iResult = recv(s, recvbuf, BUFFER_LEN, 0);
		if (iResult > 0){
			printf("服务器端接收到数据%s\n", recvbuf);

			//向客户端发送数据
			memset(sendbuf, 0, BUFFER_LEN);
			strcat_s(sendbuf, "Back from server!");
			iResult = send(s, sendbuf, BUFFER_LEN, 0);
			if (iResult == SOCKET_ERROR)
			{
				printf("send 函数调用错误，错误号: %ld\n", WSAGetLastError());
				err = closesocket(s);
				if (err == SOCKET_ERROR){
					printf("closesocket 函数调用错误，错误号：%d\n", WSAGetLastError());
				}
				iResult = -1;
			}
			else
				printf("服务器端发送数据%s\n", sendbuf);
		}
		else{
			if (iResult == 0)
				printf("对方连接关闭，退出\n");
			else{
				printf("recv 函数调用错误，错误号: %d\n", WSAGetLastError());
				iResult = -1;
			}
			err = closesocket(s);
			if (err == SOCKET_ERROR){
				printf("closesocket 函数调用错误，错误号：%d\n", WSAGetLastError());
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
		// 初始化 MFC 并在失败时显示错误
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: 更改错误代码以符合您的需要
			_tprintf(_T("错误: MFC 初始化失败\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: 在此处为应用程序的行为编写代码。
		}
	}
	else
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: GetModuleHandle 失败\n"));
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
	printf("服务器准备好同时为多个客户端提供服务。。。\n");
	HANDLE pThread[20];
	listen(ListenSocket, 20);
	//开始
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
		//建立连接成功
		printf("\r\n与来自%s的客户端成功建立连接\n\n", peeraddr);
		//启动回射线程
		pThread[i] = AfxBeginThread(duoxiancheng_server_fun, &ConnectSocket);
	}
	closesocket(ListenSocket);
	printf("线程全部执行完毕\n");
	system("pause");
	//终止 DLL 的使用  
	WSACleanup();
	return nRetCode;
}
