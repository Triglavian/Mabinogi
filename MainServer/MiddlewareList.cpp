#include "MiddlewareList.h"
#include "IMiddleware.h"

void MiddlewareList::AddMiddleWare(std::shared_ptr<IMiddleware> mw)
{
	mwPipeline.get()->push_back(mw);
	mwPipeline.get()->back().get()->SetNextSeq(std::bind(&IMiddleware::Sequence, mw.get(), std::placeholders::_1));
	return;
}
