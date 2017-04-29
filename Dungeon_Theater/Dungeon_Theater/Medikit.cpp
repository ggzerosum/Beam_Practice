#include "stdafx.h"
#include "Medikit.h"

namespace myNameSpace
{
	Medikit::Medikit(PCTSTR name, int durability, int damage)
		:ItemBase(name, durability, damage)
	{
	}


	Medikit::~Medikit()
	{
	}


	int Medikit::use()
	{
		return 0;
	}
}