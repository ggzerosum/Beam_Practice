#include "essential.h"
#include "SmartPointer.h"

namespace My_NameSpace
{
	SmartPointer::SmartPointer(Base* ptr)
	{
		value = new PTR_REF(ptr);
	}


	SmartPointer::~SmartPointer()
	{
		//decrease count. delete if count is zero.
		if (--value->count == 0)
		{
			delete value;
		}
	}

	//copy consturctor
	SmartPointer::SmartPointer(const SmartPointer &ref)
		:value(ref.value)
	{
		++value->count;
	}

	//assignment operator
	SmartPointer& SmartPointer::operator=(const SmartPointer &ref)
	{
		//decrease previous ptr and delete if zero
		if (--value->count == 0)
		{
			delete value;
		}

		//assign ref's address
		value = ref.value;
		++value->count;

		return *this;
	}

	//asterisk operator
	Base& SmartPointer::operator*()
	{
		return *(value->ptr);
	}

	//arrow operator
	Base* SmartPointer::operator->()
	{
		return value->ptr;
	}


	//virtual methods
	void SmartPointer::Use()
	{

	}

	void SmartPointer::PrintInfo() const
	{

	}
}