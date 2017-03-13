#pragma once
#include "Base.h"

namespace My_NameSpace
{
	class Items : public Base
	{
	private:
		void* id; //use address for unique number
		char* name;
		int price;

	public:
		Items(const char* name, int price);
		virtual ~Items();

		//Access functinos
		const char* GetName() const;
		int GetPrice() const;
		const void* GetId() const;

		//virtual methods
		virtual void Use() = 0;
		virtual void PrintInfo() const = 0;
	};
}