#include "includes.h"
#include "classes.h"

void main(void)
{
	//시호짱 생성!!
	idol SihoZZang(17, 83, "키타자와 시호", "어당리~?");

	factory::itSelf()->CreateIdolList();

	//시호짱에게 행동을 명령해보자!
	SihoZZang.DoHateSpeech(*factory::itSelf()->SearchIdol());
}