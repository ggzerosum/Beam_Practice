#pragma once
#include "Dungeon_Theater.h"
#include "ChildWindow.h"

namespace myNameSpace
{
	class ChatWindow :
		public ChildWindow
	{
	private:
		static WCHAR classname[MAX_LOADSTRING];

	public:
		ChatWindow(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle);
		~ChatWindow();

	public: //프로시저 함수, 윈도우 클래스 등록 함수
		static ATOM RegistClass(HINSTANCE hInstance);
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
}