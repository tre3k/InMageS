/****************************************************************************
** Meta object code from reading C++ file 'plot1d.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/widgets/plots/plot1d.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plot1d.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Plot1D_t {
    QByteArrayData data[10];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Plot1D_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Plot1D_t qt_meta_stringdata_Plot1D = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Plot1D"
QT_MOC_LITERAL(1, 7, 10), // "cleanPlots"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "addPlot"
QT_MOC_LITERAL(4, 27, 15), // "QVector<double>"
QT_MOC_LITERAL(5, 43, 8), // "abscissa"
QT_MOC_LITERAL(6, 52, 8), // "ordinate"
QT_MOC_LITERAL(7, 61, 4), // "name"
QT_MOC_LITERAL(8, 66, 5), // "color"
QT_MOC_LITERAL(9, 72, 11) // "rescaleAxis"

    },
    "Plot1D\0cleanPlots\0\0addPlot\0QVector<double>\0"
    "abscissa\0ordinate\0name\0color\0rescaleAxis"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Plot1D[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    4,   40,    2, 0x0a /* Public */,
       3,    3,   49,    2, 0x2a /* Public | MethodCloned */,
       3,    2,   56,    2, 0x2a /* Public | MethodCloned */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::QString, QMetaType::QString,    5,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::QString,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void,

       0        // eod
};

void Plot1D::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Plot1D *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cleanPlots(); break;
        case 1: _t->addPlot((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->addPlot((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->addPlot((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 4: _t->rescaleAxis(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Plot1D::staticMetaObject = { {
    &BaseWidget::staticMetaObject,
    qt_meta_stringdata_Plot1D.data,
    qt_meta_data_Plot1D,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Plot1D::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Plot1D::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Plot1D.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int Plot1D::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
