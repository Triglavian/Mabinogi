#include "ServerBase.h"
#include "CommonHeader.h"

int main(int argc, char* argv[])
{
	std::unique_ptr<ServerBase> inst = std::make_unique<ServerBase>();
	inst.get()->Run();
	return 0;
}