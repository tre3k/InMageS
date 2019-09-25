/****************************************************************************
** Meta object code from reading C++ file 'plot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/widgets/plots/plot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Plot_t {
    QByteArrayData data[16];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Plot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Plot_t qt_meta_stringdata_Plot = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Plot"
QT_MOC_LITERAL(1, 5, 21), // "slot_sAxies_drag_zoom"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "QCPAxis*"
QT_MOC_LITERAL(4, 37, 23), // "QCPAxis::SelectablePart"
QT_MOC_LITERAL(5, 61, 12), // "QMouseEvent*"
QT_MOC_LITERAL(6, 74, 19), // "slot_full_drag_zoom"
QT_MOC_LITERAL(7, 94, 21), // "slot_selectionChanged"
QT_MOC_LITERAL(8, 116, 19), // "slot_contextMenuReq"
QT_MOC_LITERAL(9, 136, 1), // "p"
QT_MOC_LITERAL(10, 138, 11), // "exportToPDF"
QT_MOC_LITERAL(11, 150, 11), // "exportToBMP"
QT_MOC_LITERAL(12, 162, 11), // "exportToJPG"
QT_MOC_LITERAL(13, 174, 11), // "exportToPNG"
QT_MOC_LITERAL(14, 186, 7), // "setXLog"
QT_MOC_LITERAL(15, 194, 7) // "setYLog"

    },
    "Plot\0slot_sAxies_drag_zoom\0\0QCPAxis*\0"
    "QCPAxis::SelectablePart\0QMouseEvent*\0"
    "slot_full_drag_zoom\0slot_selectionChanged\0"
    "slot_contextMenuReq\0p\0exportToPDF\0"
    "exportToBMP\0exportToJPG\0exportToPNG\0"
    "setXLog\0setYLog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Plot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   64,    2, 0x09 /* Protected */,
       6,    1,   71,    2, 0x09 /* Protected */,
       7,    0,   74,    2, 0x09 /* Protected */,
       8,    1,   75,    2, 0x09 /* Protected */,
      10,    0,   78,    2, 0x09 /* Protected */,
      11,    0,   79,    2, 0x09 /* Protected */,
      12,    0,   80,    2, 0x09 /* Protected */,
      13,    0,   81,    2, 0x09 /* Protected */,
      14,    0,   82,    2, 0x09 /* Protected */,
      15,    0,   83,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4, 0x80000000 | 5,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Plot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Plot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_sAxies_drag_zoom((*reinterpret_cast< QCPAxis*(*)>(_a[1])),(*reinterpret_cast< QCPAxis::SelectablePart(*)>(_a[2])),(*reinterpret_cast< QMouseEvent*(*)>(_a[3]))); break;
        case 1: _t->slot_full_drag_zoom((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->slot_selectionChanged(); break;
        case 3: _t->slot_contextMenuReq((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->exportToPDF(); break;
        case 5: _t->exportToBMP(); break;
        case 6: _t->exportToJPG(); break;
        case 7: _t->exportToPNG(); break;
        case 8: _t->setXLog(); break;
        case 9: _t->setYLog(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAxis* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAxis::SelectablePart >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Plot::staticMetaObject = { {
    &QCustomPlot::staticMetaObject,
    qt_meta_stringdata_Plot.data,
    qt_meta_data_Plot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Plot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Plot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Plot.stringdata0))
        return static_cast<void*>(this);
    return QCustomPlot::qt_metacast(_clname);
}

int Plot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCustomPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
