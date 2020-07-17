#pragma once
#include "TcpEncodeSocket.h"

class TcpForwardClient : public QObject
{
	Q_OBJECT
public:
	explicit TcpForwardClient(QObject *parent = 0);
	~TcpForwardClient(void);
	TcpEncodeSocket* local() {return m_localClient;}
	TcpEncodeSocket* remote() {return m_remoteClient;}
	bool connectToRemote(QString ip, int port);
	bool connectToLocal(int desc);
	void setEncodeKey(QByteArray bytes){m_encodeKeys = bytes;}

signals:
	void pushMessage(int, QString);

public slots:
	void onSayHi();
    void updateClientsFromLocal(TcpEncodeSocket*, QByteArray);
	void updateClientsFromRemote(TcpEncodeSocket*, QByteArray);
	void onDisconnect(int desc);
	void onError(QAbstractSocket::SocketError);

protected:
	void encodeMsg(QByteArray &);
	void decodeMsg(QByteArray &);

private:
	TcpEncodeSocket* m_localClient;
	TcpEncodeSocket* m_remoteClient;
	QByteArray m_encodeKeys;
    bool m_bConnected;
};

