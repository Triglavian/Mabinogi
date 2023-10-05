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

	NewSockQueue = std::make_shared<std::queue<SOCKET>>();

	Listening();
}

Listener::~Listener()
{
	closesocket(lSocket);
	thread.get()->join();
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

void Listener::CraeteListeningThread(std::thread& thread)
{
	thread = std::thread(&Listener::AcceptClients, this);
}

void Listener::Listening()
{
	if (false == IsValidSock())
	{
		throw -1;
	}
	if (false == IsBindedSocket())
	{
		throw - 1;
	}
	if (false == IsOnListening())
	{
		throw - 1;
	}
}


/// <summary>
/// Some ways to fix code to escape accept loop
/// 
/// a) Use non-blocking
/// b) Use AcceptEx() to wait on an extra signal, (Windows)
/// c) Close the listening socket from another thread to make Accept() return with an error / exception.
/// d) Open a temporary local connection from another thread to make Accept() return with the temp connection
///
/// https://stackoverflow.com/questions/12565112/how-to-break-c-accept-function
/// </summary>
void Listener::AcceptClients()
{
	while (true)
	{
		SOCKET NewSock = accept(lSocket, (sockaddr*)&clientAddr, &cAddrSize);
		if (INVALID_SOCKET != NewSock)
		{
			NewSockQueue.get()->push(NewSock);
			continue;
		}
		//Invalid socket error logging
	}
}
