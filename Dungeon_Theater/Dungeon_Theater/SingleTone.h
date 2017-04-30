#pragma once
#include "defines.h"

#define GETSINGLETONE(T) \
myNameSpace::SingleTone<T>::get()

#define CLEARSINGLETONE(T) \
myNameSpace::SingleTone<T>::del()

namespace myNameSpace
{
	template<typename T>
	class SingleTone
	{
	private:
		static T* Inst;

	public:
		static T*	get();
		static void del();
	};


	template<typename T>
	T* SingleTone<T>::Inst = nullptr;

	template<typename T>
	T* SingleTone<T>::get()
	{
		if (Inst == nullptr)
		{
			Inst = new T;
		}

		return Inst;
	}

	template<typename T>
	void SingleTone<T>::del()
	{
		Inst = nullptr;
	}
}