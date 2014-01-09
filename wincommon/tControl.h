#ifndef TCONTROL_H
#define TCONTROL_H

#include <windows.h>
#include <string>
#include "DefaultHandlers.h"
#include "DefaultResource.h"

namespace Windows
{
    class tControl
    {
        public:
            tControl(int, int, int, int, TCHAR*, int(*)(tControl*) = ::Default,
                     TCHAR* = TEXT("Static"), DWORD = IDC_STATIC, HWND = NULL);
            HWND GetParentWindow() { return m_parentHwnd; };
            virtual void CreateMe(HWND);
            DWORD GetID() { return m_iD; };
            int (*CommandHandler)(tControl*);
        protected:
            int m_x, m_y, m_width, m_height;
            std::wstring m_Label, m_class;
            DWORD m_iD;
            HWND m_parentHwnd, m_hwnd;
    };
}
#endif
