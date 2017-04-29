#include "stdafx.h"
#include "BattleMgr.h"

namespace myNameSpace
{
	BattleMgr::BattleMgr()
	{
	}


	BattleMgr::~BattleMgr()
	{
		CLEARSINGLETONE(BattleMgr);
	}

	//초기화
	void BattleMgr::init()
	{

	}

	//전투 진행
	void BattleMgr::progress()
	{

	}

	//UI에 전투 결과 반영
	void BattleMgr::render()
	{

	}

	//전투 종료
	void BattleMgr::release()
	{

	}
}