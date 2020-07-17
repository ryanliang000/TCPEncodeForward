#include "sendmsgserver.h"
#include "qapplication.h"
#include "qdesktopwidget.h"
#include "qscrollbar.h"
#include "qmessagebox.h"
#include "ToolConfig.h"

SendMsgServer::SendMsgServer(QWidget *parent)
    : QMainWindow(parent)
    , m_pTcpServer(nullptr)
{
    ui.setupUi(this);

    m_pMainWidget = ui.leftWidget;

    connect(ui.btnStart, SIGNAL(clicked()), this, SLOT(onStartServer()));
    connect(ui.btnStop, SIGNAL(clicked()), this, SLOT(onStopServer()));
    connect(ui.btnClear, SIGNAL(clicked()), this, SLOT(onClearContent()));
    connect(ui.checkBoxShowMessage, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxShowMessage(int)));

    ui.btnStop->setDisabled(true);
    ui.btnStart->setDisabled(false);   
    Config config = ToolConfig::getInstance()->getConfig();
    ui.remoteIP->setText(config.sRemoteIP);
	ui.remotePort->setText(QString("%1").arg(config.nRemortPort));
    ui.editPort->setText(QString("%1").arg(config.nLocalPort));
	ui.keys->setText(config.sEncodeKey);
    ui.checkBoxShowMessage->setChecked(config.nShowMsg);
    onCheckBoxShowMessage(config.nShowMsg);
}

SendMsgServer::~SendMsgServer()
{
    if (m_pTcpServer != nullptr)
    {
        // close listen
        m_pTcpServer->stopListen();
        delete m_pTcpServer;
        m_pTcpServer = nullptr;
    }
}

void SendMsgServer::onStartServer()
{
    ui.btnStart->setDisabled(true);
	QString sRemoteIP = ui.remoteIP->text();
	uint nRemotePort = ui.remotePort->text().toUInt();
	QString sKeys = ui.keys->text();
    uint nPort = ui.editPort->text().toUInt();
    bool bShowMessage = ui.checkBoxShowMessage->isChecked();

	if (sRemoteIP.isEmpty() || nRemotePort == 0){
		QMessageBox::warning(this, "Warning", "Please input sock server and port!");
		ui.remoteIP->setFocus();
		return;
	}
    if (m_pTcpServer == nullptr)
    {
        m_pTcpServer = new TcpForwardServer(this, nPort);
        connect(m_pTcpServer, SIGNAL(connectMsg(QString)), this, SLOT(onConnectMsg(QString)));
        connect(m_pTcpServer, SIGNAL(aliveInfoMsg(QString)), this, SLOT(onAliveMsg(QString)));
        connect(m_pTcpServer, SIGNAL(replyMsg(QString)), this, SLOT(onReplyMsg(QString)));
        connect(m_pTcpServer, SIGNAL(receivedMsg(QString)), this, SLOT(onReceivedMsg(QString)));
    }
    m_pTcpServer->setLocalPort(nPort);
    m_pTcpServer->setEnableMessage(bShowMessage);
    m_pTcpServer->setRemoteAddress(sRemoteIP, nRemotePort);
    m_pTcpServer->setEncodeHexString(sKeys);

    ui.textReceive->setEnabled(bShowMessage);
    ui.textReply->setEnabled(bShowMessage);

    // start listen
    if (m_pTcpServer->startListen())
    {
        // reset button states
        ui.btnStart->setDisabled(true);
        ui.btnStop->setDisabled(false);
        MyDebugVar2("SendMsgServer::onStartServer Succ!", nPort);

        Config config;
        strcpy(config.sRemoteIP, sRemoteIP.toLocal8Bit().data());
        strcpy(config.sEncodeKey, sKeys.toLocal8Bit().data());
        config.nRemortPort = nRemotePort;
        config.nLocalPort = nPort;
        config.nShowMsg = bShowMessage;
        ToolConfig::getInstance()->setConfig(config);
        disconnect(ui.checkBoxShowMessage, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxShowMessage(int)));
    }
    else
    {
        ui.btnStart->setDisabled(false);
        ui.btnStop->setDisabled(true);
        MyDebugVar2("SendMsgServer::onStartServer Fail!", nPort);
    }
}

void SendMsgServer::onStopServer()
{
    MyDebugVar1("SendMsgServer::onStopServer!");
    if (m_pTcpServer != nullptr)
    {
        // close listen
        m_pTcpServer->stopListen();
        
        // reset button states
        ui.btnStop->setDisabled(true);
        ui.btnStart->setDisabled(false);
    }
    connect(ui.checkBoxShowMessage, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxShowMessage(int)));
    onCheckBoxShowMessage(ui.checkBoxShowMessage->isChecked());
}

void SendMsgServer::onClearContent()
{
    ui.textReceive->setText("");
    ui.textReply->setText("");
	ui.connectInfo->setText("");
}

void SendMsgServer::onReceivedMsg(QString msg)
{
	static unsigned int s_nMsgCount = 0;
	s_nMsgCount++;
	if (s_nMsgCount % MAX_SHOW_MSG_COUNT == 0){
		ui.textReceive->setText("...");
	}

    ui.textReceive->append("Receive: " + msg);
    QScrollBar *pScroll = ui.textReceive->verticalScrollBar();
    if (pScroll)
    {
        pScroll->setSliderPosition(pScroll->maximum());
    }
}


void SendMsgServer::onReplyMsg(QString msg)
{
	static unsigned int s_nMsgCount = 0;
	s_nMsgCount++;
	if (s_nMsgCount % MAX_SHOW_MSG_COUNT == 0){
		ui.textReply->setText("...");
	}

    ui.textReply->append("Reply: " + msg);
    QScrollBar *pScroll = ui.textReply->verticalScrollBar();
    if (pScroll)
    {
        pScroll->setSliderPosition(pScroll->maximum());
    }
}

void SendMsgServer::onConnectMsg(QString msg)
{
	static unsigned int s_nMsgCount = 0;
	s_nMsgCount++;
	if (s_nMsgCount % MAX_SHOW_MSG_COUNT == 0){
		ui.connectInfo->setText("...");
	}

	ui.connectInfo->append("->" + msg);
    QScrollBar *pScroll = ui.connectInfo->verticalScrollBar();
    if (pScroll)
    {
        pScroll->setSliderPosition(pScroll->maximum());
    }
}

void SendMsgServer::onAliveMsg(QString str)
{
    ui.labelConnectInfo->setText("Connection Info: " + str);
}

void SendMsgServer::onCheckBoxShowMessage(int checked)
{
    ui.textReceive->setEnabled(checked);
    ui.textReply->setEnabled(checked);
}


