#pragma once

namespace myNameSpace
{
	class ChildWindow
	{
	protected:
		HWND hParent;
		int x;
		int y;
		int cx;
		int cy;

	protected:
		ChildWindow(int x, int y, int cx, int cy, PCTSTR classname, HWND parent, DWORD windowStyle);
		~ChildWindow();
	};
}