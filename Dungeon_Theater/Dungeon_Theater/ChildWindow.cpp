#include "stdafx.h"
#include "ChildWindow.h"

extern HINSTANCE hInst;

namespace myNameSpace
{
	ChildWindow::ChildWindow(int x, int y, int cx, int cy, PCTSTR classname, HWND parent, DWORD windowStyle)
	{
		this->hParent = parent;
		this->x = x;
		this->y = y;
		this->cx = cx;
		this->cy = cy;

		CreateWindow(classname, NULL, windowStyle, x, y, cx, cy, parent, NULL, hInst, NULL);
	}


	ChildWindow::~ChildWindow()
	{
	}
}