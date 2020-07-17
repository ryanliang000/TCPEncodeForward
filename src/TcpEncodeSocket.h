#pragma once
#include "qtcpsocket.h"
#include "pub.h"
class TcpEncodeSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpEncodeSocket(QObject *parent = 0);
    ~TcpEncodeSocket(void);

	void setDesc(int ref){m_nDesc = ref;}
	int desc() {return m_nDesc;}

public slots:
    void onDataReceived();
    void onDisconnected();
    void onConnected();
    //void onAboutToClose();
signals:
    void updateClients(TcpEncodeSocket*, QByteArray);
    void disconnectedFromClient(int);

private:
	int m_nDesc;
};

