/****************************************************************************
** Meta object code from reading C++ file 'splinefit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "splinefit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'splinefit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SplineFit_t {
    QByteArrayData data[18];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SplineFit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SplineFit_t qt_meta_stringdata_SplineFit = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SplineFit"
QT_MOC_LITERAL(1, 10, 6), // "seData"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 3), // "str"
QT_MOC_LITERAL(4, 22, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 44, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 68, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(7, 88, 16), // "showPointToolTip"
QT_MOC_LITERAL(8, 105, 12), // "QMouseEvent*"
QT_MOC_LITERAL(9, 118, 5), // "event"
QT_MOC_LITERAL(10, 124, 11), // "writeCoords"
QT_MOC_LITERAL(11, 136, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(12, 160, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(13, 184, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(14, 208, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(15, 232, 21), // "on_checkBox_5_clicked"
QT_MOC_LITERAL(16, 254, 21), // "on_checkBox_4_clicked"
QT_MOC_LITERAL(17, 276, 21) // "on_checkBox_6_clicked"

    },
    "SplineFit\0seData\0\0str\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_checkBox_clicked\0"
    "showPointToolTip\0QMouseEvent*\0event\0"
    "writeCoords\0on_pushButton_3_clicked\0"
    "on_pushButton_5_clicked\0on_pushButton_4_clicked\0"
    "on_pushButton_6_clicked\0on_checkBox_5_clicked\0"
    "on_checkBox_4_clicked\0on_checkBox_6_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SplineFit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       4,    0,   82,    2, 0x08 /* Private */,
       5,    0,   83,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    1,   85,    2, 0x08 /* Private */,
      10,    1,   88,    2, 0x08 /* Private */,
      11,    0,   91,    2, 0x08 /* Private */,
      12,    0,   92,    2, 0x08 /* Private */,
      13,    0,   93,    2, 0x08 /* Private */,
      14,    0,   94,    2, 0x08 /* Private */,
      15,    0,   95,    2, 0x08 /* Private */,
      16,    0,   96,    2, 0x08 /* Private */,
      17,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SplineFit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SplineFit *_t = static_cast<SplineFit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->seData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_checkBox_clicked(); break;
        case 4: _t->showPointToolTip((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->writeCoords((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_pushButton_5_clicked(); break;
        case 8: _t->on_pushButton_4_clicked(); break;
        case 9: _t->on_pushButton_6_clicked(); break;
        case 10: _t->on_checkBox_5_clicked(); break;
        case 11: _t->on_checkBox_4_clicked(); break;
        case 12: _t->on_checkBox_6_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject SplineFit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SplineFit.data,
      qt_meta_data_SplineFit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SplineFit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SplineFit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SplineFit.stringdata0))
        return static_cast<void*>(const_cast< SplineFit*>(this));
    return QDialog::qt_metacast(_clname);
}

int SplineFit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
