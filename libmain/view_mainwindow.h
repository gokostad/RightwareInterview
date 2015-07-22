/****************************************************************************
**
** class View_MainWindow
**
** Description:
** Main application window
**
****************************************************************************/
#ifndef VIEW_MAINWINDOW_H
#define VIEW_MAINWINDOW_H

#ifndef UI_VIEW_MAINWINDOW_H
#include "ui_view_mainwindow.h"
#endif
#include "iview.h"
#include "icontroler.h"

class View_MainWindow : public QMainWindow, public Ui_MainWindow, public IView
{
    Q_OBJECT

public:
    View_MainWindow(QWidget *parent = 0);
    virtual ~View_MainWindow();
    void setControler(IControler* controler) { m_Controler = controler; }
    IControler * const getControler() { return m_Controler; }

    void addOneGeometry() { pbtAddPressed(); }
    void removeOneGeometry() { pbtRemovePressed(); }
    size_t getGeometryCount() { return openGLWidget->geometryCount(); }

protected:
    void setLabelCountText();

private:
    IControler* m_Controler;

private slots:
    void updateDone();
    void pbtAddPressed();
    void pbtRemovePressed();
    void pbtStartStopPressed();

//IView interface implementation
signals:
    void addGeometry();
    void removeGeometry();
    void graphicUpdateDone();

private slots:
    void fpsChanged(float fps);
    void startupTimeChanged(qint64 time);
    void geometryAdded();
    void geometryRemoved();
};
#endif // VIEW_MAINWINDOW_H
