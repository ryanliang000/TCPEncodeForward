#ifndef SENDMSGSERVER_H
#define SENDMSGSERVER_H

#include <QtWidgets/QMainWindow>
#include "ui_sendmsgserver.h"
#include "TcpForwardServer.h"

class SendMsgServer : public QMainWindow
{
    Q_OBJECT

public:
    SendMsgServer(QWidget *parent = 0);
    ~SendMsgServer();

public slots:
    void onStartServer();
    void onStopServer();
    void onClearContent();
    void onReceivedMsg(QString);
    void onReplyMsg(QString);
	void onConnectMsg(QString);
    void onAliveMsg(QString);
    void onCheckBoxShowMessage(int);
private:
    Ui::SendMsgServerClass ui;
    TcpForwardServer* m_pTcpServer;
    QWidget* m_pMainWidget;
    std::vector<QThread*> m_threads;
};

#endif // SENDMSGSERVER_H
