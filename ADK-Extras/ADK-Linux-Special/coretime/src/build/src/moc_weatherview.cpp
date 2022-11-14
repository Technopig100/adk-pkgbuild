/****************************************************************************
** Meta object code from reading C++ file 'weatherview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../coretime-v4.4.0/src/weatherview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weatherview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_weatherView_t {
    QByteArrayData data[19];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_weatherView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_weatherView_t qt_meta_stringdata_weatherView = {
    {
QT_MOC_LITERAL(0, 0, 11), // "weatherView"
QT_MOC_LITERAL(1, 12, 18), // "updateTodayWeather"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "WeatherData"
QT_MOC_LITERAL(4, 44, 2), // "wd"
QT_MOC_LITERAL(5, 47, 13), // "loadLocations"
QT_MOC_LITERAL(6, 61, 9), // "Locations"
QT_MOC_LITERAL(7, 71, 4), // "locs"
QT_MOC_LITERAL(8, 76, 23), // "on_selectLocBtn_clicked"
QT_MOC_LITERAL(9, 100, 17), // "on_search_clicked"
QT_MOC_LITERAL(10, 118, 17), // "on_select_clicked"
QT_MOC_LITERAL(11, 136, 26), // "on_searchStr_returnPressed"
QT_MOC_LITERAL(12, 163, 27), // "on_result_itemDoubleClicked"
QT_MOC_LITERAL(13, 191, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(14, 209, 4), // "item"
QT_MOC_LITERAL(15, 214, 18), // "on_editLoc_clicked"
QT_MOC_LITERAL(16, 233, 15), // "on_back_clicked"
QT_MOC_LITERAL(17, 249, 25), // "on_mainWid_currentChanged"
QT_MOC_LITERAL(18, 275, 5) // "index"

    },
    "weatherView\0updateTodayWeather\0\0"
    "WeatherData\0wd\0loadLocations\0Locations\0"
    "locs\0on_selectLocBtn_clicked\0"
    "on_search_clicked\0on_select_clicked\0"
    "on_searchStr_returnPressed\0"
    "on_result_itemDoubleClicked\0"
    "QTableWidgetItem*\0item\0on_editLoc_clicked\0"
    "on_back_clicked\0on_mainWid_currentChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_weatherView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   67,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,
      12,    1,   74,    2, 0x08 /* Private */,
      15,    0,   77,    2, 0x08 /* Private */,
      16,    0,   78,    2, 0x08 /* Private */,
      17,    1,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void weatherView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<weatherView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateTodayWeather((*reinterpret_cast< WeatherData(*)>(_a[1]))); break;
        case 1: _t->loadLocations((*reinterpret_cast< Locations(*)>(_a[1]))); break;
        case 2: _t->on_selectLocBtn_clicked(); break;
        case 3: _t->on_search_clicked(); break;
        case 4: _t->on_select_clicked(); break;
        case 5: _t->on_searchStr_returnPressed(); break;
        case 6: _t->on_result_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->on_editLoc_clicked(); break;
        case 8: _t->on_back_clicked(); break;
        case 9: _t->on_mainWid_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (weatherView::*)(WeatherData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&weatherView::updateTodayWeather)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject weatherView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_weatherView.data,
    qt_meta_data_weatherView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *weatherView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *weatherView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_weatherView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int weatherView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void weatherView::updateTodayWeather(WeatherData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_WeatherItem_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeatherItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeatherItem_t qt_meta_stringdata_WeatherItem = {
    {
QT_MOC_LITERAL(0, 0, 11) // "WeatherItem"

    },
    "WeatherItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void WeatherItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject WeatherItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_WeatherItem.data,
    qt_meta_data_WeatherItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WeatherItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeatherItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherItem.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WeatherItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
