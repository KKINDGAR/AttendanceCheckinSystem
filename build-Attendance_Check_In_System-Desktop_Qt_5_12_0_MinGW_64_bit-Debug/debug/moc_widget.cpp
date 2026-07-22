/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Attendance_Check_In_System/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[17];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 10), // "cardParsed"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 10), // "cardNumber"
QT_MOC_LITERAL(4, 30, 13), // "rawSerialData"
QT_MOC_LITERAL(5, 44, 7), // "rawText"
QT_MOC_LITERAL(6, 52, 18), // "cardParsedToModify"
QT_MOC_LITERAL(7, 71, 19), // "cardParseAttendance"
QT_MOC_LITERAL(8, 91, 17), // "cardParseRecharge"
QT_MOC_LITERAL(9, 109, 19), // "cardParseRegistPage"
QT_MOC_LITERAL(10, 129, 18), // "cardParseLoginPage"
QT_MOC_LITERAL(11, 148, 11), // "onClockTick"
QT_MOC_LITERAL(12, 160, 13), // "onCardScanned"
QT_MOC_LITERAL(13, 174, 4), // "card"
QT_MOC_LITERAL(14, 179, 27), // "on_adminEntryButton_clicked"
QT_MOC_LITERAL(15, 207, 17), // "onSerialReadyRead"
QT_MOC_LITERAL(16, 225, 13) // "onCardTimeout"

    },
    "Widget\0cardParsed\0\0cardNumber\0"
    "rawSerialData\0rawText\0cardParsedToModify\0"
    "cardParseAttendance\0cardParseRecharge\0"
    "cardParseRegistPage\0cardParseLoginPage\0"
    "onClockTick\0onCardScanned\0card\0"
    "on_adminEntryButton_clicked\0"
    "onSerialReadyRead\0onCardTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       6,    1,   80,    2, 0x06 /* Public */,
       7,    1,   83,    2, 0x06 /* Public */,
       8,    1,   86,    2, 0x06 /* Public */,
       9,    1,   89,    2, 0x06 /* Public */,
      10,    1,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   95,    2, 0x08 /* Private */,
      12,    1,   96,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cardParsed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->rawSerialData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->cardParsedToModify((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->cardParseAttendance((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->cardParseRecharge((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->cardParseRegistPage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->cardParseLoginPage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->onClockTick(); break;
        case 8: _t->onCardScanned((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_adminEntryButton_clicked(); break;
        case 10: _t->onSerialReadyRead(); break;
        case 11: _t->onCardTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::cardParsed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Widget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::rawSerialData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Widget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::cardParsedToModify)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Widget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::cardParseAttendance)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Widget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::cardParseRecharge)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Widget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::cardParseRegistPage)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Widget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::cardParseLoginPage)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Widget::cardParsed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget::rawSerialData(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Widget::cardParsedToModify(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Widget::cardParseAttendance(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Widget::cardParseRecharge(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Widget::cardParseRegistPage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Widget::cardParseLoginPage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
