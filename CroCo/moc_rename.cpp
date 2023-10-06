/****************************************************************************
** Meta object code from reading C++ file 'rename.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "rename.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rename.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Rename_t {
    QByteArrayData data[16];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Rename_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Rename_t qt_meta_stringdata_Rename = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Rename"
QT_MOC_LITERAL(1, 7, 6), // "seData"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 3), // "str"
QT_MOC_LITERAL(4, 19, 4), // "str2"
QT_MOC_LITERAL(5, 24, 4), // "str3"
QT_MOC_LITERAL(6, 29, 4), // "str4"
QT_MOC_LITERAL(7, 34, 4), // "str5"
QT_MOC_LITERAL(8, 39, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 61, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(10, 85, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(11, 109, 25), // "on_spinBox_5_valueChanged"
QT_MOC_LITERAL(12, 135, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(13, 159, 21), // "on_checkBox_3_clicked"
QT_MOC_LITERAL(14, 181, 21), // "on_checkBox_4_clicked"
QT_MOC_LITERAL(15, 203, 23) // "on_pushButton_5_clicked"

    },
    "Rename\0seData\0\0str\0str2\0str3\0str4\0"
    "str5\0on_pushButton_clicked\0"
    "on_spinBox_valueChanged\0on_pushButton_2_clicked\0"
    "on_spinBox_5_valueChanged\0"
    "on_pushButton_4_clicked\0on_checkBox_3_clicked\0"
    "on_checkBox_4_clicked\0on_pushButton_5_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Rename[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    5,   59,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,
      12,    0,   74,    2, 0x08 /* Private */,
      13,    0,   75,    2, 0x08 /* Private */,
      14,    0,   76,    2, 0x08 /* Private */,
      15,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Rename::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Rename *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->seData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_spinBox_valueChanged(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_spinBox_5_valueChanged(); break;
        case 5: _t->on_pushButton_4_clicked(); break;
        case 6: _t->on_checkBox_3_clicked(); break;
        case 7: _t->on_checkBox_4_clicked(); break;
        case 8: _t->on_pushButton_5_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Rename::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Rename.data,
    qt_meta_data_Rename,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Rename::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Rename::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Rename.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Rename::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
