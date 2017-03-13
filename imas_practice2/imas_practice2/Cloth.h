#pragma once
#include "Items.h"

namespace My_NameSpace
{
	class Cloth : public Items
	{
	private:
		GRADES grade;
	public:
		Cloth(const char* name, int price, GRADES grade);
		~Cloth();

		//virtual methods
		virtual void Use();
		virtual void PrintInfo() const;
	};
}