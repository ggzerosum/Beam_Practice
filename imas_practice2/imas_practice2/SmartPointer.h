#pragma once
#include "Base.h"
#include "Sturct.h"
#include "Items.h"

namespace My_NameSpace
{
	class SmartPointer :
		public Base
	{
	private:
		//Let's make referencing count!
		PTR_REF* value;

	public:
		//default constrructor
		SmartPointer();
		//constructor
		SmartPointer(Base* ptr);
		//delete value when destroy
		virtual ~SmartPointer();

		//copy constructor. just increase count.
		//copy consturctor
		SmartPointer(const SmartPointer &ref);

		//= operator overloading.
		SmartPointer& operator=(const SmartPointer &ref);

		//* operator
		Base& operator*();

		//-> operator
		Base* operator->();

		//== operator
		//bool operator==(const SmartPointer &ref);
		//friend bool operator==(const SmartPointer &left, const SmartPointer &right);

		//!= operator
		//friend bool operator!=(const SmartPointer &left, const SmartPointer &right);
		
		//(Items*) operator
		operator Items*();

		//virtual methods
		virtual void Use();
		virtual void PrintInfo() const;
	};
}