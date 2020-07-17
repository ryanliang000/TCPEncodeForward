#include "TcpEncodeSocket.h"
#include "qthread.h"
// max byte limit for 1 time: 100mb


TcpEncodeSocket::TcpEncodeSocket(QObject *parent) 
    : QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(onDataReceived()));
    connect(this, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(this, SIGNAL(connected()), this, SLOT(onConnected()));
    //connect(this, SIGNAL(aboutToClose()), this, SLOT(onAboutToClose()));
}


TcpEncodeSocket::~TcpEncodeSocket(void)
{

}

void TcpEncodeSocket::onDataReceived()
{
    MyDebugVar1("MyTcpClient::onDataReceived");

	int nLen = bytesAvailable();
	QByteArray recvArray;
    if (nLen <= MAX_RECEIVE_BYTE_LENGTH)
    {
        recvArray = readAll();        
    }
    else
    {
        reset();
        recvArray = QByteArray("Error: message to long (above 100 mb)!");
    }

    emit updateClients(this, recvArray);
}

void TcpEncodeSocket::onDisconnected()
{
    MyDebugVar1("MyTcpClient::onDisconnected");
    emit disconnectedFromClient(desc());
}

void TcpEncodeSocket::onConnected()
{
    MyDebugVar1("MyTcpClient::onConnected");
}

//void TcpEncodeSocket::onAboutToClose()
//{
//    emit disconnectedFromClient(desc());
//}
