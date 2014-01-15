#include "tListBox.h"

extern HINSTANCE hInst;

namespace Windows
{
    tListBox::tListBox(TCHAR* label, int x, int y, int width, int height, DWORD id, int(*com)(tControl*, PVOID)) :
            tControl(x, y, width, height, label, com, TEXT("ListBox"), id)
    {
    }

    void tListBox::CreateMe(HWND parentWindow)
    {
        // default
        m_parentHwnd = parentWindow; // usually the parent dialog
        m_hwnd = CreateWindowEx(WS_EX_WINDOWEDGE, m_class.c_str(), m_Label.c_str(), WS_CHILD | WS_VISIBLE | WS_VSCROLL | LBS_STANDARD | 
			LBS_NOINTEGRALHEIGHT | LBS_USETABSTOPS, m_x, m_y, m_width, m_height, m_parentHwnd, (HMENU)m_iD, hInst, 0);
        // optional
        for (int i = 0; i < 5; i++)
        {
            SendMessage(GetDlgItem(m_parentHwnd, m_iD)/*hwndList*/, LB_ADDSTRING, 0, (LPARAM)TEXT("Hello!"));
        }
    }
	void tListBox::ClearAll()
	{
		SendMessage(GetDlgItem(m_parentHwnd, m_iD), LB_RESETCONTENT, 0, 0);
	}

	int tListBox::GetCurrentEntry()
	{
		int index = SendMessage(GetDlgItem(GetParentWindow(), GetID()), LB_GETCURSEL, 0, 0);
		return index;
	}
}


