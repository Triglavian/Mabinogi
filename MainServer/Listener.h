#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <queue>
#include "CommonHeader.h"

class Listener
{
public:
	Listener(const int& portNum = 9000);
	~Listener();
		
	const SOCKET& GetSocket();			//socket value returner

	//Validations
	bool IsValidSock();		//create and validate invalid socket creation error
	bool IsBindedSocket();	//validate unbinded socket error 
	bool IsOnListening();	//validate incommlete connection with client

	void CraeteListeningThread(std::thread& thread);

protected:
private:
	SOCKET lSocket;
	sockaddr_in serverAddr;
	sockaddr_in clientAddr;
	int cAddrSize;
	int result;
	std::shared_ptr<std::thread> thread;
	void Listening();	//keep listening until receive any client's connection

	std::shared_ptr<std::queue<SOCKET>> NewSockQueue;
	void AcceptClients();

	Listener(const Listener& listenSocket) = delete;	//don't use
};

