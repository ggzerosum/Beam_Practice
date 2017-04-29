#include "stdafx.h"
#include "MeleeWeapon.h"

namespace myNameSpace
{
	MeleeWeapon::MeleeWeapon(PCTSTR name, int durability, int damage)
		:ItemBase(name, durability, damage)
	{
	}


	MeleeWeapon::~MeleeWeapon()
	{
	}


	int MeleeWeapon::use()
	{
		return 0;
	}
}