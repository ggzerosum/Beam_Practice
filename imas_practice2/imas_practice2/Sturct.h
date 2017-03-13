#pragma once

#include "Base.h"

namespace My_NameSpace
{
	//used in Smart Pointer
	typedef struct __PTR_REF
	{
		//Let's accept all pointers!
		Base* ptr;
		int count;
		
		__PTR_REF(Base* ptr);
		~__PTR_REF();
	}PTR_REF;
}