#include "ServerBase.h"
#include "Listener.h"

ServerBase::ServerBase()
{
	result = WSAStartup(MAKEWORD(2, 2), &wsa);
	_Listener = std::make_unique<Listener>();

}

ServerBase::~ServerBase()
{

}

void ServerBase::Run()
{
	
}
