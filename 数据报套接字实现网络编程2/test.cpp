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
//	//��ʼ��WinSock
//	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//	if (iResult != 0) {
//		printf("WSAStartup failed with error: %d\n", iResult);
//		return 1;
//	}
//	ZeroMemory(&hints, sizeof(hints));
//	//����IPV4��ַ�壬��ʽ�׽��֣�UDPЭ��
//	hints.ai_family = AF_INET;
//	hints.ai_socktype = SOCK_DGRAM;
//	hints.ai_protocol = IPPROTO_UDP;
//	hints.ai_flags = AI_PASSIVE;
//
//
//	//������������ַ�Ͷ˿ں�
//	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
//	if (iResult != 0) {
//		printf("getaddrinfo failed with error: %d\n", iResult);
//		WSACleanup();
//		return 1;
//	}
//
//	//Ϊ�����ӵķ����������׽���
//	ServerSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
//	if (ServerSocket == INVALID_SOCKET) {
//		printf("socket failed with error: %ld\n", WSAGetLastError());
//		freeaddrinfo(result);
//		WSACleanup();
//		return 1;
//	}
//
//	//Ϊ�����׽��ְ󶨱��ص�ַ�Ͷ˿ں� 
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
//	//recvfrom����ֱ���ڲ�����ָ���������ݵ�Դ��ַ
//	iResult = recvfrom(ServerSocket, recvbuf, recvbuflen, 0, (SOCKADDR*)&clientaddr, &clientlen);
//	if (iResult > 0) {
//		//���1���ɹ����յ�����
//		printf("Bytes received: %d\n", iResult);
//		//�������������ݻ��͸��ͻ���
//		//sendto����Ҳ��ͬ���ڲ�����ָ������Ҫ���͵���Ŀ�ĵ�ַ
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
//		//���2���ر�����
//		printf("Connection closing...\n");
//	else {
//		//���3�����շ�������
//		printf("recv failed with error: %d\n", WSAGetLastError());
//		closesocket(ServerSocket);
//		WSACleanup();
//		return 1;
//	}
//	//�ر��׽���
//	closesocket(ServerSocket);
//	//�ͷ���Դ
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
	//��ʼ��WinSock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}
	ZeroMemory(&hints, sizeof(hints));
	//����IPV4��ַ�壬��ʽ�׽��֣�UDPЭ��
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;
	hints.ai_flags = AI_PASSIVE;


	//������������ַ�Ͷ˿ں�
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	//Ϊ�����ӵķ����������׽���
	ServerSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ServerSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	//Ϊ�����׽��ְ󶨱��ص�ַ�Ͷ˿ں� 
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

	//recvfrom����ֱ���ڲ�����ָ���������ݵ�Դ��ַ
	iResult = recvfrom(ServerSocket, recvbuf, recvbuflen, 0, (SOCKADDR*)&clientaddr, &clientlen);
	if (iResult > 0) {
		//���1���ɹ����յ�����
		printf("Bytes received: %d\n", iResult);
		//�������������ݻ��͸��ͻ���
		//sendto����Ҳ��ͬ���ڲ�����ָ������Ҫ���͵���Ŀ�ĵ�ַ
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
		//���2���ر�����
		printf("Connection closing...\n");
	else {
		//���3�����շ�������
		printf("recv failed with error: %d\n", WSAGetLastError());
		closesocket(ServerSocket);
		WSACleanup();
		return 1;
	}
	//�ر��׽���
	closesocket(ServerSocket);
	//�ͷ���Դ
	WSACleanup();
	system("pause");
	return 0;
}


