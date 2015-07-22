/****************************************************************************
**
** class View_MainWindow
**
** Description:
** Main application window
**
****************************************************************************/
#include "ui_view_mainwindow.h"
#include "view_mainwindow.h"
#include "iview.h"

View_MainWindow::View_MainWindow(QWidget *parent) :
  QMainWindow(parent)
{
    setupUi(this);

    //connect neccessary signals and slots
    connect(pbtAdd, SIGNAL(pressed()), this, SLOT(pbtAddPressed()));
    connect(pbtRemove, SIGNAL(pressed()), this, SLOT(pbtRemovePressed()));
    connect(pbtStartStop, SIGNAL(pressed()), this, SLOT(pbtStartStopPressed()));
    connect(openGLWidget, SIGNAL(updateDone()), this, SLOT(updateDone()));
}

View_MainWindow::~View_MainWindow()
{
    disconnect(pbtAdd, SIGNAL(pressed()), this, SLOT(pbtAddPressed()));
    disconnect(pbtRemove, SIGNAL(pressed()), this, SLOT(pbtRemovePressed()));
    disconnect(pbtStartStop, SIGNAL(pressed()), this, SLOT(pbtStartStopPressed()));
    disconnect(openGLWidget, SIGNAL(updateDone()), this, SLOT(updateDone()));
}

void View_MainWindow::updateDone()
{
    graphicUpdateDone();
}

void View_MainWindow::pbtAddPressed()
{
    addGeometry();
}

void View_MainWindow::pbtRemovePressed()
{
    removeGeometry();
}

void View_MainWindow::pbtStartStopPressed()
{
    openGLWidget->setAnimationMovementState(!openGLWidget->getAnimationMovementState());
}

void View_MainWindow::geometryAdded()
{
    openGLWidget->addGeometry();

    setLabelCountText();
}

void View_MainWindow::geometryRemoved()
{
    openGLWidget->removeGeometry();

    setLabelCountText();
}

void View_MainWindow::setLabelCountText()
{
    QString count;
    count.setNum(m_Controler->get_GeometryCount());
    this->lblCount->setText("Cubes count: " + count);
}

void View_MainWindow::fpsChanged(float frequency)
{
    QString framesPerSecond;
    framesPerSecond.setNum(frequency, 'f', 2);

    this->lblFPS->setText("Current FPS: "+framesPerSecond);
}

void View_MainWindow::startupTimeChanged(qint64 time)
{
    float sec = time / 1.0e+09f;

    QString startUpTime;
    startUpTime.setNum(sec, 'f', 9);

    this->lblStartupTime->setText(this->lblStartupTime->text() + startUpTime + "sec");
}

