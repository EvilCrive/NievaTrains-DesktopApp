/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../NievaTrains_P2/view/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 20), // "slotShowInfoGenerali"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "slotCarica"
QT_MOC_LITERAL(4, 44, 9), // "slotSalva"
QT_MOC_LITERAL(5, 54, 10), // "slotAutori"
QT_MOC_LITERAL(6, 65, 13), // "slotShowTreno"
QT_MOC_LITERAL(7, 79, 9), // "slotFlush"
QT_MOC_LITERAL(8, 89, 15), // "slotRemoveTreno"
QT_MOC_LITERAL(9, 105, 24), // "slotShowInserimentoTreno"
QT_MOC_LITERAL(10, 130, 18), // "slotInserisciTreno"
QT_MOC_LITERAL(11, 149, 21), // "slotShowModificaTreno"
QT_MOC_LITERAL(12, 171, 17), // "slotModificaTreno"
QT_MOC_LITERAL(13, 189, 9), // "slotCerca"
QT_MOC_LITERAL(14, 199, 15), // "slotResetSearch"
QT_MOC_LITERAL(15, 215, 18), // "slotKmPercorribili"
QT_MOC_LITERAL(16, 234, 24) // "slotCarburanteNecessario"

    },
    "MainWindow\0slotShowInfoGenerali\0\0"
    "slotCarica\0slotSalva\0slotAutori\0"
    "slotShowTreno\0slotFlush\0slotRemoveTreno\0"
    "slotShowInserimentoTreno\0slotInserisciTreno\0"
    "slotShowModificaTreno\0slotModificaTreno\0"
    "slotCerca\0slotResetSearch\0slotKmPercorribili\0"
    "slotCarburanteNecessario"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    0,   94,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    0,   97,    2, 0x0a /* Public */,
      11,    0,   98,    2, 0x0a /* Public */,
      12,    0,   99,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    0,  101,    2, 0x0a /* Public */,
      15,    0,  102,    2, 0x0a /* Public */,
      16,    0,  103,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotShowInfoGenerali(); break;
        case 1: _t->slotCarica(); break;
        case 2: _t->slotSalva(); break;
        case 3: _t->slotAutori(); break;
        case 4: _t->slotShowTreno(); break;
        case 5: _t->slotFlush(); break;
        case 6: _t->slotRemoveTreno(); break;
        case 7: _t->slotShowInserimentoTreno(); break;
        case 8: _t->slotInserisciTreno(); break;
        case 9: _t->slotShowModificaTreno(); break;
        case 10: _t->slotModificaTreno(); break;
        case 11: _t->slotCerca(); break;
        case 12: _t->slotResetSearch(); break;
        case 13: _t->slotKmPercorribili(); break;
        case 14: _t->slotCarburanteNecessario(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
