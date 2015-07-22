/****************************************************************************
**
** class WaitForUpdateDone
**
** Description:
** Declaration of WaitForUpdateDone class. Used for catching rendering finished
** event from libmain application (main opengl widget)
**
****************************************************************************/
#ifndef WAITFORUPDATEDONE_H
#define WAITFORUPDATEDONE_H

#include <QObject>

class WaitForUpdateDone : public QObject
{
    Q_OBJECT
public:
    explicit WaitForUpdateDone(QObject *parent = 0);

    bool waitForEvent();

private:
    volatile bool done;

public slots:
    void graphicsUpdateDone();
};

#endif // WAITFORUPDATEDONE_H
