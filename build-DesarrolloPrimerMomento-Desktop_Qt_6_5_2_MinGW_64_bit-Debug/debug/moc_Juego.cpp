/****************************************************************************
** Meta object code from reading C++ file 'Juego.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DesarrolloPrimerMomento/Juego.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Juego.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSJuegoENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSJuegoENDCLASS = QtMocHelpers::stringData(
    "Juego",
    "checkGameOver",
    "",
    "aparecerJugado",
    "cambiarTexto",
    "reducirVidas",
    "actualizarTexto",
    "verificarColision"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSJuegoENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[6];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[13];
    char stringdata5[13];
    char stringdata6[16];
    char stringdata7[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSJuegoENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSJuegoENDCLASS_t qt_meta_stringdata_CLASSJuegoENDCLASS = {
    {
        QT_MOC_LITERAL(0, 5),  // "Juego"
        QT_MOC_LITERAL(6, 13),  // "checkGameOver"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 14),  // "aparecerJugado"
        QT_MOC_LITERAL(36, 12),  // "cambiarTexto"
        QT_MOC_LITERAL(49, 12),  // "reducirVidas"
        QT_MOC_LITERAL(62, 15),  // "actualizarTexto"
        QT_MOC_LITERAL(78, 17)   // "verificarColision"
    },
    "Juego",
    "checkGameOver",
    "",
    "aparecerJugado",
    "cambiarTexto",
    "reducirVidas",
    "actualizarTexto",
    "verificarColision"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSJuegoENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x0a,    1 /* Public */,
       3,    0,   51,    2, 0x0a,    2 /* Public */,
       4,    0,   52,    2, 0x0a,    3 /* Public */,
       5,    0,   53,    2, 0x0a,    4 /* Public */,
       6,    0,   54,    2, 0x0a,    5 /* Public */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Juego::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_CLASSJuegoENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSJuegoENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSJuegoENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Juego, std::true_type>,
        // method 'checkGameOver'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'aparecerJugado'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cambiarTexto'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reducirVidas'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'actualizarTexto'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'verificarColision'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Juego::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Juego *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->checkGameOver(); break;
        case 1: _t->aparecerJugado(); break;
        case 2: _t->cambiarTexto(); break;
        case 3: _t->reducirVidas(); break;
        case 4: _t->actualizarTexto(); break;
        case 5: _t->verificarColision(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Juego::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Juego::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSJuegoENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int Juego::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
