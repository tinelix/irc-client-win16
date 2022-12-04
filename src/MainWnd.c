#include "AboutDlg.h"
#include "Globals.h"
#include "MainWnd.h" 
#include "ConnMDlg.h"
#include "Resource.h"

/* Main window class and title */
static const char MainWndClass[] = "Main Window";

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch (msg)
  {
    case WM_COMMAND:
    {
      WORD id = wParam;

      switch (id)
      {
        case ID_ABOUT:
        {
          ShowAboutDialog(hWnd);
          return 0;
        }
        case ID_CONNECT:
        {
          ShowConnManDialog(hWnd);
          return 0;
        }
        case IDOK:
        case IDCANCEL:
        {
          DestroyWindow(hWnd);
          return 0;
        }
      }
      break;
    }

    /* Item from system menu has been invoked */
    case WM_SYSCOMMAND:
    {
      WORD id = wParam;

      switch (id)
      {
        /* Show "about" dialog on about system menu item */
        case ID_ABOUT:
        {
          ShowAboutDialog(hWnd);
          return 0;
        }
      }
      break;
    }

    case WM_CREATE:
    {
      HWND dummyWnd;
      RECT rect;

      dummyWnd = CreateWindowEx(0, "STATIC", "STATIC", 0, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, NULL, NULL, g_hInstance,
                                NULL);
      GetWindowRect(dummyWnd, &rect);
      DestroyWindow(dummyWnd);

      SetWindowPos(hWnd, 0, rect.left, rect.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

      return 0;
    }

    case WM_DESTROY:
    { 
      QuitApp();
      PostQuitMessage(0);
      return 0;
    }
  }

  return DefWindowProc(hWnd, msg, wParam, lParam);
}

BOOL RegisterMainWindowClass()
{
  WNDCLASS wc;

  wc.style         = 0;
  wc.lpfnWndProc   = &MainWndProc;
  wc.cbClsExtra    = 0;
  wc.cbWndExtra    = DLGWINDOWEXTRA;
  wc.hInstance     = g_hInstance;
  wc.hIcon         = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_APPICON));
  wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wc.lpszMenuName  = NULL;
  wc.lpszClassName = MainWndClass;

  return (RegisterClass(&wc)) ? TRUE : FALSE;
}

HWND CreateMainWindow()
{
  HWND hWnd = CreateDialog(g_hInstance, MAKEINTRESOURCE(IDD_MAINDIALOG), NULL, NULL);

  if (hWnd)
  {          
    HMENU hMenu; 
    HMENU hSysMenu;
    hMenu = LoadMenu(g_hInstance, MAKEINTRESOURCE(IDR_APPMENU));
    hSysMenu = GetSystemMenu(hWnd, FALSE);
    InsertMenu(hSysMenu, 5, MF_BYPOSITION | MF_SEPARATOR, 0, NULL);
    InsertMenu(hSysMenu, 6, MF_BYPOSITION, ID_ABOUT, "About...");
    SetMenu(hWnd, hMenu);
    SetWindowText(hWnd, AppName);
  }

  return hWnd;
}
