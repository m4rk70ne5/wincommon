#include "tDialog.h"
#include <Shlobj.h>
#include <algorithm>

std::vector<Windows::tDialog*> Windows::tDialog::m_activeDialog;

// Windows::tDialog::m_activeDialog.clear(); // initialize static member

namespace Windows
{

tDialog::tDialog(WORD x, WORD y, WORD width, WORD height, LPCWSTR title)
{
    m_dT.Write<DWORD>(WS_VISIBLE | WS_OVERLAPPEDWINDOW | DS_CENTER | DS_MODALFRAME); // style
    m_dT.Write<DWORD>(0); // extended style
    m_dT.Write<WORD>(0); // cdit
    m_dT.Write<WORD>(x); // X
    m_dT.Write<WORD>(y); // Y
    m_dT.Write<WORD>(width); // width
    m_dT.Write<WORD>(height); // height
    m_dT.WriteString(L""); // no menu
    m_dT.WriteString(L""); // default dialog class
    m_dT.WriteString(title); // title
    m_dT.AlignToDword();
}

tDialog::~tDialog()
{
    for(size_t i = 0; i < m_controls.size(); ++i)
        delete m_controls[i];
}

int tDialog::Show(HWND parent)
{
    m_activeDialog.push_back(this); // make it current dialog
    int ret = DialogBoxIndirect(hInst, m_dT.Template(), parent, (DLGPROC)DialogProc);
    m_activeDialog.pop_back(); // remove it from dialog queue
    return ret;
}

BOOL CALLBACK tDialog::DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    std::vector<tControl*> controls = m_activeDialog.back()->GetControls();

    switch(uMsg)
    {
        case WM_INITDIALOG:
        {
             // cycle through controls, calling CreateWindowEx on each one
             for (std::vector<tControl*>::iterator iControl = controls.begin(); iControl != controls.end(); iControl++)
             {
                 (*iControl)->CreateMe(hwndDlg);
             }
            return TRUE;
        }
        case WM_CLOSE:
            EndDialog(hwndDlg, 0);
            return TRUE;

        case WM_COMMAND:
            // cycle through controls
            for (std::vector<tControl*>::iterator iControl = controls.begin(); iControl != controls.end(); iControl++)
            {
                if (LOWORD(wParam) == (*iControl)->GetID())
                    (*iControl)->CommandHandler(*iControl, (*iControl)->m_additionalInfo);
            }
            return TRUE;
    }
    return FALSE;
}

tOpenFolderDialog::tOpenFolderDialog()
{
    // initialize com
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    m_path = new TCHAR[m_pathSize];
    memset(m_path, 0, m_pathSize);
}

tOpenFolderDialog::~tOpenFolderDialog()
{
    CoUninitialize();
    delete[] m_path;
}

void tOpenFolderDialog::Show(HWND hwnd, std::wstring title, LPWSTR initialPath)
{
    BROWSEINFO bI;
    bI.hwndOwner = hwnd;
    bI.iImage = 0;
    bI.lpszTitle = title.c_str();
    bI.pszDisplayName = m_path;
    bI.ulFlags = BIF_NEWDIALOGSTYLE|BIF_RETURNONLYFSDIRS;
    bI.lpfn = BrowseCallbackProc;
    bI.lParam = (LPARAM)initialPath; // to start on an initial path
    bI.pidlRoot = NULL;

    LPITEMIDLIST lpItem = SHBrowseForFolder(&bI);
    if( lpItem != NULL )
        SHGetPathFromIDList(lpItem, m_path);
    CoTaskMemFree(lpItem); // free pidl
}

int CALLBACK tOpenFolderDialog::BrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	switch (uMsg)
	{
		case BFFM_INITIALIZED:
		{
			if (lpData != NULL)
			{
				SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);
			}
		}
	}

	return 0;
}

//end namespace
}