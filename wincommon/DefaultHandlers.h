#ifndef DEFAULTHANDLERS_H
#define DEFAULTHANDLERS_H

namespace Windows
{
    class tControl;
}

int Default(Windows::tControl*);
int Quit(Windows::tControl*); // closes parent dialog

#endif
