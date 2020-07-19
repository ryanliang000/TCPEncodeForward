/****************************************************************************
** Meta object code from reading C++ file 'TcpEncodeSocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TcpEncodeSocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpEncodeSocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TcpEncodeSocket_t {
    QByteArrayData data[8];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpEncodeSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpEncodeSocket_t qt_meta_stringdata_TcpEncodeSocket = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TcpEncodeSocket"
QT_MOC_LITERAL(1, 16, 13), // "updateClients"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "TcpEncodeSocket*"
QT_MOC_LITERAL(4, 48, 22), // "disconnectedFromClient"
QT_MOC_LITERAL(5, 71, 14), // "onDataReceived"
QT_MOC_LITERAL(6, 86, 14), // "onDisconnected"
QT_MOC_LITERAL(7, 101, 11) // "onConnected"

    },
    "TcpEncodeSocket\0updateClients\0\0"
    "TcpEncodeSocket*\0disconnectedFromClient\0"
    "onDataReceived\0onDisconnected\0onConnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpEncodeSocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       4,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpEncodeSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpEncodeSocket *_t = static_cast<TcpEncodeSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateClients((*reinterpret_cast< TcpEncodeSocket*(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->disconnectedFromClient((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onDataReceived(); break;
        case 3: _t->onDisconnected(); break;
        case 4: _t->onConnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TcpEncodeSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpEncodeSocket::*_t)(TcpEncodeSocket * , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpEncodeSocket::updateClients)) {
                *result = 0;
            }
        }
        {
            typedef void (TcpEncodeSocket::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpEncodeSocket::disconnectedFromClient)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject TcpEncodeSocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_TcpEncodeSocket.data,
      qt_meta_data_TcpEncodeSocket,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TcpEncodeSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpEncodeSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TcpEncodeSocket.stringdata0))
        return static_cast<void*>(const_cast< TcpEncodeSocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int TcpEncodeSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void TcpEncodeSocket::updateClients(TcpEncodeSocket * _t1, QByteArray _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpEncodeSocket::disconnectedFromClient(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
