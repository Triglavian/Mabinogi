#pragma once
#include <list>
#include "CommonHeader.h"
class MiddlewareList
{
public:
	void AddMiddleWare(std::shared_ptr<class IMiddleware>);
private:
	std::unique_ptr<std::list<std::shared_ptr<class IMiddleware>>> mwPipeline;
};

