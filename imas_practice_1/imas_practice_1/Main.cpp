#include "includes.h"
#include "classes.h"

void main(void)
{
	//��ȣ¯ ����!!
	idol SihoZZang(17, 83, "ŰŸ�ڿ� ��ȣ", "��縮~?");

	factory::itSelf()->CreateIdolList();

	//��ȣ¯���� �ൿ�� ����غ���!
	SihoZZang.DoHateSpeech(*factory::itSelf()->SearchIdol());
}