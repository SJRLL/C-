//#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <winsock2.h>
using namespace std;
#pragma comment (lib, "ws2_32.lib")  //加载 ws2_32.dll

#define BUF_SIZE 1024
void udp_delay_detect_server(int port)		//指定端口
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//创建套接字
	SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
	//绑定套接字
	sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(servAddr));  //每个字节都用0填充
	servAddr.sin_family = PF_INET;  //使用IPv4地址
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY); //自动获取IP地址
	servAddr.sin_port = htons(port);  //端口
	bind(sock, (SOCKADDR*)&servAddr, sizeof(SOCKADDR));
	//接收客户端请求
	SOCKADDR clntAddr;  //客户端地址信息
	int nSize = sizeof(SOCKADDR);
	
	char buffer[BUF_SIZE];  //缓冲区

	recvfrom(sock, buffer, BUF_SIZE, 0, &clntAddr, &nSize);			//接受发送端的开始发送的信号

	int recv_count = 0;
	//设置超时等待
	int timeout = 2000; //2s
	int ret = setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));

	int recv_miss_count = 0;
	while (1){
		int strLen = recvfrom(sock, buffer, BUF_SIZE, 0, &clntAddr, &nSize);
		if (strLen>1)              //验证接受字符串的长度
		{
			sendto(sock, buffer, strLen, 0, &clntAddr, nSize);
			recv_count++;
		}
		else{
			recv_miss_count++;
			cout << "no packet recieve!" << endl;
			if (recv_miss_count == 3)				//超过三次超时等待则认为接收完毕
				break;
		}
	}
	cout << "packet_recv_count:" << recv_count << endl;
	closesocket(sock);
}
