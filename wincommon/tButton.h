#ifndef TBUTTON_H
#define TBUTTON_H

#include "tControl.h"

namespace Windows
{
    class tButton : public tControl
    {
        public:
            tButton(TCHAR*, int, int, int, int, DWORD, int(*)(tControl*) = ::Quit); // button text, x, y, w, h, ID, and command
            // in the future, make ID automatically obtained from an ID factory
            virtual void CreateMe(HWND);
    };
    class tBrowseButton : public tButton
    {
        public:
            tBrowseButton(TCHAR*, int, int, int, int, DWORD, DWORD, int(*)(tControl*));
            DWORD GetEditID() {return m_EditId; };
        protected:
            DWORD m_EditId;
    };
}
#endif
