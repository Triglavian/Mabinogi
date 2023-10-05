#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "CommonHeader.h"
#include "IMiddleware.h"

class Listener : public IMiddleware 
{
public:
	Listener(const int& portNum = 9000);
	~Listener();
		
	const SOCKET& GetSocket();			//socket value returner

	//Validations
	bool IsValidSock();		//create and validate invalid socket creation error
	bool IsBindedSocket();	//validate unbinded socket error 
	bool IsOnListening();	//validate incommlete connection with client
protected:
	virtual void Sequence(void*) override;
private:
	SOCKET lSocket;
	sockaddr_in serverAddr;
	sockaddr_in clientAddr;
	int cAddrSize;
	int result;
	bool Listening();	//keep listening until receive any client's connection
	Listener(const Listener& listenSocket) = delete;	//don't use
};

