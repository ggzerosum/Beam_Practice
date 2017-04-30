// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <windowsx.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: reference additional headers your program requires here
#define MAX_LOADSTRING 100

#include "defines.h"
#include "SingleTone.h"

#include "Brush.h"

//Child Window들은 추상 팩토리 클래스를 통해 생성되므로 ChildWindow 외의 헤더는 필요치 않음.
#include "ChildWindow.h"
#include "ChildWndFactory.h"