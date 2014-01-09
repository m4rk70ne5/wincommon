#include "DialogTemplate.h"

void DialogTemplate::AlignToDword()
{
    if (v.size() % 4)
        Write(NULL, 4 - (v.size() % 4));
}

void DialogTemplate::Write(LPCVOID pvWrite, DWORD cbWrite)
{
    v.insert(v.end(), cbWrite, 0);
    if (pvWrite)
        CopyMemory(&v[v.size() - cbWrite], pvWrite, cbWrite);
}

void DialogTemplate::WriteString(LPCWSTR psz)
{
    Write(psz, (lstrlenW(psz) + 1) * sizeof(WCHAR));
}
