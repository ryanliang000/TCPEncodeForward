/****************************************************************************
** Meta object code from reading C++ file 'sendmsgserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../sendmsgserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sendmsgserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SendMsgServer_t {
    QByteArrayData data[10];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SendMsgServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SendMsgServer_t qt_meta_stringdata_SendMsgServer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SendMsgServer"
QT_MOC_LITERAL(1, 14, 13), // "onStartServer"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "onStopServer"
QT_MOC_LITERAL(4, 42, 14), // "onClearContent"
QT_MOC_LITERAL(5, 57, 13), // "onReceivedMsg"
QT_MOC_LITERAL(6, 71, 10), // "onReplyMsg"
QT_MOC_LITERAL(7, 82, 12), // "onConnectMsg"
QT_MOC_LITERAL(8, 95, 10), // "onAliveMsg"
QT_MOC_LITERAL(9, 106, 21) // "onCheckBoxShowMessage"

    },
    "SendMsgServer\0onStartServer\0\0onStopServer\0"
    "onClearContent\0onReceivedMsg\0onReplyMsg\0"
    "onConnectMsg\0onAliveMsg\0onCheckBoxShowMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SendMsgServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    1,   57,    2, 0x0a /* Public */,
       6,    1,   60,    2, 0x0a /* Public */,
       7,    1,   63,    2, 0x0a /* Public */,
       8,    1,   66,    2, 0x0a /* Public */,
       9,    1,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void SendMsgServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SendMsgServer *_t = static_cast<SendMsgServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onStartServer(); break;
        case 1: _t->onStopServer(); break;
        case 2: _t->onClearContent(); break;
        case 3: _t->onReceivedMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->onReplyMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->onConnectMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->onAliveMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->onCheckBoxShowMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SendMsgServer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SendMsgServer.data,
      qt_meta_data_SendMsgServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SendMsgServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SendMsgServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SendMsgServer.stringdata0))
        return static_cast<void*>(const_cast< SendMsgServer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SendMsgServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
