#pragma once

namespace myNameSpace
{
	class ItemBase
	{
	private:
		PTSTR name;
		int damage;
		int max_durability;
		int cur_durability;

	public:
		ItemBase(PCTSTR name, int durability, int damage);
		virtual ~ItemBase();

		void	setMaxDur(int value);
		int		getMaxDur() const;

		void	setCurDur(int value);
		int		getCurDur() const;

		void	setDamage(int value);
		int		getDamage() const;

		void	setName(PCTSTR source);
		PCTSTR	getName();

	public:
		virtual int use() = 0;
	};
}