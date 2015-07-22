/********************************************************************************
** Form generated from reading UI file 'view_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_MAINWINDOW_H
#define UI_VIEW_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "view_mainwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblFPS;
    QLabel *lblStartupTime;
    QLabel *lblCount;
    QVBoxLayout *verticalLayout;
    QPushButton *pbtAdd;
    QPushButton *pbtRemove;
    QPushButton *pbtStartStop;
    QFrame *frame;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    View_MainWidget *openGLWidget;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lblFPS = new QLabel(centralwidget);
        lblFPS->setObjectName(QStringLiteral("lblFPS"));

        verticalLayout_3->addWidget(lblFPS);

        lblStartupTime = new QLabel(centralwidget);
        lblStartupTime->setObjectName(QStringLiteral("lblStartupTime"));

        verticalLayout_3->addWidget(lblStartupTime);

        lblCount = new QLabel(centralwidget);
        lblCount->setObjectName(QStringLiteral("lblCount"));

        verticalLayout_3->addWidget(lblCount);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pbtAdd = new QPushButton(centralwidget);
        pbtAdd->setObjectName(QStringLiteral("pbtAdd"));
        pbtAdd->setFlat(false);

        verticalLayout->addWidget(pbtAdd);

        pbtRemove = new QPushButton(centralwidget);
        pbtRemove->setObjectName(QStringLiteral("pbtRemove"));

        verticalLayout->addWidget(pbtRemove);

        pbtStartStop = new QPushButton(centralwidget);
        pbtStartStop->setObjectName(QStringLiteral("pbtStartStop"));

        verticalLayout->addWidget(pbtStartStop);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(1, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        openGLWidget = new View_MainWidget(frame);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));

        gridLayout->addWidget(openGLWidget, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(1, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        verticalLayout_2->addWidget(frame);


        horizontalLayout_2->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        lblFPS->setText(QApplication::translate("MainWindow", "Current FPS:", 0));
        lblStartupTime->setText(QApplication::translate("MainWindow", "Startup Time: ", 0));
        lblCount->setText(QApplication::translate("MainWindow", "Cubes count:", 0));
        pbtAdd->setText(QApplication::translate("MainWindow", "Add Cube", 0));
        pbtRemove->setText(QApplication::translate("MainWindow", "Remove Cube", 0));
        pbtStartStop->setText(QApplication::translate("MainWindow", "Start / Stop Animation", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_MAINWINDOW_H
