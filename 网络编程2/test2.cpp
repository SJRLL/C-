#define _CRT_SECURE_NO_WARNINGS 1

// ShuruxinxClient.cpp : 客户端程序，用户可以从键盘输入信息并发送给服务器。
//

#include<iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#include<string.h>
#pragma comment (lib,"ws2_32.lib")
#pragma warning(disable :4996)
#define SERVER_PORT "8888"
#define BUFFER_LEN  512
using namespace std;

#define SERVER_PORT "8888"
#define BUFFER_LEN 512

int main(int argc, char * argv[])
{
	struct addrinfo* result = NULL, *ptr = NULL, hints;
	WSADATA wsaData;
	SOCKET ConnectSocket;
	char sendbuf[BUFFER_LEN];
	char recvbuf[BUFFER_LEN];
	int iResult;

	if (argc != 1) {
		printf("Usage: %s server ip address\n", argv[0]);
		return 1;
	}

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	iResult = getaddrinfo(NULL, SERVER_PORT, &hints, &result);//将输入参数argv[1]中指定的服务器信息写入result
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	ConnectSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);//使用result指定的信息创建套接字
	if (ConnectSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	iResult = connect(ConnectSocket, result->ai_addr, result->ai_addrlen);//使用套接字ConnectSocket向result中指定的服务器请求连接
	if (iResult == SOCKET_ERROR) {
		printf("connect failed with error: %ld\n", iResult);
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}
	freeaddrinfo(result);//释放动态分配的地址信息结构体result

	while (gets_s(sendbuf) != NULL) {//从键盘获取输入字符串  
		if (*sendbuf == 'Q') {
			closesocket(ConnectSocket);
			return 0;
		}
		iResult = send(ConnectSocket, sendbuf, strlen(sendbuf), 0);
		if (iResult == SOCKET_ERROR) {
			printf("send failed with error: %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			return 1;
		}
		do {
			memset(recvbuf, 0, BUFFER_LEN * sizeof(char));
			iResult = recv(ConnectSocket, recvbuf, strlen(recvbuf), 0);
			if (iResult > 0)
			{
				printf("Received message from client: %d\n", iResult);
			}
			else if (iResult == 0)
			{
				printf("请继续输入要发送数据：");
			}
			else {
				printf("recv failed with error:%d\n", WSAGetLastError());
			}
		} while (iResult > 0);
	}

	closesocket(ConnectSocket);
	WSACleanup();
	return 0;
}
