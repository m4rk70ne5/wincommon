#ifndef HANDLERS_H
#define HANDLERS_H

namespace Windows
{
    class tControl;
}

int SpawnSettingsDialog(Windows::tControl*); // command handler for settings
int SpawnFileBrowser(Windows::tControl*);
int Default(Windows::tControl*);
int Quit(Windows::tControl*); // closes parent dialog

#endif
