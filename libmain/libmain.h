/****************************************************************************
**
** library entry point declaration
**
****************************************************************************/
#ifndef LIBMAIN_H
#define LIBMAIN_H

typedef int (*callbackMain)();

int libmain(int argc, char *argv[], callbackMain call = 0);

//extern for easier testing
class QString;
extern class View_MainWindow *m_mainWindow;
extern QString applicationPath;

#endif // LIBMAIN_H
