/****************************************************************************
**
** class Profiling
**
** Description:
** Declaration - purpose is to measure two things:
**     1. one 'once triggered' event, from the momment of this object is
**        constructed to the momment first 'signal arised' eventSignaled() event
**     2. to measure continuosly frequence of signal arised event
**
****************************************************************************/

#ifndef HELPER_PROFILING_H
#define HELPER_PROFILING_H

#include <QTimer>
#include <QElapsedTimer>
#include <QAtomicInt>

class Helper_Profiling : public QObject
{
    Q_OBJECT

public:
    explicit Helper_Profiling(QObject* parent = 0);

    void resetStartupTime();
    void stopETimer();
    void startETimer();

protected:
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;

public slots:
    //triggered for frequency measurement
    void eventSignaled();

signals:
    //signal for startup time measurement
    //with nanosecond time measurement parameter
    void startupEvent(qint64);

    //signal for frequency measurement
    //with frequency as parameter
    void frequencyEvent(float);

protected:
    QElapsedTimer m_timer;
    QAtomicInt m_counter;
    bool m_startup_done;
    bool m_stoped;
};

//as global, will be construced before main have been called
extern Helper_Profiling globalProfiler;

#endif // HELPER_PROFILING_H
