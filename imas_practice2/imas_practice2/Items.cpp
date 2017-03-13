#include "essential.h"
#include "Items.h"

namespace My_NameSpace
{
	Items::Items(const char* name, int price)
		:price(price), id(this)
	{
		StrToDes(this->name, name);
	}


	Items::~Items()
	{
		delete[] name;
	}

	//Access functinos
	const char* Items::GetName() const
	{
		return name;
	}

	int Items::GetPrice() const
	{
		return price;
	}

	const void* Items::GetId() const
	{
		return id;
	}
}