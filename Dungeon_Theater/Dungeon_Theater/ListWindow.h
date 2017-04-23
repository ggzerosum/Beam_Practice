#pragma once

#include "ChildWindow.h"

namespace myNameSpace
{
	class ListWindow : public ChildWindow
	{
	private:
		static WCHAR classname[MAX_LOADSTRING];

	public:
		ListWindow(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle);
		~ListWindow();

	public: //프로시저 함수, 윈도우 클래스 등록 함수
		static ATOM RegistClass(HINSTANCE hInstance);
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
}