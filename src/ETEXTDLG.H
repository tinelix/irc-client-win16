#ifndef ETEXTDLG_H
#define ETEXTDLG_H

#include <windows.h>

/* Dialog procedure for our "about" dialog */
BOOL CALLBACK __export EnterTextDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

/* Show our "about" dialog */
void ShowEnterTextDialog(HWND owner, char* _key);

#endif
