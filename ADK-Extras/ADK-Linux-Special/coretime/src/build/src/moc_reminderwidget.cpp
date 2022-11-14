/****************************************************************************
** Meta object code from reading C++ file 'reminderwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../coretime-v4.4.0/src/reminderwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reminderwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_reminderWidget_t {
    QByteArrayData data[15];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_reminderWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_reminderWidget_t qt_meta_stringdata_reminderWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "reminderWidget"
QT_MOC_LITERAL(1, 15, 13), // "reminderAdded"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 1), // "d"
QT_MOC_LITERAL(4, 32, 14), // "CalendarEvent&"
QT_MOC_LITERAL(5, 47, 5), // "event"
QT_MOC_LITERAL(6, 53, 14), // "reminderEdited"
QT_MOC_LITERAL(7, 68, 4), // "oldD"
QT_MOC_LITERAL(8, 73, 4), // "newD"
QT_MOC_LITERAL(9, 78, 15), // "reminderDeleted"
QT_MOC_LITERAL(10, 94, 15), // "on_done_clicked"
QT_MOC_LITERAL(11, 110, 17), // "on_cancel_clicked"
QT_MOC_LITERAL(12, 128, 30), // "on_browseReminderSound_clicked"
QT_MOC_LITERAL(13, 159, 21), // "on_r_specific_toggled"
QT_MOC_LITERAL(14, 181, 7) // "checked"

    },
    "reminderWidget\0reminderAdded\0\0d\0"
    "CalendarEvent&\0event\0reminderEdited\0"
    "oldD\0newD\0reminderDeleted\0on_done_clicked\0"
    "on_cancel_clicked\0on_browseReminderSound_clicked\0"
    "on_r_specific_toggled\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_reminderWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       6,    3,   54,    2, 0x06 /* Public */,
       9,    1,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   64,    2, 0x08 /* Private */,
      11,    0,   65,    2, 0x08 /* Private */,
      12,    0,   66,    2, 0x08 /* Private */,
      13,    1,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDate, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QDate, QMetaType::QDate, 0x80000000 | 4,    7,    8,    5,
    QMetaType::Void, QMetaType::QDate,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,

       0        // eod
};

void reminderWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<reminderWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->reminderAdded((*reinterpret_cast< QDate(*)>(_a[1])),(*reinterpret_cast< CalendarEvent(*)>(_a[2]))); break;
        case 1: _t->reminderEdited((*reinterpret_cast< QDate(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2])),(*reinterpret_cast< CalendarEvent(*)>(_a[3]))); break;
        case 2: _t->reminderDeleted((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 3: _t->on_done_clicked(); break;
        case 4: _t->on_cancel_clicked(); break;
        case 5: _t->on_browseReminderSound_clicked(); break;
        case 6: _t->on_r_specific_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (reminderWidget::*)(QDate , CalendarEvent & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&reminderWidget::reminderAdded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (reminderWidget::*)(QDate , QDate , CalendarEvent & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&reminderWidget::reminderEdited)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (reminderWidget::*)(QDate );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&reminderWidget::reminderDeleted)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject reminderWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_reminderWidget.data,
    qt_meta_data_reminderWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *reminderWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *reminderWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_reminderWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int reminderWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void reminderWidget::reminderAdded(QDate _t1, CalendarEvent & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void reminderWidget::reminderEdited(QDate _t1, QDate _t2, CalendarEvent & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void reminderWidget::reminderDeleted(QDate _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
