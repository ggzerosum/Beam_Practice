#pragma once

namespace My_NameSpace
{
	class Base
	{
	protected:
		//copy chars(?) to des. for inheritance.
		void StrToDes(char* &destination, const char* source);
	public:
		Base();
		virtual ~Base();

		//virtual methods
		virtual void Use() = 0;
		virtual void PrintInfo() const = 0;
	};
}