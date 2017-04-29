#pragma once

namespace myNameSpace
{
	class CharacterBase;

	class Group
	{
	private:
		CharacterBase* group[MAX_GROUP_MEMBER];
		int maxLength;

	public:
		Group();
		~Group();

		void			setMember	(CharacterBase* character);
		CharacterBase*	getMember	(int position);
		int				getMaxLength();
	};
}
