#include "IMiddleware.h"

void IMiddleware::SetNextSeq(std::function<void(void*)> func)
{
	next = func;
}
