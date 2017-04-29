#pragma once

namespace myNameSpace
{
	class CombatModule
	{
	public:
		CombatModule();
		virtual ~CombatModule();

	public:
		virtual void setting();
		virtual void battle();
		virtual void end();
	};
}