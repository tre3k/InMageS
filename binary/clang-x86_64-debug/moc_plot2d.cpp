/****************************************************************************
** Meta object code from reading C++ file 'plot2d.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/widgets/plots/plot2d.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plot2d.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Plot2D_t {
    QByteArrayData data[12];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Plot2D_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Plot2D_t qt_meta_stringdata_Plot2D = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Plot2D"
QT_MOC_LITERAL(1, 7, 8), // "logScale"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 5), // "state"
QT_MOC_LITERAL(4, 23, 4), // "hold"
QT_MOC_LITERAL(5, 28, 12), // "setHoldRange"
QT_MOC_LITERAL(6, 41, 11), // "setAxisUnit"
QT_MOC_LITERAL(7, 53, 11), // "rescaleAxis"
QT_MOC_LITERAL(8, 65, 15), // "changeDataRange"
QT_MOC_LITERAL(9, 81, 8), // "QCPRange"
QT_MOC_LITERAL(10, 90, 19), // "setCurrentUnitIndex"
QT_MOC_LITERAL(11, 110, 5) // "index"

    },
    "Plot2D\0logScale\0\0state\0hold\0setHoldRange\0"
    "setAxisUnit\0rescaleAxis\0changeDataRange\0"
    "QCPRange\0setCurrentUnitIndex\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Plot2D[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    1,   52,    2, 0x0a /* Public */,
       5,    0,   55,    2, 0x0a /* Public */,
       6,    1,   56,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    1,   60,    2, 0x0a /* Public */,
      10,    1,   63,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void Plot2D::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Plot2D *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->logScale((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->hold((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setHoldRange(); break;
        case 3: _t->setAxisUnit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->rescaleAxis(); break;
        case 5: _t->changeDataRange((*reinterpret_cast< QCPRange(*)>(_a[1]))); break;
        case 6: _t->setCurrentUnitIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Plot2D::staticMetaObject = { {
    &BaseWidget::staticMetaObject,
    qt_meta_stringdata_Plot2D.data,
    qt_meta_data_Plot2D,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Plot2D::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Plot2D::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Plot2D.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int Plot2D::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
