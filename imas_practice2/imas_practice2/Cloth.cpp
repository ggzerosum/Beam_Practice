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
		cout << "�ĺ���ȣ: " << GetId() << endl;
		cout << "�ǻ� �̸�: " << GetName() << endl;
		cout << "����: " << GetPrice() << endl;
		cout << "���: " << grade << endl;
	}
}
