#pragma once
#include "qtcpserver.h"
#include "qthread.h"
#include "TcpEncodeSocket.h"
#include "TcpForwardClient.h"
#include <atomic>
#include <qtimer.h>
class TcpForwardServer :
    public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpForwardServer(QObject *parent = 0, int port = 28888);
    ~TcpForwardServer(void);

    bool startListen();
    void stopListen();
	void setRemoteAddress(QString sIP, int nPort);
	void setEncodeHexString(QString sEncodeString);
    void setLocalPort(int nPort) { m_nPort = nPort; }
    void setEnableMessage(bool flag) { m_bSendMessageToUI = flag; }
signals:
    void receivedMsg(QString);
    void replyMsg(QString);
	void connectMsg(QString);
    void aliveInfoMsg(QString);
	void sayHi();
	void disconnectAll(int);

public slots:
    void onPushMessageToUI(int nType, QString message);
    void onSlotDisconneted(int);
    void doResetFailCount();
protected:
    virtual void incomingConnection(qintptr socketDescriptor);

private:
    int m_nPort;
	QHash<int, TcpForwardClient*> m_mapClients;
    QString m_sReplyTextSet;
	QString m_sRemoteIP;
	int m_nRemotePort;
    int m_nThreadCount;
	QByteArray m_encodeKeys;
    std::vector<QThread*> m_threads;
    std::atomic_long m_nValidConnections;
    std::atomic_long m_nFailedCount;
    bool m_bSendMessageToUI;
    QTimer* m_pTimer;
};

