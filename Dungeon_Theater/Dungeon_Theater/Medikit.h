#pragma once
#include "ItemBase.h"

namespace myNameSpace
{
	class Medikit :
		public ItemBase
	{
	public:
		Medikit(PCTSTR name, int durability, int damage);
		virtual ~Medikit();

	public:
		virtual int use();
	};
}