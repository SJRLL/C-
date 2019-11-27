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
//	int iResult;
//	SOCKET ServerSocket = INVALID_SOCKET;
//	struct addrinfo *result = NULL;
//	struct addrinfo hints;
//	sockaddr_in clientaddr;
//	int clientlen = sizeof(clientaddr);
//	int iSendResult;
//	char recvbuf[DEFAULT_BUFLEN];
//	int recvbuflen = DEFAULT_BUFLEN;
//	//初始化WinSock
//	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//	if (iResult != 0) {
//		printf("WSAStartup failed with error: %d\n", iResult);
//		return 1;
//	}
//	ZeroMemory(&hints, sizeof(hints));
//	//声明IPV4地址族，流式套接字，UDP协议
//	hints.ai_family = AF_INET;
//	hints.ai_socktype = SOCK_DGRAM;
//	hints.ai_protocol = IPPROTO_UDP;
//	hints.ai_flags = AI_PASSIVE;
//
//
//	//解析服务器地址和端口号
//	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
//	if (iResult != 0) {
//		printf("getaddrinfo failed with error: %d\n", iResult);
//		WSACleanup();
//		return 1;
//	}
//
//	//为无连接的服务器创建套接字
//	ServerSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
//	if (ServerSocket == INVALID_SOCKET) {
//		printf("socket failed with error: %ld\n", WSAGetLastError());
//		freeaddrinfo(result);
//		WSACleanup();
//		return 1;
//	}
//
//	//为监听套接字绑定本地地址和端口号 
//	iResult = bind(ServerSocket, result->ai_addr, (int)result->ai_addrlen);
//	if (iResult == SOCKET_ERROR) {
//		printf("bind failed with error: %d\n", WSAGetLastError());
//		freeaddrinfo(result);
//		closesocket(ServerSocket);
//		WSACleanup();
//		return 1;
//	}
//	freeaddrinfo(result);
//
//	printf("UDP server starting\n");
//	ZeroMemory(&clientaddr, sizeof(clientaddr));
//
//	//recvfrom函数直接在参数中指定接收数据的源地址
//	iResult = recvfrom(ServerSocket, recvbuf, recvbuflen, 0, (SOCKADDR*)&clientaddr, &clientlen);
//	if (iResult > 0) {
//		//情况1：成功接收到数据
//		printf("Bytes received: %d\n", iResult);
//		//将缓冲区的内容回送给客户端
//		//sendto函数也是同理，在参数中指定数据要发送到的目的地址
//		iSendResult = sendto(ServerSocket, recvbuf, iResult, 0, (SOCKADDR*)&clientaddr, clientlen);
//		if (iSendResult == SOCKET_ERROR){
//			printf("send failed with error: %d\n", WSAGetLastError());
//			closesocket(ServerSocket);
//			WSACleanup();
//			return 1;
//		}
//		printf("Bytes sent: %d\n", iSendResult);
//	}
//	else if (iResult == 0)
//		//情况2：关闭连接
//		printf("Connection closing...\n");
//	else {
//		//情况3：接收发生错误
//		printf("recv failed with error: %d\n", WSAGetLastError());
//		closesocket(ServerSocket);
//		WSACleanup();
//		return 1;
//	}
//	//关闭套接字
//	closesocket(ServerSocket);
//	//释放资源
//	WSACleanup();
//	system("pause");
//	return 0;
//}
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
	int iResult;
	SOCKET ServerSocket = INVALID_SOCKET;
	struct addrinfo *result = NULL;
	struct addrinfo hints;
	sockaddr_in clientaddr;
	int clientlen = sizeof(clientaddr);
	int iSendResult;
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;
	//初始化WinSock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}
	ZeroMemory(&hints, sizeof(hints));
	//声明IPV4地址族，流式套接字，UDP协议
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;
	hints.ai_flags = AI_PASSIVE;


	//解析服务器地址和端口号
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	//为无连接的服务器创建套接字
	ServerSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ServerSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	//为监听套接字绑定本地地址和端口号 
	iResult = bind(ServerSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ServerSocket);
		WSACleanup();
		return 1;
	}
	freeaddrinfo(result);

	printf("UDP server starting\n");
	ZeroMemory(&clientaddr, sizeof(clientaddr));

	//recvfrom函数直接在参数中指定接收数据的源地址
	iResult = recvfrom(ServerSocket, recvbuf, recvbuflen, 0, (SOCKADDR*)&clientaddr, &clientlen);
	if (iResult > 0) {
		//情况1：成功接收到数据
		printf("Bytes received: %d\n", iResult);
		//将缓冲区的内容回送给客户端
		//sendto函数也是同理，在参数中指定数据要发送到的目的地址
		iSendResult = sendto(ServerSocket, recvbuf, iResult, 0, (SOCKADDR*)&clientaddr, clientlen);
		if (iSendResult == SOCKET_ERROR){
			printf("send failed with error: %d\n", WSAGetLastError());
			closesocket(ServerSocket);
			WSACleanup();
			return 1;
		}
		printf("Bytes sent: %d\n", iSendResult);
	}
	else if (iResult == 0)
		//情况2：关闭连接
		printf("Connection closing...\n");
	else {
		//情况3：接收发生错误
		printf("recv failed with error: %d\n", WSAGetLastError());
		closesocket(ServerSocket);
		WSACleanup();
		return 1;
	}
	//关闭套接字
	closesocket(ServerSocket);
	//释放资源
	WSACleanup();
	system("pause");
	return 0;
}


