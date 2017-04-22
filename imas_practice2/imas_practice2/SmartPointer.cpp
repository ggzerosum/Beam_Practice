#include "essential.h"
#include "SmartPointer.h"

namespace My_NameSpace
{
	//default constrructor
	SmartPointer::SmartPointer()
		:value(nullptr)
	{
		//empty
	}

	SmartPointer::SmartPointer(Base* ptr)
	{
		if (ptr == nullptr)
		{
			value = nullptr;
			return;
		}

		value = new PTR_REF(ptr);
	}


	SmartPointer::~SmartPointer()
	{
		if (value == nullptr)
			return;

		//decrease count. delete if count is zero.
		if (--value->count == 0)
		{
			delete value;
		}
	}


	//copy constructor. just increase count.
	SmartPointer::SmartPointer(const SmartPointer & ref)
		:value(ref.value)
	{
		if(value != nullptr)
			++value->count;
	}

	//assignment operator
	SmartPointer& SmartPointer::operator=(const SmartPointer &ref)
	{
		//decrease previous ptr and delete if zero
		if(value != nullptr)
			if (--value->count == 0)
				delete value;

		//assign ref's address
		value = ref.value;
		if(value != nullptr)
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
		//empty
	}

	void SmartPointer::PrintInfo() const
	{
		//empty
	}


	//(Items*) operator
	SmartPointer::operator Items*()
	{
		if (value == nullptr)
			return nullptr;

		return (Items*)(value->ptr);
	}

	////== operator
	//bool SmartPointer::operator==(const SmartPointer &ref)
	//{
	//	return (value == ref.value);
	//}

	////== operator
	//bool operator==(const SmartPointer &left, const SmartPointer &right)
	//{
	//	return (left.value == right.value);
	//}

	////!= operator
	//bool operator!=(const SmartPointer &left, const SmartPointer &right)
	//{
	//	return !(left.value == right.value);
	//}
}