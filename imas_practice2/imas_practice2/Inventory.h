#pragma once
#include "Base.h"

namespace My_NameSpace
{
	class Inventory : public Base
	{
	public:
		Inventory();
		virtual ~Inventory();

		//virtual methods
		virtual void Use();
		virtual void PrintInfo() const;
	};
}