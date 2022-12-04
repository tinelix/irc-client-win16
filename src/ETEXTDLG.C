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
  }
}
