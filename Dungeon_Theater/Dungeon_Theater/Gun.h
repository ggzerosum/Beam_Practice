#pragma once
#include "ItemBase.h"

namespace myNameSpace
{
	class Gun :
		public ItemBase
	{
	private:
		int max_ammo;
		int cur_ammo;

	public:
		Gun(PCTSTR name, int durability, int damage, int maxAmmo);
		virtual ~Gun();

		void	setMaxAmmo(int value);
		int		getMaxAmmo() const;

		void	setCurAmmo(int value);
		int		getCurAmmo() const;

	public:
		virtual int use();
	};
}