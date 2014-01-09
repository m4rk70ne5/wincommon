#ifndef TLISTBOX_H
#define TLISTBOX_H

#include "tControl.h"

namespace Windows
{
    class tListBox : tControl
    {
        public:
            tListBox(TCHAR*, int, int, int, int, DWORD, int(*)(tControl*) = Default); // button text, x, y, w, h, ID
            // in the future, make ID automatically obtained from an ID factory
            virtual void CreateMe(HWND);
    };
}

#endif

