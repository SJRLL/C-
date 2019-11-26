//#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
//#define WIN32_LEAN_AND_MEAN
//#include <windows.h>
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <stdlib.h>
//#include <stdio.h>
//
//#pragma comment (lib, "Ws2_32.lib")
//#pragma comment (lib, "Mswsock.lib")
//#pragma comment (lib, "AdvApi32.lib")
//
//#define DEFAULT_BUFLEN 512
//#define DEFAULT_PORT "27015"
//
//int __cdecl main(int argc, char **argv)
//{
//	WSADATA wsaData;
//	SOCKET ConnectLessSocket = INVALID_SOCKET;
//	struct addrinfo *result = NULL, *ptr = NULL, hints;
//	char *sendbuf = "this is a test";
//	char recvbuf[DEFAULT_BUFLEN];
//	int iResult;
//	int recvbuflen = DEFAULT_BUFLEN;
//	if (argc != 2) {
//		printf("usage: %s server-name\n", argv[0]);
//		return 1;
//	}
//
//	//初始化套接字
//	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//	if (iResult != 0) {
//		printf("WSAStartup failed with error: %d\n", iResult);
//		return 1;
//	}
//	ZeroMemory(&hints, sizeof(hints));
//	hints.ai_family = AF_UNSPEC;
//	hints.ai_socktype = SOCK_DGRAM;
//	hints.ai_protocol = IPPROTO_UDP;
//
//	//解析服务器地址和端口号
//	iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
//	if (iResult != 0) {
//		printf("getaddrinfo failed with error: %d\n", iResult);
//		WSACleanup();
//		return 1;
//	}
//	//创建数据报套接字
//	ConnectLessSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
//	if (ConnectLessSocket == INVALID_SOCKET) {
//		printf("scoket failed with error: %ld\n", WSAGetLastError());
//		WSACleanup();
//		return 1;
//	}
//
//	//发送缓冲区中的测试数据
//	iResult = sendto(ConnectLessSocket, sendbuf, (int)strlen(sendbuf), 0, result->ai_addr, (int)result->ai_addrlen);
//	if (iResult == SOCKET_ERROR) {
//		printf("send failed with error: %d\n", WSAGetLastError());
//		closesocket(ConnectLessSocket);
//		WSACleanup();
//		return 1;
//	}
//	freeaddrinfo(result);
//	printf("Bytes Sent: %ld\n", iResult);
//
//	//接收数据 
//	iResult = recvfrom(ConnectLessSocket, recvbuf, recvbuflen, 0, NULL, NULL);
//	if (iResult > 0)
//		printf("Bytes received: %d\n", iResult);
//	else if (iResult == 0)
//		printf("Connection closed\n");
//	else
//		printf("recv failed with error: %d\n", WSAGetLastError());
//	//关闭套接字
//	closesocket(ConnectLessSocket);
//	//释放资源
//	WSACleanup();
//	system("pause");
//	return 0;
//}
//
//

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

int __cdecl main(int argc, char **argv)
{
	WSADATA wsaData;
	SOCKET ConnectLessSocket = INVALID_SOCKET;
	struct addrinfo *result = NULL, *ptr = NULL, hints;
	char *sendbuf = "this is a test";
	char recvbuf[DEFAULT_BUFLEN];
	int iResult;
	int recvbuflen = DEFAULT_BUFLEN;
	if (argc != 2) {
		printf("usage: %s server-name\n", argv[0]);
		return 1;
	}

	//初始化套接字
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;

	//解析服务器地址和端口号
	iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}
	//创建数据报套接字
	ConnectLessSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ConnectLessSocket == INVALID_SOCKET) {
		printf("scoket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	//发送缓冲区中的测试数据
	iResult = sendto(ConnectLessSocket, sendbuf, (int)strlen(sendbuf), 0, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectLessSocket);
		WSACleanup();
		return 1;
	}
	freeaddrinfo(result);
	printf("Bytes Sent: %ld\n", iResult);

	//接收数据 
	iResult = recvfrom(ConnectLessSocket, recvbuf, recvbuflen, 0, NULL, NULL);
	if (iResult > 0)
		printf("Bytes received: %d\n", iResult);
	else if (iResult == 0)
		printf("Connection closed\n");
	else
		printf("recv failed with error: %d\n", WSAGetLastError());
	//关闭套接字
	closesocket(ConnectLessSocket);
	//释放资源
	WSACleanup();
	system("pause");
	return 0;
}
