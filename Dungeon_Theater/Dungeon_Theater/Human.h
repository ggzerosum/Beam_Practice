#pragma once
#include "CharacterBase.h"

namespace myNameSpace
{
	class Human :
		public CharacterBase
	{
	private:
		char *item; //아이템 공간 임시

	public:
		Human();
		~Human();

	public:
		void setPortrait();
		void setName(PCTSTR source);
		void setItem();
		void setHp(int value);
		void setTension(int value);
		void setExpMelee(int value);
		void setExpFirearm(int value);
		void setExpMedikit(int value);

		HBITMAP getPortrait();
		PCTSTR getName();
		void getItem();
		int getHp();
		int getTension();
		int getExpMelee();
		int getExpFirearm();
		int getExpMedikit();
	};
}