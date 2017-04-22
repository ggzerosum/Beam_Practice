#pragma once
#include "Base.h"
namespace My_NameSpace
{
	class Character :
		public Base
	{
	public:
		Character();
		virtual ~Character();

		//virtual methods
		virtual void Use() = 0;
		virtual void PrintInfo() const = 0;
		virtual void addItem(const char* name, int price, GRADES grade) = 0;
		virtual void EquipItem(const char* target) = 0;
	};
}