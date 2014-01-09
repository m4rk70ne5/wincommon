#ifndef TEDIT_H
#define TEDIT_H

#include "tControl.h"

namespace Windows
{
    class tEdit : tControl
    {
        public:
            tEdit(TCHAR*, int, int, int, int, DWORD); // button text, x, y, w, h, ID
            // in the future, make ID automatically obtained from an ID factory
            virtual void CreateMe(HWND);
    };
}

#endif
