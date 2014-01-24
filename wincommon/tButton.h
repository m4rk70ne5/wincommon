#ifndef TBUTTON_H
#define TBUTTON_H

#include "tControl.h"

namespace Windows
{
    class tButton : public tControl
    {
		protected:
			bool m_startDisabled;
        public:
			// button text, x, y, w, h, ID, and command
            tButton(TCHAR*, int, int, int, int, DWORD, int(*)(tControl*, PVOID) = ::Quit, bool = FALSE);
            // in the future, make ID automatically obtained from an ID factory
            virtual void CreateMe(HWND);
    };
    class tBrowseButton : public tButton
    {
        public:
            tBrowseButton(TCHAR*, int, int, int, int, DWORD, DWORD, int(*)(tControl*, PVOID));
            DWORD GetEditID() {return m_EditId; };
        protected:
            DWORD m_EditId;
    };
}
#endif
