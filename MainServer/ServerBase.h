#pragma once
#include "CommonHeader.h"
#include <map>
#include <WinSock2.h>

class ServerBase
{	
public:
	ServerBase();
	~ServerBase();
	void Run();
private:
	WSADATA wsa;
	std::shared_ptr<class Listener> ClientListener;
	std::unique_ptr<std::map<std::string, std::thread>> threads;	//Thread names and handles
	std::shared_ptr<Listener> ChannelListener;
	int result;
	
	void SetClientListeningThread();
};

