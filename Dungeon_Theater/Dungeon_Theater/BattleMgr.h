#pragma once

namespace myNameSpace
{
	class DungeonBase;
	class CombatModule;
	class RenderModule;

	class BattleMgr
	{
	private:
		DungeonBase* dungeon;
		CombatModule* combat_module;
		RenderModule* render_module;

	public:
		BattleMgr();
		virtual ~BattleMgr();

	public:
		virtual void init();
		virtual void progress();
		virtual void render();
		virtual void release();
	};
}