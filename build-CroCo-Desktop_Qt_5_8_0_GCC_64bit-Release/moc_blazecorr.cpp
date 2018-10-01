/****************************************************************************
** Meta object code from reading C++ file 'blazecorr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CroCo/blazecorr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blazecorr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BlazeCorr_t {
    QByteArrayData data[13];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlazeCorr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlazeCorr_t qt_meta_stringdata_BlazeCorr = {
    {
QT_MOC_LITERAL(0, 0, 9), // "BlazeCorr"
QT_MOC_LITERAL(1, 10, 6), // "seData"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 3), // "str"
QT_MOC_LITERAL(4, 22, 13), // "BlazeFunction"
QT_MOC_LITERAL(5, 36, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 58, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(7, 82, 31), // "on_doubleSpinBox_8_valueChanged"
QT_MOC_LITERAL(8, 114, 31), // "on_doubleSpinBox_9_valueChanged"
QT_MOC_LITERAL(9, 146, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(10, 170, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(11, 194, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(12, 218, 23) // "on_pushButton_6_clicked"

    },
    "BlazeCorr\0seData\0\0str\0BlazeFunction\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_doubleSpinBox_8_valueChanged\0"
    "on_doubleSpinBox_9_valueChanged\0"
    "on_pushButton_3_clicked\0on_pushButton_5_clicked\0"
    "on_pushButton_4_clicked\0on_pushButton_6_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlazeCorr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       4,    0,   67,    2, 0x08 /* Private */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Double,
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

void BlazeCorr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BlazeCorr *_t = static_cast<BlazeCorr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->seData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: { double _r = _t->BlazeFunction();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_doubleSpinBox_8_valueChanged(); break;
        case 5: _t->on_doubleSpinBox_9_valueChanged(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_pushButton_5_clicked(); break;
        case 8: _t->on_pushButton_4_clicked(); break;
        case 9: _t->on_pushButton_6_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject BlazeCorr::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BlazeCorr.data,
      qt_meta_data_BlazeCorr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BlazeCorr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlazeCorr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BlazeCorr.stringdata0))
        return static_cast<void*>(const_cast< BlazeCorr*>(this));
    return QDialog::qt_metacast(_clname);
}

int BlazeCorr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
