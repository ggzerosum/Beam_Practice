#include "stdafx.h"
#include "Human.h"

namespace myNameSpace
{
	Human::Human()
		:CharacterBase(), item(nullptr)
	{
	}

	Human::~Human()
	{
		if (item != nullptr)
			delete item;
	}


	void Human::setPortrait()
	{

	}

	void Human::setName(PCTSTR source)
	{

	}

	void Human::setItem()
	{

	}

	void Human::setHp(int value)
	{
		hp = value;
	}

	void Human::setTension(int value)
	{
		tension = value;
	}

	void Human::setExpMelee(int value)
	{
		exp_melee = value;
	}

	void Human::setExpFirearm(int value)
	{
		exp_firearm = value;
	}

	void Human::setExpMedikit(int value)
	{
		exp_medikit = value;
	}


}