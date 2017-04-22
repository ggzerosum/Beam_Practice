#pragma once
#include "Base.h"
#include "Items.h"
#include "SmartPointer.h"

namespace My_NameSpace
{
	class Inventory : public Base
	{
	private:
		SmartPointer* slots;
		int size;

	public:
		Inventory(int sizeOfSlots);
		virtual ~Inventory();

		void Add(Items* item); //add items to inventory
		int Search(const char* target) const; //search items in inventory
		SmartPointer& ReturnPTR(int idx) const;

		//virtual methods
		virtual void Use();
		virtual void PrintInfo() const;
	};
}