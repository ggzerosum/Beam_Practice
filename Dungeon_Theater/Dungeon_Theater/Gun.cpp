#include "stdafx.h"
#include "Gun.h"

namespace myNameSpace
{
	Gun::Gun(PCTSTR name, int durability, int damage, int maxAmmo)
		:ItemBase(name, durability, damage), max_ammo(maxAmmo), cur_ammo(maxAmmo)
	{
	}


	Gun::~Gun()
	{
	}


	void Gun::setMaxAmmo(int value)
	{
		max_ammo = value;
	}

	int Gun::getMaxAmmo() const
	{
		return max_ammo;
	}


	void Gun::setCurAmmo(int value)
	{
		if (value >= max_ammo)
			value = max_ammo;

		max_ammo = value;
	}

	int Gun::getCurAmmo() const
	{
		return cur_ammo;
	}


	int Gun::use()
	{
		return 0;
	}
}