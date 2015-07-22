/****************************************************************************
**
** class Controler
**
** Description:
** Declaration of IControler interface (MVC pattern used)
**
****************************************************************************/

#ifndef CONTROLER_H
#define CONTROLER_H

#include <QObject>

#include "icontroler.h"

class Model;
class IView;

class Controler : public QObject, public IControler
{
    Q_OBJECT
public:
    explicit Controler(IView* view, QObject *parent = 0);
    virtual ~Controler();

    float getFPS();
    qint64 getStartupTime();
    int get_GeometryCount();

private:
    IView* m_View;
    Model* m_Model;
};

#endif // CONTROLER_H
