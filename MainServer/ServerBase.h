#pragma once
#include "CommonHeader.h"
#include <WinSock2.h>

class ServerBase
{	
	WSADATA wsa;
	std::unique_ptr<class Listener> _Listener;
	int result;
	
public:
	ServerBase();
	~ServerBase();
	void Run();
};

