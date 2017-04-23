#include "stdafx.h"
#include "CharacterBase.h"

namespace myNameSpace
{
	CharacterBase::CharacterBase()
		:portrait(nullptr), name(nullptr), hp(MAX_HP), tension(MAX_TENSION), exp_melee(0), exp_firearm(0), exp_medikit(0)
	{}

	CharacterBase::~CharacterBase()
	{
		if (portrait != nullptr)
			DeleteObject(portrait);

		if (name != nullptr)
			delete[] name;
	}
}