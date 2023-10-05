#include "ServerBase.h"
#include "Listener.h"

ServerBase::ServerBase()
{
	result = WSAStartup(MAKEWORD(2, 2), &wsa);
	ClientListener = std::make_shared<Listener>();
	ChannelListener = std::make_shared<Listener>(9500);
	threads = std::make_unique<std::map<std::string, std::thread>>();
}

ServerBase::~ServerBase()
{

}

void ServerBase::Run()
{
	try
	{
	}
	catch (int i)
	{

	}
}

void ServerBase::SetClientListeningThread()
{
	std::thread thread;
	ClientListener.get()->CraeteListeningThread(thread);
	//std::map<std::string, std::thread> map;
	//map["Client listener"] = thread;
	//threads.get()->insert(std::pair<std::string, std::thread>("Client listener", thread));
}
