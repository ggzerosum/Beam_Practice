// Dungeon_Theater.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Dungeon_Theater.h"


// Global Variables:
// 프로세스 전역변수 정의:
namespace ns = myNameSpace;
HINSTANCE hInst;                                // current instance
HWND g_hwnd;									// main window handle
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
ns::Brush TitleBarBrush(RGB(214, 219, 233));	// titlebar color
ns::Brush BackGroundBrush(RGB(41, 58, 86));		// background color
ns::Brush ChildBackGroundBrush(RGB(255,255,255));
ns::Brush ChildTitleBarBrush(RGB(77, 96, 130));
ns::Brush ChildSubTitleBarBrush(RGB(207, 214, 229));
ns::Brush ChatBoxBackGroundBrush(RGB(240, 240, 240));

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.
	// Main 단계의 지역 변수 정의.


    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DUNGEON_THEATER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);
	ns::ListWindow::RegistClass(hInstance);
	ns::ChatWindow::RegistClass(hInstance);
	ns::ProgressWindow::RegistClass(hInstance);
	ns::DetailedListWindow::RegistClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DUNGEON_THEATER));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DUNGEON_THEATER));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground	= BackGroundBrush.getHandle();//(HBRUSH)GetStockObject(WHITE_BRUSH);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_POPUP | WS_BORDER | WS_VISIBLE | WS_CLIPCHILDREN,
      200, 200, MyMainWindow_Width, MyMainWindow_Height, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
enum
{
	padding = 5,
	height_TitleBar = 60,

	width_List = 200,
	height_List = 428,

	X_Chat = 195,
	width_Chat = 360,
	height_Chat = 300,

};

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
		{
			g_hwnd = hWnd;

			RECT rt;
			GetClientRect(hWnd, &rt);
			CreateWindow(TEXT("STATIC"), NULL, WS_CHILD | WS_VISIBLE, rt.left, rt.top, rt.right, height_TitleBar, hWnd, (HMENU)-1, hInst, NULL);

			ns::ChatWindow MyChatWindow(X_Chat, height_TitleBar + padding, width_Chat, height_Chat, hWnd, WS_CHILD | WS_VISIBLE | WS_BORDER);
			ns::ListWindow MyCharacterListWindow(rt.left + padding, height_TitleBar + padding, X_Chat - padding * 2, height_List, hWnd, WS_CHILD | WS_VISIBLE | WS_BORDER);
			ns::ProgressWindow MyProgressWindow(X_Chat, height_TitleBar + height_Chat + padding * 2, width_Chat, MyMainWindow_Height - height_TitleBar - height_Chat - (padding * 2) - 7, hWnd, WS_CHILD | WS_VISIBLE | WS_BORDER);
			ns::DetailedListWindow MyListWindow(width_List + width_Chat, height_TitleBar + padding, MyMainWindow_Width - width_List - width_Chat - padding -2, MyMainWindow_Height - height_TitleBar - (padding * 2) - 2, hWnd, WS_CHILD | WS_VISIBLE | WS_BORDER);
		}
		break;

	case WM_CTLCOLORSTATIC:
	{
		return (LRESULT)TitleBarBrush.getHandle();
	}
	break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

	case WM_SIZE:
		{
			
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

	case WM_NCHITTEST:
		{
			POINT pos = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
			ScreenToClient(hWnd, &pos);

			if (pos.y <= height_TitleBar)
				return HTCAPTION;
			else
				return DefWindowProc(hWnd, WM_NCHITTEST, wParam, lParam);
		}
		break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
