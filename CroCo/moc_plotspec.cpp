/****************************************************************************
** Meta object code from reading C++ file 'plotspec.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "plotspec.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plotspec.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlotSpec_t {
    QByteArrayData data[21];
    char stringdata0[322];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlotSpec_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlotSpec_t qt_meta_stringdata_PlotSpec = {
    {
QT_MOC_LITERAL(0, 0, 8), // "PlotSpec"
QT_MOC_LITERAL(1, 9, 6), // "seData"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 3), // "str"
QT_MOC_LITERAL(4, 21, 4), // "str2"
QT_MOC_LITERAL(5, 26, 4), // "str3"
QT_MOC_LITERAL(6, 31, 4), // "str4"
QT_MOC_LITERAL(7, 36, 4), // "str5"
QT_MOC_LITERAL(8, 41, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(9, 65, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(10, 89, 29), // "on_lineEdit_2_editingFinished"
QT_MOC_LITERAL(11, 119, 29), // "on_lineEdit_3_editingFinished"
QT_MOC_LITERAL(12, 149, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(13, 173, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(14, 193, 21), // "on_checkBox_2_clicked"
QT_MOC_LITERAL(15, 215, 21), // "on_checkBox_3_clicked"
QT_MOC_LITERAL(16, 237, 24), // "on_lineEdit_5_textEdited"
QT_MOC_LITERAL(17, 262, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(18, 286, 16), // "showPointToolTip"
QT_MOC_LITERAL(19, 303, 12), // "QMouseEvent*"
QT_MOC_LITERAL(20, 316, 5) // "event"

    },
    "PlotSpec\0seData\0\0str\0str2\0str3\0str4\0"
    "str5\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked\0"
    "on_lineEdit_2_editingFinished\0"
    "on_lineEdit_3_editingFinished\0"
    "on_pushButton_4_clicked\0on_checkBox_clicked\0"
    "on_checkBox_2_clicked\0on_checkBox_3_clicked\0"
    "on_lineEdit_5_textEdited\0"
    "on_spinBox_valueChanged\0showPointToolTip\0"
    "QMouseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlotSpec[] = {

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
       1,    5,   74,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,
      15,    0,   92,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,
      17,    0,   94,    2, 0x08 /* Private */,
      18,    1,   95,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

void PlotSpec::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlotSpec *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->seData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_lineEdit_2_editingFinished(); break;
        case 4: _t->on_lineEdit_3_editingFinished(); break;
        case 5: _t->on_pushButton_4_clicked(); break;
        case 6: _t->on_checkBox_clicked(); break;
        case 7: _t->on_checkBox_2_clicked(); break;
        case 8: _t->on_checkBox_3_clicked(); break;
        case 9: _t->on_lineEdit_5_textEdited(); break;
        case 10: _t->on_spinBox_valueChanged(); break;
        case 11: _t->showPointToolTip((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlotSpec::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_PlotSpec.data,
    qt_meta_data_PlotSpec,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PlotSpec::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlotSpec::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlotSpec.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int PlotSpec::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
