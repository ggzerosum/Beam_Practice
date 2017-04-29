#include "stdafx.h"
#include "Human.h"
#include "ItemBase.h"

namespace myNameSpace
{
	Human::Human(HBITMAP Bitmap, PTSTR name, ItemBase* item, int expMelee, int expFirearm, int expMedikit)
		:CharacterBase(Bitmap, name, expMelee, expFirearm, expMedikit), item(item)
	{
	}

	Human::~Human()
	{
		if (item != nullptr)
			delete item;
	}


	void Human::setItem(ItemBase* targetItem)
	{
		item = targetItem;
	}

	ItemBase* Human::getItem() const
	{
		return item;
	}


	void Human::useItem()
	{
		item->use();
	}
}