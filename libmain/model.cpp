/****************************************************************************
**
** class Model
**
** Description:
** Model Implemetation (MVC pattern used)
**
****************************************************************************/
#include "model.h"

//model factory
Model* Model::CreateModel(QObject *parent)
{
    return new Model(parent);
}

Model::Model(QObject *parent) :
    QObject(parent),
    m_fps(0),
    m_startupTime(0),
    m_geometryCount(0)
{}

void Model::setFPS(float fps)
{
    if (m_fps != fps)
    {
        m_fps = fps;
        fpsChanged(m_fps);
    }
}

void Model::setStartupTime(qint64 startupTime)
{
    if (m_startupTime != startupTime)
    {
        m_startupTime = startupTime;
        startupTimeChanged(m_startupTime);
    }
}

void Model::addGeometry()
{
    m_geometryCount++;
    geometryAdded();
}

void Model::removeGeometry()
{
    if (m_geometryCount > 0)
    {
        m_geometryCount--;
        geometryRemoved();
    }
}
