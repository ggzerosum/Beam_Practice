#pragma once

#define myNameSpace miniGame_iMas_Dungeon_2017

#define MyMainWindow_Width 750
#define MyMainWindow_Height 500

//캐릭터 스탯 관련 매크로 상수
#define MAX_HP 100
#define MINOR_INJURY 80
#define SERIOUS_INJURY 50

#define MAX_TENSION 100
#define MAX_EXP 10000

#define MAX_GROUP_MEMBER 4

//Copy str from source to des
//"defines.h"
inline void StrToDes(PTSTR& des, PCTSTR source)
{
	des = new TCHAR[lstrlen(source) + 1];
	lstrcpy(des, source);
}