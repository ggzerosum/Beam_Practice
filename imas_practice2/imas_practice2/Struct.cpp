#include "essential.h"
#include "Sturct.h"

namespace My_NameSpace
{
	__PTR_REF::__PTR_REF(Base* ptr)
		:ptr(ptr), count(1)
	{
		//empty
	}

	__PTR_REF::~__PTR_REF()
	{
		delete ptr;
	}
}