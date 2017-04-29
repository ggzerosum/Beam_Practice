#pragma once
#include "CharacterBase.h"

namespace myNameSpace
{
	class ItemBase;

	class Human :
		public CharacterBase
	{
	private:
		ItemBase* item;

	public:
		Human(HBITMAP Bitmap, PTSTR name, ItemBase* item, int expMelee = 0, int expFirearm = 0, int expMedikit = 0);
		virtual ~Human();

		void		setItem	(ItemBase* targetItem);
		ItemBase*	getItem	() const;

	public:
		virtual void useItem();
	};
}