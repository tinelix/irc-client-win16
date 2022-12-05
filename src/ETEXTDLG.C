#include "ETextDlg.h"
#include "PrfStDlg.h"
#include "Globals.h"
#include "Resource.h"
#include <string.h> 

char* key;

BOOL CALLBACK EnterTextDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
    case WM_COMMAND:
    {
      WORD id = wParam;

      switch (id)
      {
        case IDOK: {
	      ShowProfileSettingsDialog(hwndDlg);
          EndDialog(hwndDlg, id);
          return TRUE;       
        }
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

void ShowEnterTextDialog(HWND owner, char* _key)
{
  HWND hWnd = CreateDialog(g_hInstance, MAKEINTRESOURCE(IDD_ENTERTEXTDIALOG), owner, EnterTextDialogProc);
  if(hWnd) {
  	ShowWindow(hWnd, SW_SHOW);
  	key = _key;
	if(!strcmp(_key, "profile_name")) {
	  HWND editTextLabel = GetDlgItem(hWnd, IDC_ENTERTEXTLABEL);
	  SetWindowText(editTextLabel, "Profile name:");
	}
	SetEnterTextUiFont(hWnd);
  }
}

void SetEnterTextUiFont(HWND hWnd) {
   HFONT defaultFont; 
   LOGFONT fontAttrib;
   defaultFont = (HFONT)CreateFont(13, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET,
   	 OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, 
     "Helv");  
    
  SendDlgItemMessage(hWnd, IDOK, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  SendDlgItemMessage(hWnd, IDCANCEL, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  SendDlgItemMessage(hWnd, IDC_ENTERTEXTLABEL, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  SendDlgItemMessage(hWnd, IDC_ENTERTEXTBOX, WM_SETFONT, (WPARAM)defaultFont, TRUE);
}
