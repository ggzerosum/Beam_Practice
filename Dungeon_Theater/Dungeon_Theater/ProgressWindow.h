#pragma once
#include "Dungeon_Theater.h"
#include "ChildWindow.h"

namespace myNameSpace
{
	class ProgressWindow :
		public ChildWindow
	{
	private:
		static WCHAR classname[MAX_LOADSTRING];

	public:
		ProgressWindow(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle);
		~ProgressWindow();

	public: //���ν��� �Լ�, ������ Ŭ���� ��� �Լ�
		static ATOM RegistClass(HINSTANCE hInstance);
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
}