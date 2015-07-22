/****************************************************************************
** Meta object code from reading C++ file 'view_mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../libmain/view_mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view_mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_View_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_View_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_View_MainWindow_t qt_meta_stringdata_View_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "View_MainWindow"
QT_MOC_LITERAL(1, 16, 11), // "addGeometry"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "removeGeometry"
QT_MOC_LITERAL(4, 44, 17), // "graphicUpdateDone"
QT_MOC_LITERAL(5, 62, 10), // "updateDone"
QT_MOC_LITERAL(6, 73, 13), // "pbtAddPressed"
QT_MOC_LITERAL(7, 87, 16), // "pbtRemovePressed"
QT_MOC_LITERAL(8, 104, 19), // "pbtStartStopPressed"
QT_MOC_LITERAL(9, 124, 10), // "fpsChanged"
QT_MOC_LITERAL(10, 135, 3), // "fps"
QT_MOC_LITERAL(11, 139, 18), // "startupTimeChanged"
QT_MOC_LITERAL(12, 158, 4), // "time"
QT_MOC_LITERAL(13, 163, 13), // "geometryAdded"
QT_MOC_LITERAL(14, 177, 15) // "geometryRemoved"

    },
    "View_MainWindow\0addGeometry\0\0"
    "removeGeometry\0graphicUpdateDone\0"
    "updateDone\0pbtAddPressed\0pbtRemovePressed\0"
    "pbtStartStopPressed\0fpsChanged\0fps\0"
    "startupTimeChanged\0time\0geometryAdded\0"
    "geometryRemoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    1,   76,    2, 0x08 /* Private */,
      11,    1,   79,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   10,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void View_MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        View_MainWindow *_t = static_cast<View_MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addGeometry(); break;
        case 1: _t->removeGeometry(); break;
        case 2: _t->graphicUpdateDone(); break;
        case 3: _t->updateDone(); break;
        case 4: _t->pbtAddPressed(); break;
        case 5: _t->pbtRemovePressed(); break;
        case 6: _t->pbtStartStopPressed(); break;
        case 7: _t->fpsChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 8: _t->startupTimeChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 9: _t->geometryAdded(); break;
        case 10: _t->geometryRemoved(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (View_MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&View_MainWindow::addGeometry)) {
                *result = 0;
            }
        }
        {
            typedef void (View_MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&View_MainWindow::removeGeometry)) {
                *result = 1;
            }
        }
        {
            typedef void (View_MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&View_MainWindow::graphicUpdateDone)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject View_MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_View_MainWindow.data,
      qt_meta_data_View_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *View_MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View_MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_View_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< View_MainWindow*>(this));
    if (!strcmp(_clname, "Ui_MainWindow"))
        return static_cast< Ui_MainWindow*>(const_cast< View_MainWindow*>(this));
    if (!strcmp(_clname, "IView"))
        return static_cast< IView*>(const_cast< View_MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int View_MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void View_MainWindow::addGeometry()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void View_MainWindow::removeGeometry()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void View_MainWindow::graphicUpdateDone()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
