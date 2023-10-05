#include "MiddlewareList.h"
#include "IMiddleware.h"

bool MiddlewareList::AddMiddleWare(std::shared_ptr<IMiddleware> mw)
{
	mwList.get()->back().get()->SetNextSeq(std::bind(&IMiddleware::Sequence, mw.get(), std::placeholders::_1));
	return true;
}
