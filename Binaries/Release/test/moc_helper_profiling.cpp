/****************************************************************************
** Meta object code from reading C++ file 'helper_profiling.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../libmain/helper_profiling.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'helper_profiling.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Helper_Profiling_t {
    QByteArrayData data[5];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Helper_Profiling_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Helper_Profiling_t qt_meta_stringdata_Helper_Profiling = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Helper_Profiling"
QT_MOC_LITERAL(1, 17, 12), // "startupEvent"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "frequencyEvent"
QT_MOC_LITERAL(4, 46, 13) // "eventSignaled"

    },
    "Helper_Profiling\0startupEvent\0\0"
    "frequencyEvent\0eventSignaled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Helper_Profiling[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Float,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Helper_Profiling::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Helper_Profiling *_t = static_cast<Helper_Profiling *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startupEvent((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->frequencyEvent((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->eventSignaled(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Helper_Profiling::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Helper_Profiling::startupEvent)) {
                *result = 0;
            }
        }
        {
            typedef void (Helper_Profiling::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Helper_Profiling::frequencyEvent)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Helper_Profiling::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Helper_Profiling.data,
      qt_meta_data_Helper_Profiling,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Helper_Profiling::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Helper_Profiling::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Helper_Profiling.stringdata0))
        return static_cast<void*>(const_cast< Helper_Profiling*>(this));
    return QObject::qt_metacast(_clname);
}

int Helper_Profiling::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Helper_Profiling::startupEvent(qint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Helper_Profiling::frequencyEvent(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
