#include "stdafx.h"
#include "ChildWndFactory.h"

#include "ChatWindow.h"
#include "DetailedListWindow.h"
#include "ListWindow.h"
#include "ProgressWindow.h"

namespace myNameSpace
{
	namespace ns = myNameSpace;

	ChildWndFactory::ChildWndFactory(const ChildWndFactory& ref){}
	void ChildWndFactory::operator=(const ChildWndFactory& ref){}

	ChildWndFactory::ChildWndFactory(){}
	ChildWndFactory::~ChildWndFactory()
	{
		CLEARSINGLETONE(ChildWndFactory);
	}

	//registClass �Լ� ȣ��
	void ChildWndFactory::registChatWnd(HINSTANCE hInstance)
	{
		ChatWindow::RegistClass(hInstance);
	}

	//registClass �Լ� ȣ��
	void ChildWndFactory::registDetailedListWnd(HINSTANCE hInstance)
	{
		DetailedListWindow::RegistClass(hInstance);
	}

	//registClass �Լ� ȣ��
	void ChildWndFactory::registListWnd(HINSTANCE hInstance)
	{
		ListWindow::RegistClass(hInstance);
	}

	//registClass �Լ� ȣ��
	void ChildWndFactory::registProgressWnd(HINSTANCE hInstance)
	{
		ProgressWindow::RegistClass(hInstance);
	}


	ChildWindow* ChildWndFactory::createChatWnd(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle)
	{
		ChildWindow* ptr = new ChatWindow(x, y, cx, cy, parent, windowStyle);
		return ptr;
	}

	ChildWindow* ChildWndFactory::createDetailedListWnd(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle)
	{
		ChildWindow* ptr = new DetailedListWindow(x, y, cx, cy, parent, windowStyle);
		return ptr;
	}

	ChildWindow* ChildWndFactory::createListWnd(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle)
	{
		ChildWindow* ptr = new ListWindow(x, y, cx, cy, parent, windowStyle);
		return ptr;
	}

	ChildWindow* ChildWndFactory::createProgressWnd(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle)
	{
		ChildWindow* ptr = new ProgressWindow(x, y, cx, cy, parent, windowStyle);
		return ptr;
	}
}