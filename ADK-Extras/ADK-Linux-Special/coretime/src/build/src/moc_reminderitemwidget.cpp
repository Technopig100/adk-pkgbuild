/****************************************************************************
** Meta object code from reading C++ file 'reminderitemwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../coretime-v4.4.0/src/reminderitemwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reminderitemwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_reminderItemWidget_t {
    QByteArrayData data[9];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_reminderItemWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_reminderItemWidget_t qt_meta_stringdata_reminderItemWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "reminderItemWidget"
QT_MOC_LITERAL(1, 19, 20), // "ringReminderOccurred"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 58, 4), // "item"
QT_MOC_LITERAL(5, 63, 12), // "editOccurred"
QT_MOC_LITERAL(6, 76, 14), // "removeOccurred"
QT_MOC_LITERAL(7, 91, 13), // "enableToggled"
QT_MOC_LITERAL(8, 105, 5) // "state"

    },
    "reminderItemWidget\0ringReminderOccurred\0"
    "\0QListWidgetItem*\0item\0editOccurred\0"
    "removeOccurred\0enableToggled\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_reminderItemWidget[] = {

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

void reminderItemWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<reminderItemWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ringReminderOccurred((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->editOccurred((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->removeOccurred((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->enableToggled((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (reminderItemWidget::*)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&reminderItemWidget::ringReminderOccurred)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (reminderItemWidget::*)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&reminderItemWidget::editOccurred)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (reminderItemWidget::*)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&reminderItemWidget::removeOccurred)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (reminderItemWidget::*)(bool , QListWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&reminderItemWidget::enableToggled)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject reminderItemWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractScheduleItem::staticMetaObject>(),
    qt_meta_stringdata_reminderItemWidget.data,
    qt_meta_data_reminderItemWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *reminderItemWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *reminderItemWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_reminderItemWidget.stringdata0))
        return static_cast<void*>(this);
    return AbstractScheduleItem::qt_metacast(_clname);
}

int reminderItemWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void reminderItemWidget::ringReminderOccurred(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void reminderItemWidget::editOccurred(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void reminderItemWidget::removeOccurred(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void reminderItemWidget::enableToggled(bool _t1, QListWidgetItem * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
