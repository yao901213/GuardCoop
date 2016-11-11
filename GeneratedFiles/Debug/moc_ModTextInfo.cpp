/****************************************************************************
** Meta object code from reading C++ file 'ModTextInfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ModTextInfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModTextInfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ModTextInfoDiag_t {
    QByteArrayData data[3];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModTextInfoDiag_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModTextInfoDiag_t qt_meta_stringdata_ModTextInfoDiag = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ModTextInfoDiag"
QT_MOC_LITERAL(1, 16, 17), // "SubmitModTextInfo"
QT_MOC_LITERAL(2, 34, 0) // ""

    },
    "ModTextInfoDiag\0SubmitModTextInfo\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModTextInfoDiag[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ModTextInfoDiag::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModTextInfoDiag *_t = static_cast<ModTextInfoDiag *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SubmitModTextInfo(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ModTextInfoDiag::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ModTextInfoDiag.data,
      qt_meta_data_ModTextInfoDiag,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ModTextInfoDiag::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModTextInfoDiag::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ModTextInfoDiag.stringdata0))
        return static_cast<void*>(const_cast< ModTextInfoDiag*>(this));
    return QDialog::qt_metacast(_clname);
}

int ModTextInfoDiag::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
