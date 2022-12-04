#include "AboutDlg.h"
#include "Globals.h"
#include "Resource.h"

/* Dialog procedure for our "about" dialog */
BOOL CALLBACK ConnManDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
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

/* Show our "about" dialog */
void ShowConnManDialog(HWND owner)
{                                                                                     
	MessageBox(owner, "Not implemented yet.", "Error", MB_ICONSTOP|MB_OK);
  //DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_CONNMANDLG), owner, &AboutDialogProc);
}
