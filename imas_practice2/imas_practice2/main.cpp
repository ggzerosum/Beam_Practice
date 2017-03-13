#include "essential.h"
#include "Base.h"
#include "Items.h"
#include "SmartPointer.h"

#include "Cloth.h"

namespace ns = My_NameSpace;
using ns::SmartPointer;
using ns::Base;
using ns::Items;
using ns::Cloth;
using ns::GRADES;

typedef SmartPointer sp;

void main(void)
{
	sp ptr = new Cloth("´r~ ¹ìÆÄÀÌ¾î", 10000, GRADES::GRADE_A);
	ptr->PrintInfo();
}