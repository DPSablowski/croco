/****************************************************************************
** Meta object code from reading C++ file 'rvcalc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CroCo_git/croco/croco/rvcalc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rvcalc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RVCalc_t {
    QByteArrayData data[14];
    char stringdata0[304];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RVCalc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RVCalc_t qt_meta_stringdata_RVCalc = {
    {
QT_MOC_LITERAL(0, 0, 6), // "RVCalc"
QT_MOC_LITERAL(1, 7, 31), // "on_doubleSpinBox_9_valueChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 64, 25), // "on_lineEdit_2_textChanged"
QT_MOC_LITERAL(5, 90, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(6, 114, 21), // "on_checkBox_3_clicked"
QT_MOC_LITERAL(7, 136, 21), // "on_checkBox_4_clicked"
QT_MOC_LITERAL(8, 158, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(9, 182, 24), // "on_lineEdit_4_textEdited"
QT_MOC_LITERAL(10, 207, 24), // "on_lineEdit_5_textEdited"
QT_MOC_LITERAL(11, 232, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(12, 256, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(13, 280, 23) // "on_pushButton_6_clicked"

    },
    "RVCalc\0on_doubleSpinBox_9_valueChanged\0"
    "\0on_pushButton_2_clicked\0"
    "on_lineEdit_2_textChanged\0"
    "on_spinBox_valueChanged\0on_checkBox_3_clicked\0"
    "on_checkBox_4_clicked\0on_pushButton_3_clicked\0"
    "on_lineEdit_4_textEdited\0"
    "on_lineEdit_5_textEdited\0"
    "on_pushButton_4_clicked\0on_pushButton_5_clicked\0"
    "on_pushButton_6_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RVCalc[] = {

 // content:
       7,       // revision
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
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void RVCalc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RVCalc *_t = static_cast<RVCalc *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_doubleSpinBox_9_valueChanged(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_lineEdit_2_textChanged(); break;
        case 3: _t->on_spinBox_valueChanged(); break;
        case 4: _t->on_checkBox_3_clicked(); break;
        case 5: _t->on_checkBox_4_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_lineEdit_4_textEdited(); break;
        case 8: _t->on_lineEdit_5_textEdited(); break;
        case 9: _t->on_pushButton_4_clicked(); break;
        case 10: _t->on_pushButton_5_clicked(); break;
        case 11: _t->on_pushButton_6_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject RVCalc::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RVCalc.data,
      qt_meta_data_RVCalc,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RVCalc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RVCalc::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RVCalc.stringdata0))
        return static_cast<void*>(const_cast< RVCalc*>(this));
    return QDialog::qt_metacast(_clname);
}

int RVCalc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE