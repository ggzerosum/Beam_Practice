#pragma once
#include "Character.h"

namespace My_NameSpace
{
	class Playable :
		public Character
	{
	public:
		Playable();
		virtual ~Playable();
	};
}