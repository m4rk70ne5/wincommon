#ifndef TLISTBOX_H
#define TLISTBOX_H

#include "tControl.h"

namespace Windows
{
    class tListBox : public tControl
    {
		protected:
			void ClearAll(); // clears all contents
        public:
            tListBox(TCHAR*, int, int, int, int, DWORD, int(*)(tControl*, PVOID) = Default); // button text, x, y, w, h, ID
            // in the future, make ID automatically obtained from an ID factory
			virtual ~tListBox() { };
			virtual void CreateMe(HWND);
			int GetCurrentEntry(); // returns the index of the currently selected item
    };
}

#endif

