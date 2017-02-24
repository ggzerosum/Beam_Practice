/*
	시호의 헤이트 스피치
	version : 1.0
	완성일자: 2017.2.25
*/

#include "includes.h"
#include "classes.h"

void main(void)
{
	bool key = true;
	idol* siho;
	factory::itSelf()->CreateIdolList();
	siho = factory::itSelf()->SearchIdol(0);

	while (key)
	{
		//시호짱에게 행동을 명령해보자!
		siho->DoHateSpeech(factory::itSelf()->SearchIdol());

		Sleep(2000);
		system("cls");
	}
}