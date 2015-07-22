/****************************************************************************
**
** apstract class IControler
**
** Description:
** IControler interface (MVC pattern used) declaration
**
****************************************************************************/

#ifndef ICONTROLER
#define ICONTROLER

class IControler
{
public:
    virtual float getFPS() = 0;
    virtual qint64 getStartupTime() = 0;
    virtual int get_GeometryCount() = 0;
};

#endif // ICONTROLER

