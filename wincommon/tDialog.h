#ifndef TDIALOG_H
#define TDIALOG_H

#include <windows.h>
#include <vector>
#include "DialogTemplate.h"
#include "tControl.h"

extern HINSTANCE hInst;

namespace Windows
{
    class tDialog
    {
        public:
            tDialog(WORD, WORD, WORD, WORD, LPCWSTR); // xy pos, width, height, title
            virtual ~tDialog();
            void AddControl(tControl* control) { m_controls.push_back(control); };
            int Show(HWND);
            static std::vector<tDialog*> m_activeDialog;
            std::vector<tControl*>& GetControls() { return m_controls; };
        protected:
            DialogTemplate m_dT;
            static BOOL CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);
            std::vector<tControl*> m_controls;
            void CreateControls();
    };
    class tOpenFolderDialog
    {
        public:
            tOpenFolderDialog();
            virtual ~tOpenFolderDialog();
            void Show(HWND, std::wstring, LPWSTR); // returns the path selected
            TCHAR* GetPath() { return m_path; };
        protected:
            static const int m_pathSize = 255;
            TCHAR* m_path;
			static int CALLBACK BrowseCallbackProc(HWND, UINT, LPARAM, LPARAM);
    };
}

#endif
