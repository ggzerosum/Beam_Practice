#pragma once

namespace myNameSpace
{
	class CharacterBase
	{
	protected:
		HBITMAP portrait;
		PTSTR name;
		int hp;
		int tension;
		int exp_melee;
		int exp_firearm;
		int exp_medikit;

	public:
		CharacterBase();
		~CharacterBase();
	};
}