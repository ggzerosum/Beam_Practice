#pragma once
#include "defines.h"

namespace myNameSpace
{
	class ChildWindow;

	class ChildWndFactoryBase
	{
	private:
		ChildWndFactoryBase(const ChildWndFactoryBase& ref);
		void operator=(const ChildWndFactoryBase& ref);
	public:
		ChildWndFactoryBase();
		virtual ~ChildWndFactoryBase();

	public:
		virtual void registChatWnd(HINSTANCE hInstance) = 0;
		virtual void registDetailedListWnd(HINSTANCE hInstance) = 0;
		virtual void registListWnd(HINSTANCE hInstance) = 0;
		virtual void registProgressWnd(HINSTANCE hInstance) = 0;

		virtual ChildWindow* createChatWnd(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle) = 0;
		virtual ChildWindow* createDetailedListWnd(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle) = 0;
		virtual ChildWindow* createListWnd(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle) = 0;
		virtual ChildWindow* createProgressWnd(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle) = 0;
	};
}

