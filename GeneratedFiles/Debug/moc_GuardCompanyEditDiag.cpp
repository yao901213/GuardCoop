/****************************************************************************
** Meta object code from reading C++ file 'GuardCompanyEditDiag.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GuardCompanyEditDiag.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GuardCompanyEditDiag.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GuardCompanyEditDiag_t {
    QByteArrayData data[7];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GuardCompanyEditDiag_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GuardCompanyEditDiag_t qt_meta_stringdata_GuardCompanyEditDiag = {
    {
QT_MOC_LITERAL(0, 0, 20), // "GuardCompanyEditDiag"
QT_MOC_LITERAL(1, 21, 16), // "ClickOkButtonAdd"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 16), // "ClickOkButtonMod"
QT_MOC_LITERAL(4, 56, 12), // "IsInputValid"
QT_MOC_LITERAL(5, 69, 18), // "IsCompanyNameExist"
QT_MOC_LITERAL(6, 88, 17) // "GetCompanyNameNum"

    },
    "GuardCompanyEditDiag\0ClickOkButtonAdd\0"
    "\0ClickOkButtonMod\0IsInputValid\0"
    "IsCompanyNameExist\0GetCompanyNameNum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GuardCompanyEditDiag[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Int,

       0        // eod
};

void GuardCompanyEditDiag::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GuardCompanyEditDiag *_t = static_cast<GuardCompanyEditDiag *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ClickOkButtonAdd(); break;
        case 1: _t->ClickOkButtonMod(); break;
        case 2: { bool _r = _t->IsInputValid();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->IsCompanyNameExist();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->GetCompanyNameNum();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject GuardCompanyEditDiag::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GuardCompanyEditDiag.data,
      qt_meta_data_GuardCompanyEditDiag,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GuardCompanyEditDiag::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GuardCompanyEditDiag::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GuardCompanyEditDiag.stringdata0))
        return static_cast<void*>(const_cast< GuardCompanyEditDiag*>(this));
    return QDialog::qt_metacast(_clname);
}

int GuardCompanyEditDiag::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
