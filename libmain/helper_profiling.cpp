/****************************************************************************
**
** class Profiling
**
** Description:
** Implementaion - purpose is to measure two things:
**     1. one 'once triggered' event, from the momment of this object is
**        constructed to the momment first 'signal arised' eventSignaled() event
**     2. to measure continuosly frequence of signal arised event
**
****************************************************************************/
#include "helper_profiling.h"

#include <QElapsedTimer>

Helper_Profiling globalProfiler;

Helper_Profiling::Helper_Profiling(QObject *parent) : QObject(parent),
    m_counter(0),
    m_startup_done(false),
    m_stoped(false)
{
    m_timer.start();
}

void Helper_Profiling::resetStartupTime()
{
    m_counter.fetchAndStoreAcquire(0);
    m_startup_done = false;
}

void Helper_Profiling::stopETimer()
{
    //stop timer virtualy, it is expected startETimer will ba called afterward
    //usuful when library is loaded more than once.
    m_stoped = true;
}

void Helper_Profiling::startETimer()
{
    if (m_stoped)
    {
        m_timer.restart();
        m_stoped = false;
    }
}

void Helper_Profiling::eventSignaled()
{
    //so event which timing we are measuring is triggered, and
    //we should updated our counter
    if (m_stoped)
        return;

    m_counter.fetchAndAddAcquire(1);
    if (!m_startup_done)
    {
        m_startup_done = true;
        startupEvent(m_timer.nsecsElapsed());
        //give a freedom to timer, it does not need to be accurate
        startTimer(1000, Qt::VeryCoarseTimer);
    }
}

void Helper_Profiling::timerEvent(QTimerEvent*)
{
    //we are getting our one second timer event, let's see how many events
    //we had measured in the middle time, so frequency can be easily found
    if (m_stoped)
        return;

    float ps = int(m_counter) / (m_timer.nsecsElapsed() / 1.0e+09f);
    m_counter.fetchAndStoreAcquire(0);
    m_timer.restart();
    frequencyEvent(ps);
}

