/****************************************************************************
** Meta object code from reading C++ file 'averagewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/widgets/averagewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'averagewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AverageWidget_t {
    QByteArrayData data[23];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AverageWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AverageWidget_t qt_meta_stringdata_AverageWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AverageWidget"
QT_MOC_LITERAL(1, 14, 16), // "addAverageThread"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "AverageThread*"
QT_MOC_LITERAL(4, 47, 14), // "average_thread"
QT_MOC_LITERAL(5, 62, 18), // "setUIFromAveraging"
QT_MOC_LITERAL(6, 81, 5), // "index"
QT_MOC_LITERAL(7, 87, 18), // "setAveragingFromUI"
QT_MOC_LITERAL(8, 106, 14), // "setNeutronData"
QT_MOC_LITERAL(9, 121, 12), // "NeutronData*"
QT_MOC_LITERAL(10, 134, 12), // "neutron_data"
QT_MOC_LITERAL(11, 147, 9), // "setPlot1D"
QT_MOC_LITERAL(12, 157, 7), // "Plot1D*"
QT_MOC_LITERAL(13, 165, 6), // "plot1d"
QT_MOC_LITERAL(14, 172, 9), // "setPlot2D"
QT_MOC_LITERAL(15, 182, 7), // "Plot2D*"
QT_MOC_LITERAL(16, 190, 6), // "plot2d"
QT_MOC_LITERAL(17, 197, 14), // "pressButtonSet"
QT_MOC_LITERAL(18, 212, 18), // "pressButtonAverage"
QT_MOC_LITERAL(19, 231, 14), // "pressButtonAdd"
QT_MOC_LITERAL(20, 246, 13), // "pressButtonRm"
QT_MOC_LITERAL(21, 260, 8), // "plotData"
QT_MOC_LITERAL(22, 269, 3) // "num"

    },
    "AverageWidget\0addAverageThread\0\0"
    "AverageThread*\0average_thread\0"
    "setUIFromAveraging\0index\0setAveragingFromUI\0"
    "setNeutronData\0NeutronData*\0neutron_data\0"
    "setPlot1D\0Plot1D*\0plot1d\0setPlot2D\0"
    "Plot2D*\0plot2d\0pressButtonSet\0"
    "pressButtonAverage\0pressButtonAdd\0"
    "pressButtonRm\0plotData\0num"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AverageWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a /* Public */,
       5,    1,   72,    2, 0x0a /* Public */,
       7,    0,   75,    2, 0x0a /* Public */,
       8,    1,   76,    2, 0x0a /* Public */,
      11,    1,   79,    2, 0x0a /* Public */,
      14,    1,   82,    2, 0x0a /* Public */,
      17,    0,   85,    2, 0x0a /* Public */,
      18,    0,   86,    2, 0x0a /* Public */,
      19,    0,   87,    2, 0x0a /* Public */,
      20,    0,   88,    2, 0x0a /* Public */,
      21,    1,   89,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,

       0        // eod
};

void AverageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AverageWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addAverageThread((*reinterpret_cast< AverageThread*(*)>(_a[1]))); break;
        case 1: _t->setUIFromAveraging((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setAveragingFromUI(); break;
        case 3: _t->setNeutronData((*reinterpret_cast< NeutronData*(*)>(_a[1]))); break;
        case 4: _t->setPlot1D((*reinterpret_cast< Plot1D*(*)>(_a[1]))); break;
        case 5: _t->setPlot2D((*reinterpret_cast< Plot2D*(*)>(_a[1]))); break;
        case 6: _t->pressButtonSet(); break;
        case 7: _t->pressButtonAverage(); break;
        case 8: _t->pressButtonAdd(); break;
        case 9: _t->pressButtonRm(); break;
        case 10: _t->plotData((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AverageThread* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Plot1D* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Plot2D* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AverageWidget::staticMetaObject = { {
    &BaseWidget::staticMetaObject,
    qt_meta_stringdata_AverageWidget.data,
    qt_meta_data_AverageWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AverageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AverageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AverageWidget.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int AverageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
