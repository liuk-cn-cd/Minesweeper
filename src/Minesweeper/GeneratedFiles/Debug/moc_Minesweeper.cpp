/****************************************************************************
** Meta object code from reading C++ file 'Minesweeper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Minesweeper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Minesweeper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Minesweeper_t {
    QByteArrayData data[9];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Minesweeper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Minesweeper_t qt_meta_stringdata_Minesweeper = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Minesweeper"
QT_MOC_LITERAL(1, 12, 25), // "on_actionOption_triggered"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 21), // "on_ptnNewGame_clicked"
QT_MOC_LITERAL(4, 61, 19), // "on_ptnModel_toggled"
QT_MOC_LITERAL(5, 81, 12), // "SlotGameOver"
QT_MOC_LITERAL(6, 94, 11), // "SlotGameWin"
QT_MOC_LITERAL(7, 106, 12), // "SlotProgress"
QT_MOC_LITERAL(8, 119, 9) // "dProgress"

    },
    "Minesweeper\0on_actionOption_triggered\0"
    "\0on_ptnNewGame_clicked\0on_ptnModel_toggled\0"
    "SlotGameOver\0SlotGameWin\0SlotProgress\0"
    "dProgress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Minesweeper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x09 /* Protected */,
       3,    0,   45,    2, 0x09 /* Protected */,
       4,    1,   46,    2, 0x09 /* Protected */,
       5,    0,   49,    2, 0x09 /* Protected */,
       6,    0,   50,    2, 0x09 /* Protected */,
       7,    1,   51,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    8,

       0        // eod
};

void Minesweeper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Minesweeper *_t = static_cast<Minesweeper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionOption_triggered(); break;
        case 1: _t->on_ptnNewGame_clicked(); break;
        case 2: _t->on_ptnModel_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->SlotGameOver(); break;
        case 4: _t->SlotGameWin(); break;
        case 5: _t->SlotProgress((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Minesweeper::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Minesweeper.data,
      qt_meta_data_Minesweeper,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Minesweeper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Minesweeper::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Minesweeper.stringdata0))
        return static_cast<void*>(const_cast< Minesweeper*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Minesweeper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
