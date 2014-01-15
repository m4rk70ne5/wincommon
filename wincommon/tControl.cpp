#include "tControl.h"

extern HINSTANCE hInst;

namespace Windows
{

tControl::tControl(int x, int y, int width, int height, TCHAR* label, int(*command)(tControl*, PVOID), TCHAR* szclass, DWORD id, HWND parent) : 
			CommandHandler(command), m_x(x), m_y(y), m_width(width), m_height(height), m_Label(label), m_class(szclass), m_iD(id), m_parentHwnd(parent)
{
	m_additionalInfo = NULL;
}

void tControl::CreateMe(HWND parentWindow)
{
    // default
    m_parentHwnd = parentWindow; // usually the parent dialog
    m_hwnd = CreateWindowEx(NULL, m_class.c_str(), m_Label.c_str(), WS_TABSTOP | WS_CHILD | WS_VISIBLE | SS_LEFTNOWORDWRAP,
                m_x, m_y, m_width, m_height, m_parentHwnd, (HMENU)m_iD, hInst, 0);
}

}
