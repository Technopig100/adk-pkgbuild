/****************************************************************************
** Meta object code from reading C++ file 'alarmitemwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../coretime-v4.4.0/src/alarmitemwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'alarmitemwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_alarmItemWidget_t {
    QByteArrayData data[9];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_alarmItemWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_alarmItemWidget_t qt_meta_stringdata_alarmItemWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "alarmItemWidget"
QT_MOC_LITERAL(1, 16, 16), // "ringAlarmOccured"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 51, 4), // "item"
QT_MOC_LITERAL(5, 56, 12), // "editOccurred"
QT_MOC_LITERAL(6, 69, 14), // "removeOccurred"
QT_MOC_LITERAL(7, 84, 13), // "enableToggled"
QT_MOC_LITERAL(8, 98, 5) // "state"

    },
    "alarmItemWidget\0ringAlarmOccured\0\0"
    "QListWidgetItem*\0item\0editOccurred\0"
    "removeOccurred\0enableToggled\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_alarmItemWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       7,    2,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 3,    8,    4,

       0        // eod
};

void alarmItemWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<alarmItemWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ringAlarmOccured((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->editOccurred((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->removeOccurred((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->enableToggled((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (alarmItemWidget::*)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&alarmItemWidget::ringAlarmOccured)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (alarmItemWidget::*)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&alarmItemWidget::editOccurred)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (alarmItemWidget::*)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&alarmItemWidget::removeOccurred)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (alarmItemWidget::*)(bool , QListWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&alarmItemWidget::enableToggled)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject alarmItemWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractScheduleItem::staticMetaObject>(),
    qt_meta_stringdata_alarmItemWidget.data,
    qt_meta_data_alarmItemWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *alarmItemWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *alarmItemWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_alarmItemWidget.stringdata0))
        return static_cast<void*>(this);
    return AbstractScheduleItem::qt_metacast(_clname);
}

int alarmItemWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractScheduleItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void alarmItemWidget::ringAlarmOccured(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void alarmItemWidget::editOccurred(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void alarmItemWidget::removeOccurred(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void alarmItemWidget::enableToggled(bool _t1, QListWidgetItem * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
