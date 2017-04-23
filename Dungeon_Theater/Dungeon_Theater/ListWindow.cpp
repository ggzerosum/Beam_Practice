#include "stdafx.h"
#include "Dungeon_Theater.h"
#include "ListWindow.h"

extern HINSTANCE hInst;

namespace myNameSpace
{

	WCHAR ListWindow::classname[MAX_LOADSTRING] = {0};

	ListWindow::ListWindow(int x, int y, int cx, int cy, HWND parent, DWORD windowStyle)
		:ChildWindow(x, y, cx, cy, classname, parent, windowStyle)
	{}

	ListWindow::~ListWindow()
	{}

	ATOM ListWindow::RegistClass(HINSTANCE hInstance)
	{
		LoadString(hInst, IDS_WINDOW_CHARACTER, ListWindow::classname, MAX_LOADSTRING);
		WNDCLASSEXW wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);

		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance;
		wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DUNGEON_THEATER));
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = GetStockBrush(WHITE_BRUSH);
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = ListWindow::classname;
		wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

		return RegisterClassExW(&wcex);
	}

	LRESULT CALLBACK ListWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_CREATE:
			{

			}
			break;

			case WM_COMMAND:
			{
				int wmId = LOWORD(wParam);
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;

			case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);
				// TODO: Add any drawing code that uses hdc here...

				// EndPaint...
				EndPaint(hWnd, &ps);
			}
			break;

			case WM_DESTROY:
				PostQuitMessage(0);
				break;

			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
			}

		return 0;
	}
}