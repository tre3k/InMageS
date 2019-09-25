/****************************************************************************
** Meta object code from reading C++ file 'sidebar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/widgets/sidebar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sidebar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SideBar_t {
    QByteArrayData data[10];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SideBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SideBar_t qt_meta_stringdata_SideBar = {
    {
QT_MOC_LITERAL(0, 0, 7), // "SideBar"
QT_MOC_LITERAL(1, 8, 11), // "clickedUnit"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "addUnit"
QT_MOC_LITERAL(4, 29, 12), // "SideBarUnit*"
QT_MOC_LITERAL(5, 42, 4), // "unit"
QT_MOC_LITERAL(6, 47, 10), // "addStretch"
QT_MOC_LITERAL(7, 58, 4), // "size"
QT_MOC_LITERAL(8, 63, 11), // "unitClicked"
QT_MOC_LITERAL(9, 75, 5) // "index"

    },
    "SideBar\0clickedUnit\0\0addUnit\0SideBarUnit*\0"
    "unit\0addStretch\0size\0unitClicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SideBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void SideBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SideBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickedUnit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addUnit((*reinterpret_cast< SideBarUnit*(*)>(_a[1]))); break;
        case 2: _t->addStretch((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->unitClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SideBarUnit* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SideBar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SideBar::clickedUnit)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SideBar::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_SideBar.data,
    qt_meta_data_SideBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SideBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SideBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SideBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SideBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SideBar::clickedUnit(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
