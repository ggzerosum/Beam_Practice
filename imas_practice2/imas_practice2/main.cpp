#include "essential.h"
#include "Base.h"
#include "Items.h"
#include "SmartPointer.h"
#include "Inventory.h"
#include "Cloth.h"
#include "Playable.h"

namespace ns = My_NameSpace;
using ns::SmartPointer;
using ns::Base;
using ns::Items;
using ns::Cloth;
using ns::GRADES;
using ns::Inventory;
using ns::Playable;

typedef SmartPointer sp;

void main(void)
{
	Playable my_character("�¹�", 17, 5);
	my_character.addItem("�ǻ�A", 700, GRADES::GRADE_B);
	my_character.addItem("�ǻ�B", 1000, GRADES::GRADE_C);
	my_character.addItem("�ǻ�C", 5000, GRADES::GRADE_F);

	my_character.EquipItem("�ǻ�C");

	my_character.PrintInfo();
}