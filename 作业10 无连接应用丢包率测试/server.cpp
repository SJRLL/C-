//#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <winsock2.h>
using namespace std;
#pragma comment (lib, "ws2_32.lib")  //���� ws2_32.dll

#define BUF_SIZE 1024
void udp_delay_detect_server(int port)		//ָ���˿�
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//�����׽���
	SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
	//���׽���
	sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(servAddr));  //ÿ���ֽڶ���0���
	servAddr.sin_family = PF_INET;  //ʹ��IPv4��ַ
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY); //�Զ���ȡIP��ַ
	servAddr.sin_port = htons(port);  //�˿�
	bind(sock, (SOCKADDR*)&servAddr, sizeof(SOCKADDR));
	//���տͻ�������
	SOCKADDR clntAddr;  //�ͻ��˵�ַ��Ϣ
	int nSize = sizeof(SOCKADDR);
	
	char buffer[BUF_SIZE];  //������

	recvfrom(sock, buffer, BUF_SIZE, 0, &clntAddr, &nSize);			//���ܷ��Ͷ˵Ŀ�ʼ���͵��ź�

	int recv_count = 0;
	//���ó�ʱ�ȴ�
	int timeout = 2000; //2s
	int ret = setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));

	int recv_miss_count = 0;
	while (1){
		int strLen = recvfrom(sock, buffer, BUF_SIZE, 0, &clntAddr, &nSize);
		if (strLen>1)              //��֤�����ַ����ĳ���
		{
			sendto(sock, buffer, strLen, 0, &clntAddr, nSize);
			recv_count++;
		}
		else{
			recv_miss_count++;
			cout << "no packet recieve!" << endl;
			if (recv_miss_count == 3)				//�������γ�ʱ�ȴ�����Ϊ�������
				break;
		}
	}
	cout << "packet_recv_count:" << recv_count << endl;
	closesocket(sock);
}
