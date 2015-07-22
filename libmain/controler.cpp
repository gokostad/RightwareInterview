/****************************************************************************
**
** class Controler
**
** Description:
** Implementation of IControler interface (MVC pattern used)
**
****************************************************************************/
#include "controler.h"
#include "iview.h"
#include "model.h"
#include "helper_profiling.h"

Controler::Controler(IView* view, QObject *parent) :
    QObject(parent),
    m_View(view),
    m_Model(0)
{
    m_Model = Model::CreateModel();

    //make relation about events and listeners in system
    connect(dynamic_cast<QObject*>(m_View), SIGNAL(addGeometry()), m_Model, SLOT(addGeometry()));
    connect(dynamic_cast<QObject*>(m_View), SIGNAL(removeGeometry()), m_Model, SLOT(removeGeometry()));

    connect(dynamic_cast<QObject*>(m_View), SIGNAL(graphicUpdateDone()), &globalProfiler, SLOT(eventSignaled()));
    connect(&globalProfiler, SIGNAL(startupEvent(qint64)), m_Model, SLOT(setStartupTime(qint64)));
    connect(&globalProfiler, SIGNAL(frequencyEvent(float)), m_Model, SLOT(setFPS(float)));

    connect(m_Model, SIGNAL(fpsChanged(float)), dynamic_cast<QObject*>(m_View), SLOT(fpsChanged(float)));
    connect(m_Model, SIGNAL(startupTimeChanged(qint64)), dynamic_cast<QObject*>(m_View), SLOT(startupTimeChanged(qint64)));
    connect(m_Model, SIGNAL(geometryAdded()), dynamic_cast<QObject*>(m_View), SLOT(geometryAdded()));
    connect(m_Model, SIGNAL(geometryRemoved()), dynamic_cast<QObject*>(m_View), SLOT(geometryRemoved()));

    m_View->setControler(this);
}

Controler::~Controler()
{
    disconnect(dynamic_cast<QObject*>(m_View), SIGNAL(addGeometry()), m_Model, SLOT(addGeometry()));
    disconnect(dynamic_cast<QObject*>(m_View), SIGNAL(removeGeometry()), m_Model, SLOT(removeGeometry()));

    disconnect(dynamic_cast<QObject*>(m_View), SIGNAL(graphicUpdateDone()), &globalProfiler, SLOT(eventSignaled()));
    disconnect(&globalProfiler, SIGNAL(startupEvent(qint64)), m_Model, SLOT(setStartupTime(qint64)));
    disconnect(&globalProfiler, SIGNAL(frequencyEvent(float)), m_Model, SLOT(setFPS(float)));

    disconnect(m_Model, SIGNAL(fpsChanged(float)), dynamic_cast<QObject*>(m_View), SLOT(fpsChanged(float)));
    disconnect(m_Model, SIGNAL(startupTimeChanged(qint64)), dynamic_cast<QObject*>(m_View), SLOT(startupTimeChanged(qint64)));
    disconnect(m_Model, SIGNAL(geometryAdded()), dynamic_cast<QObject*>(m_View), SLOT(geometryAdded()));
    disconnect(m_Model, SIGNAL(geometryRemoved()), dynamic_cast<QObject*>(m_View), SLOT(geometryRemoved()));
    if (m_Model)
        delete m_Model;
}

float Controler::getFPS()
{
    return m_Model->getFPS();
}

qint64 Controler::getStartupTime()
{
    return m_Model->getStartupTime();
}

int Controler::get_GeometryCount()
{
    return m_Model->getGeometryCount();
}
