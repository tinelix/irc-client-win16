#include "PrfStDlg.h"
#include "Globals.h"
#include "Resource.h"

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

void ShowProfileSettingsDialog(HWND owner)
{ 
  HWND hWnd = CreateDialog(g_hInstance, MAKEINTRESOURCE(IDD_PROFILESETTINGSDIALOG), owner, ProfileSettingsDialogProc);
  if(hWnd) {
  	HWND pageViewerHwnd = CreateWindow("STATIC", "Hello", WS_CHILD|WS_BORDER, 
  	10, 10, 120, 120, hWnd, NULL, g_hInstance, NULL);
  	pageViewerHwnd = CreateDialog(g_hInstance, MAKEINTRESOURCE(IDD_PMAIN_STGSPAGE), hWnd, NULL);
  	ShowWindow(hWnd, SW_SHOW);
  	ShowWindow(pageViewerHwnd, SW_SHOWNORMAL);
  	UpdateWindow(pageViewerHwnd);                                                    
  } else {
  	MessageBox(hWnd, "Something wen\'t wrong", "Error", MB_ICONSTOP|MB_OK);
  }
}

void SetProfileSettingsUiFont(HWND hWnd) {
   HFONT defaultFont; 
   LOGFONT fontAttrib;

}
