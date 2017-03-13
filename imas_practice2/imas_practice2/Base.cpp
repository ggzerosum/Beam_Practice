#include "essential.h"
#include "Base.h"

namespace My_NameSpace
{
	Base::Base()
	{
	}


	Base::~Base()
	{
	}

	void Base::StrToDes(char* &destination, const char* source)
	{
		size_t size = strlen(source) + 1;
		destination = new char[size];
		strcpy_s(destination, size, source);
	}
}