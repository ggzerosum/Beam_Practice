#include "stdafx.h"
#include "ItemBase.h"

namespace myNameSpace
{
	ItemBase::ItemBase(PCTSTR name, int durability, int damage)
		:max_durability(durability), cur_durability(durability), damage(damage)
	{
		StrToDes(this->name, name);
	}


	ItemBase::~ItemBase()
	{
		if (name != nullptr)
			delete[] name;
	}


	void ItemBase::setMaxDur(int value)
	{
		max_durability = value;
	}

	int ItemBase::getMaxDur() const
	{
		return max_durability;
	}


	void ItemBase::setCurDur(int value)
	{
		if (value >= max_durability)
			value = max_durability;

		cur_durability = value;
	}

	int ItemBase::getCurDur() const
	{
		return cur_durability;
	}


	void ItemBase::setDamage(int value)
	{
		damage = value;
	}

	int ItemBase::getDamage() const
	{
		return damage;
	}


	void ItemBase::setName(PCTSTR source)
	{
		if (name != nullptr)
			delete[] name;

		StrToDes(name, source);
	}

	PCTSTR ItemBase::getName()
	{
		return name;
	}
}