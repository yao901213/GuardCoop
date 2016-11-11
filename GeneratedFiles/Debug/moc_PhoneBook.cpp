/****************************************************************************
** Meta object code from reading C++ file 'PhoneBook.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PhoneBook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PhoneBook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PhoneBook_t {
    QByteArrayData data[8];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PhoneBook_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PhoneBook_t qt_meta_stringdata_PhoneBook = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PhoneBook"
QT_MOC_LITERAL(1, 10, 14), // "ClickAddButton"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "ClickSearchButton"
QT_MOC_LITERAL(4, 44, 14), // "ClickModButton"
QT_MOC_LITERAL(5, 59, 14), // "ClickDelButton"
QT_MOC_LITERAL(6, 74, 15), // "UpdatePhoneBook"
QT_MOC_LITERAL(7, 90, 13) // "ClearLineEdit"

    },
    "PhoneBook\0ClickAddButton\0\0ClickSearchButton\0"
    "ClickModButton\0ClickDelButton\0"
    "UpdatePhoneBook\0ClearLineEdit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PhoneBook[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PhoneBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PhoneBook *_t = static_cast<PhoneBook *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ClickAddButton(); break;
        case 1: _t->ClickSearchButton(); break;
        case 2: _t->ClickModButton(); break;
        case 3: _t->ClickDelButton(); break;
        case 4: _t->UpdatePhoneBook(); break;
        case 5: _t->ClearLineEdit(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PhoneBook::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PhoneBook.data,
      qt_meta_data_PhoneBook,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PhoneBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PhoneBook::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PhoneBook.stringdata0))
        return static_cast<void*>(const_cast< PhoneBook*>(this));
    return QWidget::qt_metacast(_clname);
}

int PhoneBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
