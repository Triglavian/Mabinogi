#pragma once
#include <functional>

class IMiddleware
{
public:
	//Called by next sequence middleware and set next middleware callback
	virtual void SetNextSeq(std::function<void(void*)> func);
protected:
	virtual void Sequence(void*) = 0;
	std::function<void(void*)> next = nullptr;
	friend class MiddlewareList;
	/*
public:
	template <typename T, typename...Type>
	void SetNextSeq(T func, Type...etc) = 0;
protected:
	template <typename T, typename...Type>
	std::function<void(T arg1, Type...arg2)> Next;
	*/
};

