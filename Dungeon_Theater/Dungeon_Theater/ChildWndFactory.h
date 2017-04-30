#pragma once
#include "defines.h"
#include "ChildWndFactoryBase.h"

namespace myNameSpace
{
	class ChildWndFactory :
		public ChildWndFactoryBase
	{
	private:
		ChildWndFactory(const ChildWndFactory& ref);
		void operator=(const ChildWndFactory& ref);

	public:
		ChildWndFactory();
		virtual ~ChildWndFactory();

	public:
		virtual void registChatWnd(HINSTANCE hInstance);
		virtual void registDetailedListWnd(HINSTANCE hInstance);
		virtual void registListWnd(HINSTANCE hInstance);
		virtual void registProgressWnd(HINSTANCE hInstance);

		virtual ChildWindow* createChatWnd(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle);
		virtual ChildWindow* createDetailedListWnd(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle);
		virtual ChildWindow* createListWnd(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle);
		virtual ChildWindow* createProgressWnd(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle);
	};
}