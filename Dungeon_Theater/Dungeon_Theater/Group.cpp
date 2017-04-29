#include "stdafx.h"
#include "Group.h"
#include "CharacterBase.h"

namespace myNameSpace
{
	Group::Group()
		:maxLength(0)
	{
	}


	Group::~Group()
	{
		for (int i = 0; i < maxLength; i++)
		{
			delete group[i];
		}
	}

	void Group::setMember(CharacterBase* character)
	{
		group[maxLength] = character;
		maxLength++;
	}

	CharacterBase* Group::getMember(int index)
	{
		return group[index];
	}

	int Group::getMaxLength()
	{
		return maxLength;
	}
}