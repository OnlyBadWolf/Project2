/****************************************************************************
** Meta object code from reading C++ file 'maininterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "maininterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maininterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainInterface_t {
    QByteArrayData data[14];
    char stringdata0[353];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainInterface_t qt_meta_stringdata_MainInterface = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MainInterface"
QT_MOC_LITERAL(1, 14, 31), // "on_SilverProductDetails_clicked"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 29), // "on_GoldProductDetails_clicked"
QT_MOC_LITERAL(4, 77, 33), // "on_PlatinumProductDetails_cli..."
QT_MOC_LITERAL(5, 111, 30), // "on_Platinum_BackToHome_clicked"
QT_MOC_LITERAL(6, 142, 28), // "on_Gold_BackToHome_2_clicked"
QT_MOC_LITERAL(7, 171, 28), // "on_Silver_BackToHome_clicked"
QT_MOC_LITERAL(8, 200, 28), // "on_WriteReviewButton_clicked"
QT_MOC_LITERAL(9, 229, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(10, 251, 21), // "on_buttonBox_rejected"
QT_MOC_LITERAL(11, 273, 23), // "on_BuyNowButton_clicked"
QT_MOC_LITERAL(12, 297, 21), // "on_BackButton_clicked"
QT_MOC_LITERAL(13, 319, 33) // "on_officiallyBuyNowButton_cli..."

    },
    "MainInterface\0on_SilverProductDetails_clicked\0"
    "\0on_GoldProductDetails_clicked\0"
    "on_PlatinumProductDetails_clicked\0"
    "on_Platinum_BackToHome_clicked\0"
    "on_Gold_BackToHome_2_clicked\0"
    "on_Silver_BackToHome_clicked\0"
    "on_WriteReviewButton_clicked\0"
    "on_buttonBox_accepted\0on_buttonBox_rejected\0"
    "on_BuyNowButton_clicked\0on_BackButton_clicked\0"
    "on_officiallyBuyNowButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainInterface[] = {

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

void MainInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainInterface *_t = static_cast<MainInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_SilverProductDetails_clicked(); break;
        case 1: _t->on_GoldProductDetails_clicked(); break;
        case 2: _t->on_PlatinumProductDetails_clicked(); break;
        case 3: _t->on_Platinum_BackToHome_clicked(); break;
        case 4: _t->on_Gold_BackToHome_2_clicked(); break;
        case 5: _t->on_Silver_BackToHome_clicked(); break;
        case 6: _t->on_WriteReviewButton_clicked(); break;
        case 7: _t->on_buttonBox_accepted(); break;
        case 8: _t->on_buttonBox_rejected(); break;
        case 9: _t->on_BuyNowButton_clicked(); break;
        case 10: _t->on_BackButton_clicked(); break;
        case 11: _t->on_officiallyBuyNowButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainInterface::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainInterface.data,
      qt_meta_data_MainInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainInterface.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
