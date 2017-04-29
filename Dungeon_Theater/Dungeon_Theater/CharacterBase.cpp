#include "stdafx.h"
#include "CharacterBase.h"

namespace myNameSpace
{
	CharacterBase::CharacterBase(HBITMAP Bitmap, PTSTR name, int expMelee, int expFirearm, int expMedikit)
		:	portrait(Bitmap), exp_melee(expMelee), exp_firearm(expFirearm), exp_medikit(expMedikit),
			hp(MAX_HP), tension(MAX_TENSION)
	{
		StrToDes(this->name, name);
	}

	CharacterBase::~CharacterBase()
	{
		if (name != nullptr)
			delete[] name;
	}

	//Take handle as argument
	void CharacterBase::setPortrait(HBITMAP source)
	{
		portrait = source;
	}

	void CharacterBase::setName(PCTSTR source)
	{
		if (name != nullptr)
			delete[] name;

		StrToDes(name, source);
	}

	void CharacterBase::setHp(int value)
	{
		hp = value;
	}

	void CharacterBase::setTension(int value)
	{
		tension = value;
	}

	void CharacterBase::setExpMelee(int value)
	{
		exp_melee = value;
	}

	void CharacterBase::setExpFirearm(int value)
	{
		exp_firearm = value;
	}

	void CharacterBase::setExpMedikit(int value)
	{
		exp_medikit = value;
	}


	HBITMAP	CharacterBase::getPortrait() const
	{
		return portrait;
	}

	PCTSTR	CharacterBase::getName() const
	{
		return name;
	}

	int	CharacterBase::getHp() const
	{
		return hp;
	}

	int	CharacterBase::getTension() const
	{
		return tension;
	}

	int	CharacterBase::getExpMelee() const
	{
		return exp_melee;
	}

	int	CharacterBase::getExpFirearm() const
	{
		return exp_firearm;
	}

	int	CharacterBase::getExpMedikit() const
	{
		return exp_medikit;
	}
}