#include "PrfStDlg.h"
#include "Globals.h"
#include "Resource.h" 
#include <windows.h>
#include <string.h>

HWND pageViewerHwnd;
HWND parentHwnd;
WNDPROC prstPagesCallback;

BOOL CALLBACK ProfileSettingsDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
    case WM_COMMAND:
    {
      WORD id = wParam;

      switch (id)
      {
        case IDOK:
        case IDCANCEL:
        {
          EndDialog(hwndDlg, id);
          return TRUE;
        }
      }
      break;
    }
    case WM_INITDIALOG:
    {
      return TRUE;
    }
  }

  return FALSE;
} 

LRESULT CALLBACK PrStPagesComboProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if(uMsg == WM_COMMAND) { 
	    int index = SendMessage(hWnd, (UINT) CB_GETCURSEL, (WPARAM) 0, (LPARAM) 0);
		EndDialog(pageViewerHwnd, 0);
		if(index == 0) {
			pageViewerHwnd = CreateDialog(g_hInstance, MAKEINTRESOURCE(IDD_PCONN_STGSPAGE), parentHwnd, NULL);
  			ShowWindow(pageViewerHwnd, SW_SHOWNORMAL);
  			SetProfileSettingsUiFont(hWnd, pageViewerHwnd, "connection"); 
  		} else {
  			pageViewerHwnd = CreateDialog(g_hInstance, MAKEINTRESOURCE(IDD_PMAIN_STGSPAGE), parentHwnd, NULL);
  			ShowWindow(pageViewerHwnd, SW_SHOWNORMAL);
  			SetProfileSettingsUiFont(hWnd, pageViewerHwnd, "main"); 
  		}
	}
    return CallWindowProc(prstPagesCallback, hWnd, uMsg, wParam, lParam);
}

void ShowProfileSettingsDialog(HWND owner)
{ 
  HWND hWnd = CreateDialog(g_hInstance, MAKEINTRESOURCE(IDD_PROFILESETTINGSDIALOG), owner, ProfileSettingsDialogProc);
  parentHwnd = hWnd;
  if(hWnd) {
  	pageViewerHwnd = CreateDialog(g_hInstance, MAKEINTRESOURCE(IDD_PMAIN_STGSPAGE), hWnd, NULL);
  	ShowWindow(hWnd, SW_SHOW);
  	ShowWindow(pageViewerHwnd, SW_SHOWNORMAL);
  	SetProfileSettingsUiFont(hWnd, pageViewerHwnd, "main"); 
  	prstPagesCallback = (WNDPROC) SetWindowLong((HWND)GetDlgItem(hWnd, IDC_PAGESCOMBO), GWL_WNDPROC, (long)&PrStPagesComboProc);
  	UpdateWindow(pageViewerHwnd);                                                   
  } else {
  	MessageBox(hWnd, "Something wen\'t wrong", "Error", MB_ICONSTOP|MB_OK);
  }
}

void SetProfileSettingsUiFont(HWND hwndParent, HWND hWnd, char* page_name) {
   HFONT defaultFont; 
   LOGFONT fontAttrib; 
   char Pages[2][20] = {
  	"Main", "Connection"  
   };
   int i = 0;
   defaultFont = (HFONT)CreateFont(13, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET,
   	 OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, 
     "Helv");
  SendDlgItemMessage(hwndParent, IDOK, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  SendDlgItemMessage(hwndParent, IDCANCEL, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  SendDlgItemMessage(hwndParent, IDC_PAGESCOMBO, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  for(i = 0; i < 2; i++) {
  	SendMessage((HWND)GetDlgItem(hwndParent, IDC_PAGESCOMBO), CB_ADDSTRING, (WPARAM) 0, (LPARAM) Pages[i]);
  }
  SendMessage((HWND)GetDlgItem(hwndParent, IDC_PAGESCOMBO), CB_SETCURSEL, (WPARAM) 1, (LPARAM) 0);
  if(!strcmp(page_name, "main")) {
  	SendDlgItemMessage(hWnd, IDC_PROFILE_NAME_LABEL, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  	SendDlgItemMessage(hWnd, IDC_PROFILE_NAME_EDIT, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  	SendDlgItemMessage(hWnd, IDC_NICKNAME_LABEL, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  	SendDlgItemMessage(hWnd, IDC_NICKNAME_EDIT, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  	SendDlgItemMessage(hWnd, IDC_PASSWORD_LABEL, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  	SendDlgItemMessage(hWnd, IDC_PASSWORD_EDIT, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  	SendDlgItemMessage(hWnd, IDC_REALNAME_LABEL, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  	SendDlgItemMessage(hWnd, IDC_REALNAME_EDIT, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  } else if(!strcmp(page_name, "connection")) {
  	SendDlgItemMessage(hWnd, IDC_PROFILE_SERVER_LABEL, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  	SendDlgItemMessage(hWnd, IDC_PROFILE_SERVER_EDIT, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  	SendDlgItemMessage(hWnd, IDC_PROFILE_PORT_LABEL, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  	SendDlgItemMessage(hWnd, IDC_PROFILE_PORT_EDIT, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  }
}
