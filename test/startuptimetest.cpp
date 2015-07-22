/****************************************************************************
**
** class StartupTimeTest
**
** Description:
** Implementation of StartupTimeTest test case
**
****************************************************************************/
#include <QTest>
#include <QtGlobal>

#include "startuptimetest.h"
#include "waitforupdatedone.h"
#include "xmltestreport.h"
#include "global.h"

#include "ui_view_mainwindow.h"
#include "../libmain/libmain.h"
#include "../libmain/view_mainwindow.h"
#include "../libmain/view_mainwidget.h"

StartupTimeTest::StartupTimeTest(QObject *parent) : QObject(parent)
{}

void StartupTimeTest::initTestCase()
{
    xmlReport.openReport();

    //any error on initialization for Window and Widget
    QCOMPARE(m_mainWindow != 0, true);
    QCOMPARE(m_mainWindow->openGLWidget != 0, true);

    //signal will be used for catching the drawing finished event
    connect(m_mainWindow, SIGNAL(graphicUpdateDone()), &waitForGraphicsEvent, SLOT(graphicsUpdateDone()));

    //wait for widget to become visible
    if (!waitForGraphicsEvent.waitForEvent())
    {
        QFAIL("Not responsive application");
    }

    QCOMPARE(m_mainWindow->openGLWidget->isVisible(), true);

    //start tag StartupTimeTest
    xmlReport.addElement("StartupTimeTest");
}

void StartupTimeTest::cleanupTestCase()
{
    disconnect(m_mainWindow, SIGNAL(graphicUpdateDone()), &waitForGraphicsEvent, SLOT(graphicsUpdateDone()));
    //end tag StartupTimeTest
    xmlReport.closeElement();
}

void StartupTimeTest::init()
{
    //start tag StartupTimeMeasurement
    xmlReport.addElement("StartupTimeMeasurement");
}

void StartupTimeTest::cleanup()
{
    //close tag StartupTimeMeasurement
    xmlReport.closeElement();
}

void StartupTimeTest::test()
{
    //wait for first rendering to finish
    waitForGraphicsEvent.waitForEvent();

    //aprove widget visibility (maybe we left cause of timeout)
    QCOMPARE(m_mainWindow->openGLWidget->isVisible(), true);

    xmlReport.addElementAndCharacters("Time",
                  static_cast<float>( m_mainWindow->getControler()->getStartupTime() / 1.0e+09f), 9);
}
