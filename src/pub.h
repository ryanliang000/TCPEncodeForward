#pragma once

#define TIMEOUT_CONNECT_MILLSECOND 300
#define MAX_RECEIVE_BYTE_LENGTH 1024 * 1024 * 1024
#define MAX_SHOW_MSG_COUNT 128
#define DEFUALT_ENCODE_KEY 0xB7
#define MAX_SHOW_MSG_LENGHT 48
#define MAX_FAILED_COUNT 10
#define FAILED_WAIT_SECOND 60
#define FAILED_WAIT_INDENTIFY 999999

enum MESSAGE_TYPE
{
    ENUM_ALIVE_MESSAGE = 0,
    ENUM_CONNECT_MESSAGE = 1,
	ENUM_RECEIVE_MESSAGE = 2,
	ENUM_REPLY_MESSAGE = 3
};

#ifdef NDEBUG
	#define  MyDebugVar1(desc1)
	#define  MyDebugVar2(desc1, desc2)
    #define  MyDebugVar3(desc1, desc2, desc3)
#else
	#define  MyDebugVar1(desc1) {QString sDebugInfo = QString("%1").arg(desc1); qDebug(sDebugInfo.toUtf8());}
	#define  MyDebugVar2(desc1, desc2) {QString sDebugInfo = QString("%1, %2").arg(desc1).arg(desc2); qDebug(sDebugInfo.toUtf8());}
	#define  MyDebugVar3(desc1, desc2, desc3) {QString sDebugInfo = QString("%1, %2, %3").arg(desc1).arg(desc2).arg(desc3); qDebug(sDebugInfo.toUtf8());}
#endif
