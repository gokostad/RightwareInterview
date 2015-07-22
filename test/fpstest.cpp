/****************************************************************************
**
** class FPSTest
**
** Description:
** Implementation of FPSTest test case
**
****************************************************************************/
#include <QTest>
#include <QtGlobal>

#include "FPSTest.h"
#include "waitforupdatedone.h"
#include "xmltestreport.h"
#include "global.h"

#include "ui_view_mainwindow.h"
#include "../libmain/libmain.h"
#include "../libmain/view_mainwindow.h"
#include "../libmain/view_mainwidget.h"

FPSTest::FPSTest(QObject *parent) : QObject(parent)
{
}

void FPSTest::initTestCase()
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

    //start tag FPSTest
    xmlReport.addElement("FPSTest");
}

void FPSTest::cleanupTestCase()
{
    disconnect(m_mainWindow, SIGNAL(graphicUpdateDone()), &waitForGraphicsEvent, SLOT(graphicsUpdateDone()));
    //end tag FPSTest
    xmlReport.closeElement();
}

void FPSTest::init()
{
    //clear all geometries (cubes) of screen at the beggining of every test
    size_t geometryCount = m_mainWindow->getGeometryCount();

    while (m_mainWindow->getGeometryCount() != 0)
    {
        m_mainWindow->removeOneGeometry();

        QCOMPARE(geometryCount-1, m_mainWindow->getGeometryCount());

        geometryCount--;
    }

    //start tag Measurement
    xmlReport.addElement("FPSMeasurement");
}

void FPSTest::cleanup()
{
    //close tag Measurement
    xmlReport.closeElement();

    //clear all geometries (cubes) of screen at the end of every test
    size_t geometryCount = m_mainWindow->getGeometryCount();

    while (m_mainWindow->getGeometryCount() != 0)
    {
        m_mainWindow->removeOneGeometry();

        QCOMPARE(geometryCount-1, m_mainWindow->getGeometryCount());

        geometryCount--;
    }
}

//initialize different overload of this test
void FPSTest::test_data()
{
    //add number of cubes for which fps have to be test
    QTest::addColumn<int>("TestNumber");
    QTest::addColumn<int>("GeometryCount");

    int i = 1;
    QTest::newRow("0") << i++ << 0;
    QTest::newRow("1") << i++ << 1;
    QTest::newRow("2") << i++ << 2;
    QTest::newRow("5") << i++ << 5;
#ifndef SHORT_TEST_CASES
    QTest::newRow("10") << i++ << 10;
    QTest::newRow("20") << i++ << 20;
    QTest::newRow("50") << i++ << 50;
    QTest::newRow("100") << i++ << 100;
    QTest::newRow("200") << i++ << 200;
    QTest::newRow("500") << i++ << 500;
    QTest::newRow("1000") << i++ << 1000;
    QTest::newRow("2000") << i++ << 2000;
    QTest::newRow("5000") << i++ << 5000;
    QTest::newRow("10000") << i++ << 10000;
    QTest::newRow("20000") << i++ << 20000;
#endif
}

void FPSTest::test()
{
    QFETCH(int, TestNumber);
    QFETCH(int, GeometryCount);

    //firt construct number of geometries test require
    int count = (int)m_mainWindow->getGeometryCount();
    while (count != GeometryCount)
    {
        m_mainWindow->addOneGeometry();
        count++;

        QCOMPARE(count, (int)m_mainWindow->getGeometryCount());
    }

    //wait for first rendering to finish
    waitForGraphicsEvent.waitForEvent();

    //wait for multiple rendering to happen, to have more precise fps.
    //wait more for more complex graphic rendering
    if (count < 1000)
        QTest::qWait(3000);
     else if (count <= 10000)
        QTest::qWait(10000);
    else
        QTest::qWait(20000);

    //write xml report
    xmlReport.addElementAndCharacters("TestNumber", TestNumber);
    xmlReport.addElementAndCharacters("GeometryCount", GeometryCount);
    xmlReport.addElementAndCharacters("FPS", m_mainWindow->getControler()->getFPS());
}
