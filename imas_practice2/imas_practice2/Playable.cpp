#include "essential.h"
#include "SmartPointer.h"
#include "Playable.h"
#include "Cloth.h"
#include "Inventory.h"

namespace My_NameSpace
{
	Playable::Playable(const char* name, int age, int sizeOfInventory)
		:equippedItem(nullptr)
	{
		StrToDes(this->name, name);
		this->age = age;
		inventory = new Inventory(sizeOfInventory);
	}


	Playable::~Playable()
	{
		if (name != nullptr)
			delete[] name;

		if (inventory != nullptr)
			delete inventory;
	}

	void Playable::Use()
	{}

	void Playable::PrintInfo() const
	{
		cout << "[캐릭터 정보]" << endl;
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;

		inventory->PrintInfo();
		//equippedItem->? 왜 안되는 거지?
		
	}

	void Playable::addItem(const char* name, int price, GRADES grade)
	{
		inventory->Add(new Cloth(name, price, grade));
	}

	void Playable::EquipItem(const char* target)
	{
		int idx = inventory->Search(target);
		if (idx != -1)
		{
			equippedItem = inventory->ReturnPTR(idx);
		}
	}
}