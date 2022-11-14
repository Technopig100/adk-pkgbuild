/****************************************************************************
** Meta object code from reading C++ file 'stopwatch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../coretime-v4.4.0/src/stopwatch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stopwatch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StopWatch_t {
    QByteArrayData data[9];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StopWatch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StopWatch_t qt_meta_stringdata_StopWatch = {
    {
QT_MOC_LITERAL(0, 0, 9), // "StopWatch"
QT_MOC_LITERAL(1, 10, 7), // "running"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 6), // "paused"
QT_MOC_LITERAL(4, 26, 8), // "inactive"
QT_MOC_LITERAL(5, 35, 3), // "lap"
QT_MOC_LITERAL(6, 39, 7), // "lapTime"
QT_MOC_LITERAL(7, 47, 4), // "time"
QT_MOC_LITERAL(8, 52, 1) // "t"

    },
    "StopWatch\0running\0\0paused\0inactive\0"
    "lap\0lapTime\0time\0t"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StopWatch[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       7,    1,   45,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,    6,
    QMetaType::Void, QMetaType::LongLong,    8,

       0        // eod
};

void StopWatch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StopWatch *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->running(); break;
        case 1: _t->paused(); break;
        case 2: _t->inactive(); break;
        case 3: _t->lap((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 4: _t->time((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StopWatch::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StopWatch::running)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StopWatch::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StopWatch::paused)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (StopWatch::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StopWatch::inactive)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (StopWatch::*)(const QTime & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StopWatch::lap)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (StopWatch::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StopWatch::time)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StopWatch::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_StopWatch.data,
    qt_meta_data_StopWatch,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StopWatch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StopWatch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StopWatch.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int StopWatch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void StopWatch::running()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void StopWatch::paused()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void StopWatch::inactive()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void StopWatch::lap(const QTime & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void StopWatch::time(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
