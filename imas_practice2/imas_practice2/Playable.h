#pragma once
#include "Character.h"

namespace My_NameSpace
{
	class Inventory;
	class SmartPointer;

	class Playable : public Character
	{
	private:
		char* name;
		int age;
		Inventory* inventory;
		SmartPointer equippedItem;
	public:
		Playable(const char* name, int age, int sizeOfInventory);
		virtual ~Playable();

		virtual void Use();
		virtual void PrintInfo() const;
		virtual void addItem(const char* name, int price, GRADES grade);
		virtual void EquipItem(const char* target);
	};
}