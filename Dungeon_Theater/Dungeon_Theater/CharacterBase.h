#pragma once

namespace myNameSpace
{
	class CharacterBase
	{
	private:
		HBITMAP portrait;
		PTSTR name;
		int hp;
		int tension;
		int exp_melee;
		int exp_firearm;
		int exp_medikit;

	public:
		CharacterBase(HBITMAP Bitmap, PTSTR name, int expMelee, int expFirearm, int expMedikit);
		virtual ~CharacterBase();

		void setPortrait	(HBITMAP source);
		void setName		(PCTSTR source);
		void setHp			(int value);
		void setTension		(int value);
		void setExpMelee	(int value);
		void setExpFirearm	(int value);
		void setExpMedikit	(int value);

		HBITMAP		getPortrait()	const;
		PCTSTR		getName()		const;
		int			getHp()			const;
		int			getTension()	const;
		int			getExpMelee()	const;
		int			getExpFirearm()	const;
		int			getExpMedikit()	const;

	public:
		virtual void useItem()=0;
	};
}