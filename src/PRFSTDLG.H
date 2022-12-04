#ifndef PRFSTDLG_H
#define PRFSTDLG_H

#include <windows.h>


/* Dialog procedure for our "about" dialog */
BOOL CALLBACK __export ProfileSettingsDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

/* Show our "about" dialog */
void ShowProfileSettingsDialog(HWND owner);  

void SetProfileSettingsUiFont(HWND hWnd);

#endif
