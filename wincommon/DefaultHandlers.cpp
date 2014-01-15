#include "DefaultHandlers.h"
#include "tDialog.h"
#include "tEdit.h"
#include "tButton.h"
#include "tControl.h"
#include <string>

int Default(Windows::tControl* control, PVOID unused)
{
    return 0;
}

int Quit(Windows::tControl* control, PVOID unused)
{
    EndDialog(control->GetParentWindow(), 0);
    return 0;
}
