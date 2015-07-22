/****************************************************************************
**
** Just most trivial wrapper around library (fully functional application).
** Such organisation make automated application testing much easier.
**
****************************************************************************/

#include "../libmain/libmain.h"

int main(int argc, char *argv[])
{
    return libmain(argc, argv);
}
