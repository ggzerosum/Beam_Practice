#include "essential.h"
#include "Cloth.h"

namespace My_NameSpace
{
	Cloth::Cloth(const char* name, int price, GRADES grade)
		:Items(name, price), grade(grade)
	{
		//empty
	}


	Cloth::~Cloth()
	{
	}

	//virtual methods
	void Cloth::Use()
	{
		//empty
	}

	void Cloth::PrintInfo() const
	{
		//cout(temporary)
		cout << "식별번호: " << GetId() << endl;
		cout << "의상 이름: " << GetName() << endl;
		cout << "가격: " << GetPrice() << endl;
		cout << "등급: " << grade << endl;
	}
}
