/****************************************************************************
** Meta object code from reading C++ file 'vald3.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vald3.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vald3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VALD3_t {
    QByteArrayData data[15];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VALD3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VALD3_t qt_meta_stringdata_VALD3 = {
    {
QT_MOC_LITERAL(0, 0, 5), // "VALD3"
QT_MOC_LITERAL(1, 6, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 55, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(5, 79, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(6, 103, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(7, 127, 21), // "on_checkBox_5_clicked"
QT_MOC_LITERAL(8, 149, 20), // "computeMESAResiduumA"
QT_MOC_LITERAL(9, 170, 20), // "computeMESAResiduumB"
QT_MOC_LITERAL(10, 191, 12), // "MESAResiduum"
QT_MOC_LITERAL(11, 204, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(12, 228, 10), // "saveTracks"
QT_MOC_LITERAL(13, 239, 6), // "seData"
QT_MOC_LITERAL(14, 246, 3) // "str"

    },
    "VALD3\0on_pushButton_3_clicked\0\0"
    "on_pushButton_2_clicked\0on_pushButton_4_clicked\0"
    "on_pushButton_5_clicked\0on_spinBox_valueChanged\0"
    "on_checkBox_5_clicked\0computeMESAResiduumA\0"
    "computeMESAResiduumB\0MESAResiduum\0"
    "on_pushButton_7_clicked\0saveTracks\0"
    "seData\0str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VALD3[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    1,   85,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Double,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,

       0        // eod
};

void VALD3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VALD3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_3_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_4_clicked(); break;
        case 3: _t->on_pushButton_5_clicked(); break;
        case 4: _t->on_spinBox_valueChanged(); break;
        case 5: _t->on_checkBox_5_clicked(); break;
        case 6: _t->computeMESAResiduumA(); break;
        case 7: _t->computeMESAResiduumB(); break;
        case 8: { double _r = _t->MESAResiduum();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->on_pushButton_7_clicked(); break;
        case 10: _t->saveTracks(); break;
        case 11: _t->seData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VALD3::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_VALD3.data,
    qt_meta_data_VALD3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VALD3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VALD3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VALD3.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int VALD3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
