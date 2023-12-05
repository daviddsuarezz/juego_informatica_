/****************************************************************************
** Meta object code from reading C++ file 'enemyshoots.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DesarrolloPrimerMomento/enemyshoots.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enemyshoots.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSEnemyShootsENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSEnemyShootsENDCLASS = QtMocHelpers::stringData(
    "EnemyShoots",
    "Shoot",
    "",
    "actualize",
    "Dead"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSEnemyShootsENDCLASS_t {
    uint offsetsAndSizes[10];
    char stringdata0[12];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSEnemyShootsENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSEnemyShootsENDCLASS_t qt_meta_stringdata_CLASSEnemyShootsENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "EnemyShoots"
        QT_MOC_LITERAL(12, 5),  // "Shoot"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 9),  // "actualize"
        QT_MOC_LITERAL(29, 4)   // "Dead"
    },
    "EnemyShoots",
    "Shoot",
    "",
    "actualize",
    "Dead"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSEnemyShootsENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x0a,    1 /* Public */,
       3,    0,   33,    2, 0x0a,    2 /* Public */,
       4,    0,   34,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject EnemyShoots::staticMetaObject = { {
    QMetaObject::SuperData::link<Enemy2::staticMetaObject>(),
    qt_meta_stringdata_CLASSEnemyShootsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSEnemyShootsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSEnemyShootsENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EnemyShoots, std::true_type>,
        // method 'Shoot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'actualize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Dead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void EnemyShoots::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EnemyShoots *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Shoot(); break;
        case 1: _t->actualize(); break;
        case 2: _t->Dead(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *EnemyShoots::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EnemyShoots::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSEnemyShootsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return Enemy2::qt_metacast(_clname);
}

int EnemyShoots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Enemy2::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
