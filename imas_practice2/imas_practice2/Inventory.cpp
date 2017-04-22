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
		
		cout << "������â �ʰ�. ���� �Ҵ� �ڵ� ����" << endl;
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

		cout << "�������� �����ϴ�" << endl;
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