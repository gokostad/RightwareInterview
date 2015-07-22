/****************************************************************************
**
** apstract class IView
**
** Description:
** View interface (MVC pattern used) declaration
**
****************************************************************************/
#ifndef IVIEW
#define IVIEW

class IControler;

class IView
{
public:
    virtual void setControler(IControler* controler) = 0;

signals:
    virtual void addGeometry() = 0;
    virtual void removeGeometry() = 0;
    virtual void graphicUpdateDone() = 0;

private slots:
    virtual void fpsChanged(float fps) = 0;
    virtual void startupTimeChanged(qint64 time) = 0;
    virtual void geometryAdded() = 0;
    virtual void geometryRemoved() = 0;
};

#endif // IVIEW

