#include "stdafx.h"
#include "ListWindow.h"

namespace ns = myNameSpace;
extern HINSTANCE hInst;
extern ns::Brush ChildBackGroundBrush;
extern ns::Brush ChildTitleBarBrush;
extern ns::Brush ChildSubTitleBarBrush;

enum
{
	ID_TitleBar			= 0	,
	ID_SubTitleBar			,

	height_TitleBar		= 25,
	height_SubTitleBar	= 30,
};

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
		wcex.lpfnWndProc = ListWindow::WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance;
		wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DUNGEON_THEATER));
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = ChildBackGroundBrush.getHandle();
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
				RECT rt;
				GetClientRect(hWnd, &rt);
				CreateWindow(TEXT("STATIC"), TEXT(" Character"), WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, rt.left, rt.top, rt.right, height_TitleBar, hWnd, (HMENU)ID_TitleBar, hInst, NULL);
				CreateWindow(TEXT("STATIC"), NULL, WS_CHILD | WS_VISIBLE, rt.left, height_TitleBar, rt.right, height_SubTitleBar, hWnd, (HMENU)ID_SubTitleBar, hInst, NULL);
			}
			break;

			case WM_CTLCOLORSTATIC:
			{
				HWND handle = (HWND)lParam;
				HDC hdc = (HDC)wParam;
				int id = GetDlgCtrlID(handle);

				switch (id)
				{
					case ID_TitleBar:
						SetTextColor(hdc, RGB(255, 255, 255));
						SetBkMode(hdc, TRANSPARENT);
						return (LRESULT)ChildTitleBarBrush.getHandle();
						break;

					case ID_SubTitleBar:
						return (LRESULT)ChildSubTitleBarBrush.getHandle();
						break;

					default:
						break;
				}
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