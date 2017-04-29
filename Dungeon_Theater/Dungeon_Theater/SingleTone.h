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
		static T* marker;

	public:
		static T*	get();
		static void del();
	};


	template<typename T>
	T* SingleTone<T>::marker = nullptr;

	template<typename T>
	T* SingleTone<T>::get()
	{
		if (marker == nullptr)
		{
			marker = new T;
		}

		return marker;
	}

	template<typename T>
	void SingleTone<T>::del()
	{
		marker = nullptr;
	}
}