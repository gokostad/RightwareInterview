/****************************************************************************
**
** class Model
**
** Description:
** Model Declaration (MVC pattern used)
**
****************************************************************************/
#ifndef MODEL_H
#define MODEL_H

#include <string>

#include <QObject>

class Model : public QObject
{
    Q_OBJECT

public:
    static Model* CreateModel(QObject *parent = 0);

    float getFPS() { return m_fps; }
    qint64 getStartupTime() { return m_startupTime; }
    int getGeometryCount() { return m_geometryCount; }

private:
    explicit Model(QObject *parent = 0);

signals:
    void fpsChanged(float fps);
    void startupTimeChanged(qint64 time);
    void geometryAdded();
    void geometryRemoved();

private slots:
    void setFPS(float fps);
    void setStartupTime(qint64 startupTime);
    void addGeometry();
    void removeGeometry();

private:
    float m_fps;
    qint64 m_startupTime;
    int m_geometryCount;
};

#endif // MODEL_H
