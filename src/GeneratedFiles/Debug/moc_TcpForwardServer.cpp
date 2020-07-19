/****************************************************************************
** Meta object code from reading C++ file 'TcpForwardServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TcpForwardServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpForwardServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TcpForwardServer_t {
    QByteArrayData data[13];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpForwardServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpForwardServer_t qt_meta_stringdata_TcpForwardServer = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TcpForwardServer"
QT_MOC_LITERAL(1, 17, 11), // "receivedMsg"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "replyMsg"
QT_MOC_LITERAL(4, 39, 10), // "connectMsg"
QT_MOC_LITERAL(5, 50, 12), // "aliveInfoMsg"
QT_MOC_LITERAL(6, 63, 5), // "sayHi"
QT_MOC_LITERAL(7, 69, 13), // "disconnectAll"
QT_MOC_LITERAL(8, 83, 17), // "onPushMessageToUI"
QT_MOC_LITERAL(9, 101, 5), // "nType"
QT_MOC_LITERAL(10, 107, 7), // "message"
QT_MOC_LITERAL(11, 115, 17), // "onSlotDisconneted"
QT_MOC_LITERAL(12, 133, 16) // "doResetFailCount"

    },
    "TcpForwardServer\0receivedMsg\0\0replyMsg\0"
    "connectMsg\0aliveInfoMsg\0sayHi\0"
    "disconnectAll\0onPushMessageToUI\0nType\0"
    "message\0onSlotDisconneted\0doResetFailCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpForwardServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,
       6,    0,   71,    2, 0x06 /* Public */,
       7,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   75,    2, 0x0a /* Public */,
      11,    1,   80,    2, 0x0a /* Public */,
      12,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void TcpForwardServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpForwardServer *_t = static_cast<TcpForwardServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivedMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->replyMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->connectMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->aliveInfoMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sayHi(); break;
        case 5: _t->disconnectAll((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onPushMessageToUI((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->onSlotDisconneted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->doResetFailCount(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpForwardServer::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpForwardServer::receivedMsg)) {
                *result = 0;
            }
        }
        {
            typedef void (TcpForwardServer::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpForwardServer::replyMsg)) {
                *result = 1;
            }
        }
        {
            typedef void (TcpForwardServer::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpForwardServer::connectMsg)) {
                *result = 2;
            }
        }
        {
            typedef void (TcpForwardServer::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpForwardServer::aliveInfoMsg)) {
                *result = 3;
            }
        }
        {
            typedef void (TcpForwardServer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpForwardServer::sayHi)) {
                *result = 4;
            }
        }
        {
            typedef void (TcpForwardServer::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpForwardServer::disconnectAll)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject TcpForwardServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_TcpForwardServer.data,
      qt_meta_data_TcpForwardServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TcpForwardServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpForwardServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TcpForwardServer.stringdata0))
        return static_cast<void*>(const_cast< TcpForwardServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int TcpForwardServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TcpForwardServer::receivedMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpForwardServer::replyMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpForwardServer::connectMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TcpForwardServer::aliveInfoMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpForwardServer::sayHi()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void TcpForwardServer::disconnectAll(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
