#pragma once
#include <list>
#include "CommonHeader.h"
class MiddlewareList
{
public:
	bool AddMiddleWare(std::shared_ptr<class IMiddleware>);
private:
	std::unique_ptr<std::list<std::shared_ptr<class IMiddleware>>> mwList;
};

