#include "essential.h"
#include "Inventory.h"

namespace My_NameSpace
{
	Inventory::Inventory(int sizeOfSlots)
		:size(sizeOfSlots)
	{
		slots = new SmartPointer[sizeOfSlots];
	}


	Inventory::~Inventory()
	{
		if (slots != nullptr)
			delete[] slots;
	}


	void Inventory::Add(Items* item)
	{
		for (int i = 0; i < size; i++)
		{
			if (slots[i] == nullptr)
			{
				slots[i] = item;
				return;
			}
		}
		
		cout << "아이템창 초과. 동적 할당 자동 해제" << endl;
		delete item;
	}

	int Inventory::Search(const char* target) const
	{
		Items* pTemp;

		for (int i = 0; i < size; i++)
		{
			if (slots[i] != nullptr)
			{
				pTemp = (Items*)slots[i];
				if (!strcmp(pTemp->GetName(), target))
					return i;
			}
		}

		cout << "아이템이 없습니다" << endl;
		return -1;
	}

	SmartPointer& Inventory::ReturnPTR(int idx) const
	{
		return slots[idx];
	}

	//virtual methods
	void Inventory::Use()
	{
		//empty
	}

	void Inventory::PrintInfo() const
	{
		for (int i = 0; i < size; i++)
		{
			if (slots[i] != nullptr)
			{
				slots[i]->PrintInfo();
			}
		}
	}
}