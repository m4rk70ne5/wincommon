#include "tButton.h"

extern HINSTANCE hInst;

namespace Windows
{
    tButton::tButton(TCHAR* label, int x, int y, int width, int height, DWORD id, int(*command)(tControl*)) :
            tControl(x, y, width, height, label, command, TEXT("Button"), id)
    {
    }

    void tButton::CreateMe(HWND parentWindow)
    {
        // default
        m_parentHwnd = parentWindow; // usually the parent dialog
        m_hwnd = CreateWindowEx(NULL, m_class.c_str(), m_Label.c_str(), WS_TABSTOP | WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                    m_x, m_y, m_width, m_height, m_parentHwnd, (HMENU)m_iD, hInst, 0);
    }
    tBrowseButton::tBrowseButton(TCHAR* label, int x, int y, int width, int height, DWORD id, DWORD editId, int(*command)(tControl*)) :
                    tButton(label, x, y, width, height, id, command), m_EditId(editId)
    {
    }
}
