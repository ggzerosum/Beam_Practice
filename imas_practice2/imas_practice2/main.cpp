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
	Playable my_character("Ω¬πŒ", 17, 5);
	my_character.addItem("¿«ªÛA", 700, GRADES::GRADE_B);
	my_character.addItem("¿«ªÛB", 1000, GRADES::GRADE_C);
	my_character.addItem("¿«ªÛC", 5000, GRADES::GRADE_F);

	my_character.EquipItem("¿«ªÛC");

	my_character.PrintInfo();
}