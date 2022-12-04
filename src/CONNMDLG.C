#include "ConnMDlg.h"   
#include "ETextDlg.h"
#include "Globals.h"
#include "Resource.h"

BOOL CALLBACK ConnManDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
    case WM_COMMAND:
    {
      WORD id = wParam;

      switch (id)
      {
        case IDOK: {
          EndDialog(hwndDlg, id);
          return TRUE;
        }
        case IDC_CREATE_PROFILE_BTN: {
          ShowEnterTextDialog(hwndDlg, "profile_name");
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

void ShowConnManDialog(HWND owner)
{
  if(MessageBox(owner, "Not implemented yet.", "Error", MB_ICONSTOP|MB_OK) == IDOK) {    
  	HWND hWnd = CreateDialog(g_hInstance, MAKEINTRESOURCE(IDD_CONNMANDIALOG), owner, ConnManDialogProc);
  	SetConnManUiFont(hWnd);   
  }
}

void SetConnManUiFont(HWND hWnd) {
   HFONT defaultFont; 
   LOGFONT fontAttrib;
   defaultFont = (HFONT)CreateFont(13, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET,
   	 OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, 
     "Helv");  
    
  SendDlgItemMessage(hWnd, IDOK, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  SendDlgItemMessage(hWnd, IDC_CREATE_PROFILE_BTN, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  SendDlgItemMessage(hWnd, IDC_CONNECT_BTN, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  SendDlgItemMessage(hWnd, IDC_EDIT_PROFILE_BTN, WM_SETFONT, (WPARAM)defaultFont, TRUE);
  SendDlgItemMessage(hWnd, IDC_DELETE_PROFILE_BTN, WM_SETFONT, (WPARAM)defaultFont, TRUE);
}
