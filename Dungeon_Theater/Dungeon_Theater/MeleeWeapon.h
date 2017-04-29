#pragma once
#include "ItemBase.h"

namespace myNameSpace
{
	class MeleeWeapon :
		public ItemBase
	{
	public:
		MeleeWeapon(PCTSTR name, int durability, int damage);
		virtual ~MeleeWeapon();

	public:
		virtual int use();
	};
}