#ifndef DIALOGTEMPLATE_H
#define DIALOGTEMPLATE_H

#include <windows.h>
#include <vector>

class DialogTemplate
{
    public:
        LPCDLGTEMPLATE Template() { return (LPCDLGTEMPLATE)&v[0]; }
        void AlignToDword();
        void Write(LPCVOID pvWrite, DWORD cbWrite);
        template<typename T>
        void Write(T t)
        {
            Write(&t, sizeof(T));
        }
        void WriteString(LPCWSTR psz);
    protected:
     std::vector<BYTE> v;
};

#endif // DIALOGTEMPLATE_H
