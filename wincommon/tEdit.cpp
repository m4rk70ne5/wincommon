#include "tEdit.h"

extern HINSTANCE hInst;

namespace Windows
{
    tEdit::tEdit(TCHAR* label, int x, int y, int width, int height, DWORD id) :
            tControl(x, y, width, height, label, Default, TEXT("Edit"), id)
    {
    }

    void tEdit::CreateMe(HWND parentWindow)
    {
        // default
        m_parentHwnd = parentWindow; // usually the parent dialog
        m_hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, m_class.c_str(), m_Label.c_str(), WS_TABSTOP | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
                    m_x, m_y, m_width, m_height, m_parentHwnd, (HMENU)m_iD, hInst, 0);
    }
}

