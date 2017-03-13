#pragma once
#include "Base.h"
#include "Sturct.h"

namespace My_NameSpace
{
	class SmartPointer :
		public Base
	{
	private:
		//Let's make referencing count!
		PTR_REF* value;

	public:
		//consturctor
		SmartPointer(Base* ptr);
		//delete value when destroy
		virtual ~SmartPointer();

		//copy constructor. just increase count.
		SmartPointer(const SmartPointer &ref);

		//= operator overloading.
		SmartPointer& operator=(const SmartPointer &ref);

		//* operator
		Base& operator*();

		//-> operator
		Base* operator->();

		//virtual methods
		virtual void Use();
		virtual void PrintInfo() const;
	};
}