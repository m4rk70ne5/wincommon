#ifndef DEFAULTHANDLERS_H
#define DEFAULTHANDLERS_H

namespace Windows
{
    class tControl;
}

int Default(Windows::tControl*, PVOID);
int Quit(Windows::tControl*, PVOID); // closes parent dialog

#endif
