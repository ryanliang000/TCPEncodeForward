#include "TcpForwardClient.h"
#include "qthread.h"
#include "TextHexDecode.h"
#include "qhostaddress.h"
TcpForwardClient::TcpForwardClient(QObject *parent): QObject(parent), m_localClient(nullptr), m_remoteClient(nullptr)
{
	// tcp link
    m_localClient  = new TcpEncodeSocket(this);
	m_remoteClient = new TcpEncodeSocket(this);
    m_bConnected = false;
}

TcpForwardClient::~TcpForwardClient(void)
{
	if (m_localClient)
		delete m_localClient;
	if (m_remoteClient)
		delete m_remoteClient;
}

bool TcpForwardClient::connectToRemote(QString sIP, int nPort)
{
	m_remoteClient->connectToHost(sIP, nPort, QIODevice::ReadWrite, QAbstractSocket::IPv4Protocol);
    if (m_remoteClient->waitForConnected(TIMEOUT_CONNECT_MILLSECOND))
    { 
        m_remoteClient->setDesc(m_remoteClient->localPort());
        m_bConnected = true;
        MyDebugVar1("connectToRemote Succ!")
        return true;
    }
	else {
        MyDebugVar1(m_remoteClient->errorString());
    }
	return false;
}

bool TcpForwardClient::connectToLocal(int desc)
{
	bool bRt = m_localClient->setSocketDescriptor(desc);
    m_localClient->setDesc(m_localClient->peerPort());
    return bRt;
}

void TcpForwardClient::onSayHi()
{
    qDebug()<<"current thread:"<<QThread::currentThreadId();
	qDebug()<<"hi";
}

void TcpForwardClient::encodeMsg(QByteArray &msg)
{
	int nLength = m_encodeKeys.length();
	for(int i=0; i<msg.length(); i++){
		msg[i] = msg[i] ^ m_encodeKeys[i%nLength];
	}
}
void TcpForwardClient::decodeMsg(QByteArray &msg)
{
	int nLength = m_encodeKeys.length();
	for(int i=0; i<msg.length(); i++){
		msg[i] = msg[i] ^ m_encodeKeys[i%nLength];
	}
}



void TcpForwardClient::updateClientsFromLocal(TcpEncodeSocket* pSocket, QByteArray msg)
{
    MyDebugVar1(QString("local msg: msg length %1").arg(msg.length()));
	if (msg.length() <= MAX_SHOW_MSG_LENGHT){
		emit pushMessage(ENUM_RECEIVE_MESSAGE, QString("%1:%2 length: %5\r\n  Text: %3\r\n  Hex: %4")
				.arg(pSocket->peerAddress().toString())
				.arg(pSocket->peerPort())
				.arg(QString::fromUtf8(msg))
				.arg(CTextHexDecode::byteArrayToHex(msg))
				.arg(msg.length()));
	}
	else{
		emit pushMessage(ENUM_RECEIVE_MESSAGE, QString("%1:%2 length: %5\r\n  Text: %3\r\n  Hex: %4")
				.arg(pSocket->peerAddress().toString())
				.arg(pSocket->peerPort())
				.arg(QString::fromUtf8(msg.left(MAX_SHOW_MSG_LENGHT)) + "...")
				.arg(CTextHexDecode::byteArrayToHex(msg.left(MAX_SHOW_MSG_LENGHT)) + "...")
				.arg(msg.length()));
	}

	encodeMsg(msg);
	// return message for the port
	if (remote()->write(msg.data(), msg.length()) != msg.length())
	{
		emit pushMessage(ENUM_RECEIVE_MESSAGE, "[error]write to remote data length error!");
	}
	return;
}
void TcpForwardClient::updateClientsFromRemote(TcpEncodeSocket* pSocket, QByteArray msg)
{
    MyDebugVar1(QString("remote msg: msg length %1").arg(msg.length()));

	if (msg.length() <= MAX_SHOW_MSG_LENGHT){
		emit pushMessage(ENUM_REPLY_MESSAGE, QString("%1:%2  length: %4\r\n Text: %5\r\n Hex: %3")
			.arg(pSocket->localAddress().toString()).arg(pSocket->localPort()).arg(CTextHexDecode::byteArrayToHex(msg)).arg(msg.length()).arg(QString::fromUtf8(msg)));
	}
	else{
		emit pushMessage(ENUM_REPLY_MESSAGE, QString("%1:%2  length: %4\r\n Text: %5\r\n Hex: %3")
				.arg(pSocket->localAddress().toString()).arg(pSocket->localPort()).arg(CTextHexDecode::byteArrayToHex(msg.left(MAX_SHOW_MSG_LENGHT)) + "...").arg(msg.length()).arg(QString::fromUtf8(msg.left(MAX_SHOW_MSG_LENGHT)) + "..."));
	}

	decodeMsg(msg);
	// return message for the port
	if (!local()->write(msg.data(), msg.length()) == msg.length())
	{
		emit pushMessage(ENUM_REPLY_MESSAGE, "[error]write to local data length error!");
	}
}

void TcpForwardClient::onDisconnect(int desc)
{
    if (m_bConnected) {
        m_bConnected = false;       
        QString label = "undefine";
        if (remote()->desc() == desc)
            label = "remote";
        else if (local()->desc() == desc)
            label = "local";
        else if (-1 == desc)
            label = "forwardServer";

        emit pushMessage(ENUM_CONNECT_MESSAGE, QString("Disconnet(%1) from %6, In: %2:%3, Out: %4:%5")
            .arg(local()->desc())
            .arg(local()->peerAddress().toString())
            .arg(local()->peerPort())
            .arg(remote()->localAddress().toString())
            .arg(remote()->localPort())
            .arg(label));

        if (label == "local")
            remote()->disconnectFromHost();
        else if (label == "remote")
            local()->disconnectFromHost();
        else 
        {
            remote()->disconnectFromHost();
            local()->disconnectFromHost();
        }
    }
}
void TcpForwardClient::onError(QAbstractSocket::SocketError error)
{
	MyDebugVar1(QString("socket error: %1").arg(error));

}
