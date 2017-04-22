#include "stdafx.h"
#include "Brush.h"

namespace myNameSpace
{
	Brush::Brush(Brush &ref){}
	void Brush::operator=(Brush &ref) {}

	Brush::Brush(COLORREF color)
	{
		handle = CreateSolidBrush(color);
	}

	Brush::~Brush()
	{
		if (handle != nullptr)
			DeleteObject(handle);
	}

	HBRUSH Brush::getHandle()
	{
		return handle;
	}
}