#include "Listener.h"

Listener::Listener(const int& portNum)
{
	ZeroMemory(&serverAddr, sizeof(serverAddr));
	ZeroMemory(&clientAddr, sizeof(clientAddr));
	cAddrSize = 0;
	result = 0;

	int af = AF_INET;
	lSocket = socket(af, SOCK_STREAM, 0);
	serverAddr.sin_family = af;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(portNum);
	cAddrSize = sizeof(serverAddr);
}

Listener::~Listener()
{
	closesocket(lSocket);
}

const SOCKET& Listener::GetSocket() 
{
	return lSocket;
}

bool Listener::IsValidSock()
{
	return INVALID_SOCKET != lSocket;
}

bool Listener::IsBindedSocket()
{
	return SOCKET_ERROR != bind(lSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
}

bool Listener::IsOnListening()
{
	return SOCKET_ERROR != listen(lSocket, SOMAXCONN);
}

void Listener::Sequence(void*)
{

}

bool Listener::Listening()
{
	if (false == IsValidSock())
	{
		return false;
	}
	if (false == IsBindedSocket())
	{
		return false;
	}
	if (false == IsOnListening())
	{
		return false;
	}
	return true;
}
