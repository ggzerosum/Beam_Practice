#pragma once
#include "idol.h"

class factory
{
public:
	factory();
	~factory();
private:
	idol* ListOfIdols[50];
	int SizeOfList;
	static factory* isCreated;
public:
	void CreateIdolList(void);
	idol* SearchIdol(void);
	idol* SearchIdol(int index);
	static factory* itSelf(void);
};