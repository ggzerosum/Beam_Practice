/*
	��ȣ�� ����Ʈ ����ġ
	version : 1.0
	�ϼ�����: 2017.2.25
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
		//��ȣ¯���� �ൿ�� ����غ���!
		siho->DoHateSpeech(factory::itSelf()->SearchIdol());

		Sleep(2000);
		system("cls");
	}
}