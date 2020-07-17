#include "TcpForwardServer.h"
#include "TcpEncodeSocket.h"
#include "TcpForwardClient.h"
#include "TextHexDecode.h"
TcpForwardServer::TcpForwardServer(QObject *parent /*= 0*/, int port)
    : QTcpServer(parent)
    , m_nPort(port)
{
    m_nThreadCount = ceil(c_nCPUCount * 1.5);
	m_encodeKeys.push_back(DEFUALT_ENCODE_KEY);
    for (auto i = 0; i < m_nThreadCount; i++) {
        m_threads.push_back(new QThread(this));
        m_threads.back()->start();
    }
    m_nValidConnections = 0;
    m_nFailedCount = 0;
	qDebug()<<"main thread:"<<QThread::currentThreadId();
    m_bSendMessageToUI = true;
    m_bSendMessageToUI = true;
    m_pTimer = new QTimer(this);
}


TcpForwardServer::~TcpForwardServer(void)
{
    for (auto i = 0; i < m_nThreadCount; i++) {
        m_threads[i]->terminate();
    }
    for (auto i = 0; i < m_nThreadCount; i++) {
        m_threads[i]->wait();
        delete m_threads[i];
    }
    m_threads.clear();
}

void TcpForwardServer::incomingConnection(qintptr socketDescriptor)
{
    MyDebugVar2("MyTcpServer::incomingConnection", socketDescriptor);

    // create tcp connect
    TcpForwardClient* pClient = new TcpForwardClient();
	if (!pClient->connectToLocal(socketDescriptor))
	{
		emit connectMsg(QString("sock5: connect to local client failed!"));
		delete pClient;
		return;
	}
    if (m_nFailedCount == MAX_FAILED_COUNT) {
        m_pTimer->start(FAILED_WAIT_SECOND * 1000);
        emit connectMsg(QString("failed connect to remote times over than %1, close connections for %2 seconds!")
            .arg(MAX_FAILED_COUNT)
            .arg(FAILED_WAIT_SECOND));
        m_nFailedCount = FAILED_WAIT_INDENTIFY;
    }
    if (m_nFailedCount == FAILED_WAIT_INDENTIFY)
    {
        pClient->local()->disconnect();
        return;
    }
	if (!pClient->connectToRemote(m_sRemoteIP, m_nRemotePort))
	{
		pClient->local()->disconnectFromHost();
		emit connectMsg(QString("sock5: connect to remote sock server failed!"));
		delete pClient;
        m_nFailedCount++;
		return;
	}
    m_nFailedCount = 0;
    m_nValidConnections++;
	pClient->moveToThread(m_threads[m_nValidConnections % m_threads.size()]);
	pClient->setEncodeKey(m_encodeKeys);

	connect(pClient->local(), SIGNAL(updateClients(TcpEncodeSocket*, QByteArray)), pClient, SLOT(updateClientsFromLocal(TcpEncodeSocket*, QByteArray)));
	connect(pClient->remote(), SIGNAL(updateClients(TcpEncodeSocket*, QByteArray)), pClient, SLOT(updateClientsFromRemote(TcpEncodeSocket*, QByteArray)));
	
	emit connectMsg(QString("Connect(%1), In: %2:%3, Out: %4:%5")
			.arg(socketDescriptor)
			.arg(pClient->local()->peerAddress().toString())
			.arg(pClient->local()->peerPort())
			.arg(pClient->remote()->localAddress().toString())
			.arg(pClient->remote()->localPort()));
   
	connect(pClient, SIGNAL(pushMessage(int, QString)), this, SLOT(onPushMessageToUI(int, QString)));
	connect(pClient->remote(), SIGNAL(disconnectedFromClient(int)), this, SLOT(onSlotDisconneted(int)));
	connect(pClient->local(), SIGNAL(disconnectedFromClient(int)), pClient, SLOT(onDisconnect(int)));
	connect(pClient->remote(), SIGNAL(disconnectedFromClient(int)), pClient, SLOT(onDisconnect(int)));
	connect(this, SIGNAL(disconnectAll(int)), pClient, SLOT(onDisconnect(int)));

    // 放入链接数组中
	m_mapClients[pClient->remote()->desc()] = pClient;

    TcpForwardServer::onPushMessageToUI(ENUM_ALIVE_MESSAGE, QString("Alive(%1)").arg(m_nValidConnections));
}
void TcpForwardServer::onPushMessageToUI(int nType, QString message)
{
	switch(nType){
    case ENUM_ALIVE_MESSAGE:
        {
            emit aliveInfoMsg(message);
        }
    break;
	case ENUM_CONNECT_MESSAGE:
		{
			emit connectMsg(message);
		}
		break;
	case ENUM_RECEIVE_MESSAGE:
		{
            if (m_bSendMessageToUI)
			    emit receivedMsg(message);
		}
		break;
	case ENUM_REPLY_MESSAGE:
		{
            if (m_bSendMessageToUI)
			    emit replyMsg(message);
		}
		break;
	}
}
void TcpForwardServer::onSlotDisconneted(int socketDescriptor)
{
    m_nValidConnections--;
    TcpForwardServer::onPushMessageToUI(ENUM_ALIVE_MESSAGE, QString("Alive(%1)").arg(m_nValidConnections));
    MyDebugVar2("MyTcpServer::slotDisconneted", socketDescriptor);
	if (m_mapClients.find(socketDescriptor) != m_mapClients.end()){
		m_mapClients[socketDescriptor] = nullptr;
	}
}

void TcpForwardServer::doResetFailCount()
{
    m_nFailedCount = 0;
    emit connectMsg(QString("resume connection!"));
}

bool TcpForwardServer::startListen()
{
    // 监听端口
    m_nValidConnections = 0;
    m_nFailedCount = 0;
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(doResetFailCount()));
    return listen(QHostAddress::Any, m_nPort);
}

void TcpForwardServer::stopListen()
{
    m_nFailedCount = 0;
    disconnect(m_pTimer, SIGNAL(timeout()), this, SLOT(doResetFailCount()));
    // 关闭监听
    if (isListening())
    {
		emit disconnectAll(-1);
		close();
    }
    TcpForwardServer::onPushMessageToUI(ENUM_ALIVE_MESSAGE, QString(""));
}

void TcpForwardServer::setRemoteAddress(QString sIP, int nPort)
{
	m_sRemoteIP = sIP;
	m_nRemotePort = nPort;
}
void TcpForwardServer::setEncodeHexString(QString sEncodeString)
{
	m_encodeKeys = CTextHexDecode::utf8HexToByteArray(sEncodeString);
	if (m_encodeKeys.length() == 0){
		m_encodeKeys.push_back(DEFUALT_ENCODE_KEY);
	}
}
