/***********************************************************************
 ** File: libmain.cpp
 **
 ** Description:
 ** contains main entry point into the fully functioning application.
 ** Because of easier testing of application, it is packed as library.
 ** libmain function parameter (callback) is callback funtion which will be called
 ** after UI is constructed and shown, so application main loop will be started
 ** from libraru wrappers (app and test project). In that way, testing is enabled
 ** on already fully constructed application.
 **
 *************************************************************************/

#include <QApplication>
#include <QLabel>
#include <QSurfaceFormat>
#include <QIcon>
#include <QDir>
#include <QMainWindow>

#include "view_mainwindow.h"

#ifndef QT_NO_OPENGL
#include "view_mainwidget.h"
#endif
#include "libmain.h"
#include "controler.h"
#include "helper_profiling.h"

/*
 * application view, following the Model View Controler (MVC) pattern
 * defined as extern variable for easier testing
 */
View_MainWindow *m_mainWindow = 0;

/*
 * application Path
 */
QString applicationPath;

/*
 * main entry point into application, different implementation will be
 * called for testing application
*/
int qapp_exec()
{
    return qApp->exec();
}

/*
 * main entry point into functionality of application, contains actually
 * full functional application, app project and test project are just
 * simple wrappers around this function
 */
int libmain(int argc, char *argv[], callbackMain callback)
{
    QApplication app(argc, argv);

    applicationPath =  qApp->applicationDirPath();

    globalProfiler.startETimer();

    //init resources (because code is in staticlib,
    //resources have to be initialized before usage)
    Q_INIT_RESOURCE(icon);
    Q_INIT_RESOURCE(shaders);
    Q_INIT_RESOURCE(textures);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);

    //set title, version and application icon
    qApp->setApplicationName("RIGHTWARE DEMO - 'AUT'");
    qApp->setApplicationVersion("1.0");
    QImage imgIcon(":/project_icon", "png");
    QIcon icon(QPixmap::fromImage(imgIcon));
    qApp->setWindowIcon(icon);

    int appRetVal = 0;

#ifndef QT_NO_OPENGL

    m_mainWindow = new View_MainWindow();

    Controler* controler = new Controler(m_mainWindow);

    //adjust startup layout
    m_mainWindow->statusbar->showMessage(m_mainWindow->openGLWidget->getInfoString());
    m_mainWindow->resize(900, 650);
    m_mainWindow->setWindowTitle(qApp->applicationName());
    qApp->setActiveWindow(m_mainWindow);
    m_mainWindow->show();

    //add one geometry on the start
    m_mainWindow->pbtAdd->pressed();

    //start main application event handling
    //are we running in normal or test mode
    if (callback == 0)
        appRetVal = qapp_exec();
    else
        appRetVal = callback();

    //clean up
    delete controler;
    delete m_mainWindow;

    globalProfiler.resetStartupTime();
    globalProfiler.stopETimer();

#else

    QLabel note("OpenGL Support required");
    note.show();

    appRetVal = qapp_exec();

#endif

    return appRetVal;
}

