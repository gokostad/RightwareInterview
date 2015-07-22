/****************************************************************************
**
** class WaitForUpdateDone
**
** Description:
** Implementation of WaitForUpdateDone class. Used for catching rendering finished
** event from libmain application (main opengl widget)
**
****************************************************************************/
#include <QTest>
#include <QtGlobal>

#include "waitforupdatedone.h"
#include "ui_view_mainwindow.h"
#include "../libmain/view_mainwindow.h"
#include "../libmain/libmain.h"

WaitForUpdateDone waitForGraphicsEvent;

WaitForUpdateDone::WaitForUpdateDone(QObject *parent) :
    QObject(parent),
    done(false)
{
}

void WaitForUpdateDone::graphicsUpdateDone()
{
    this->done = true;
}

bool WaitForUpdateDone::waitForEvent()
{
    const int MAXCOUNT = 2000;
    int count = 0;
    //wait for graphic to finish rendering but max 20sec
    while (!this->done && ++count < MAXCOUNT)
    {
        QTest::qWait(10);
    }
    this->done = false;
    return (count < MAXCOUNT);
}
