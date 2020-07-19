/********************************************************************************
** Form generated from reading UI file 'sendmsgserver.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDMSGSERVER_H
#define UI_SENDMSGSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SendMsgServerClass
{
public:
    QAction *actionStart_Server;
    QAction *actionStopServer;
    QAction *actionChange_Reply_Message;
    QAction *actionClear_Receive_Message;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *leftWidget;
    QVBoxLayout *verticalLayout;
    QWidget *ReceiveWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelConnectInfo;
    QTextBrowser *connectInfo;
    QLabel *label;
    QTextBrowser *textReceive;
    QLabel *label_2;
    QTextEdit *textReply;
    QWidget *sockWidget;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLineEdit *remoteIP;
    QLabel *label_6;
    QLineEdit *remotePort;
    QLabel *label_3;
    QLineEdit *editPort;
    QLabel *label_7;
    QLineEdit *keys;
    QLabel *label_8;
    QCheckBox *checkBoxShowMessage;
    QWidget *BottomWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QPushButton *btnClear;
    QToolButton *about;

    void setupUi(QMainWindow *SendMsgServerClass)
    {
        if (SendMsgServerClass->objectName().isEmpty())
            SendMsgServerClass->setObjectName(QStringLiteral("SendMsgServerClass"));
        SendMsgServerClass->resize(523, 510);
        actionStart_Server = new QAction(SendMsgServerClass);
        actionStart_Server->setObjectName(QStringLiteral("actionStart_Server"));
        actionStopServer = new QAction(SendMsgServerClass);
        actionStopServer->setObjectName(QStringLiteral("actionStopServer"));
        actionChange_Reply_Message = new QAction(SendMsgServerClass);
        actionChange_Reply_Message->setObjectName(QStringLiteral("actionChange_Reply_Message"));
        actionClear_Receive_Message = new QAction(SendMsgServerClass);
        actionClear_Receive_Message->setObjectName(QStringLiteral("actionClear_Receive_Message"));
        centralWidget = new QWidget(SendMsgServerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        leftWidget = new QWidget(centralWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        verticalLayout = new QVBoxLayout(leftWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ReceiveWidget = new QWidget(leftWidget);
        ReceiveWidget->setObjectName(QStringLiteral("ReceiveWidget"));
        verticalLayout_2 = new QVBoxLayout(ReceiveWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelConnectInfo = new QLabel(ReceiveWidget);
        labelConnectInfo->setObjectName(QStringLiteral("labelConnectInfo"));

        verticalLayout_2->addWidget(labelConnectInfo);

        connectInfo = new QTextBrowser(ReceiveWidget);
        connectInfo->setObjectName(QStringLiteral("connectInfo"));

        verticalLayout_2->addWidget(connectInfo);

        label = new QLabel(ReceiveWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        textReceive = new QTextBrowser(ReceiveWidget);
        textReceive->setObjectName(QStringLiteral("textReceive"));

        verticalLayout_2->addWidget(textReceive);

        label_2 = new QLabel(ReceiveWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label_2);

        textReply = new QTextEdit(ReceiveWidget);
        textReply->setObjectName(QStringLiteral("textReply"));
        textReply->setReadOnly(true);

        verticalLayout_2->addWidget(textReply);

        verticalLayout_2->setStretch(1, 6);
        verticalLayout_2->setStretch(3, 3);
        verticalLayout_2->setStretch(5, 3);

        verticalLayout->addWidget(ReceiveWidget);

        sockWidget = new QWidget(leftWidget);
        sockWidget->setObjectName(QStringLiteral("sockWidget"));
        formLayout = new QFormLayout(sockWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_5 = new QLabel(sockWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        remoteIP = new QLineEdit(sockWidget);
        remoteIP->setObjectName(QStringLiteral("remoteIP"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(remoteIP->sizePolicy().hasHeightForWidth());
        remoteIP->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::FieldRole, remoteIP);

        label_6 = new QLabel(sockWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        remotePort = new QLineEdit(sockWidget);
        remotePort->setObjectName(QStringLiteral("remotePort"));
        sizePolicy.setHeightForWidth(remotePort->sizePolicy().hasHeightForWidth());
        remotePort->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::FieldRole, remotePort);

        label_3 = new QLabel(sockWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        editPort = new QLineEdit(sockWidget);
        editPort->setObjectName(QStringLiteral("editPort"));
        sizePolicy.setHeightForWidth(editPort->sizePolicy().hasHeightForWidth());
        editPort->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::FieldRole, editPort);

        label_7 = new QLabel(sockWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        keys = new QLineEdit(sockWidget);
        keys->setObjectName(QStringLiteral("keys"));
        sizePolicy.setHeightForWidth(keys->sizePolicy().hasHeightForWidth());
        keys->setSizePolicy(sizePolicy);

        formLayout->setWidget(4, QFormLayout::FieldRole, keys);

        label_8 = new QLabel(sockWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_8);

        checkBoxShowMessage = new QCheckBox(sockWidget);
        checkBoxShowMessage->setObjectName(QStringLiteral("checkBoxShowMessage"));

        formLayout->setWidget(5, QFormLayout::FieldRole, checkBoxShowMessage);


        verticalLayout->addWidget(sockWidget);

        BottomWidget = new QWidget(leftWidget);
        BottomWidget->setObjectName(QStringLiteral("BottomWidget"));
        horizontalLayout_3 = new QHBoxLayout(BottomWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnStart = new QPushButton(BottomWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));

        horizontalLayout_3->addWidget(btnStart);

        btnStop = new QPushButton(BottomWidget);
        btnStop->setObjectName(QStringLiteral("btnStop"));

        horizontalLayout_3->addWidget(btnStop);

        btnClear = new QPushButton(BottomWidget);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        horizontalLayout_3->addWidget(btnClear);

        about = new QToolButton(BottomWidget);
        about->setObjectName(QStringLiteral("about"));
        QFont font;
        font.setUnderline(true);
        about->setFont(font);
        about->setAutoRaise(true);

        horizontalLayout_3->addWidget(about);


        verticalLayout->addWidget(BottomWidget);

        verticalLayout->setStretch(0, 3);

        verticalLayout_3->addWidget(leftWidget);

        SendMsgServerClass->setCentralWidget(centralWidget);

        retranslateUi(SendMsgServerClass);

        QMetaObject::connectSlotsByName(SendMsgServerClass);
    } // setupUi

    void retranslateUi(QMainWindow *SendMsgServerClass)
    {
        SendMsgServerClass->setWindowTitle(QString());
        actionStart_Server->setText(QApplication::translate("SendMsgServerClass", "Start Server", 0));
        actionStopServer->setText(QApplication::translate("SendMsgServerClass", "StopServer", 0));
        actionChange_Reply_Message->setText(QApplication::translate("SendMsgServerClass", "Change Reply Message", 0));
        actionClear_Receive_Message->setText(QApplication::translate("SendMsgServerClass", "Clear Receive Message", 0));
        labelConnectInfo->setText(QApplication::translate("SendMsgServerClass", "Connection Info:", 0));
        label->setText(QApplication::translate("SendMsgServerClass", "Local Out Message:", 0));
        label_2->setText(QApplication::translate("SendMsgServerClass", "Remote In Message: ", 0));
        label_5->setText(QApplication::translate("SendMsgServerClass", "Remote Server IP:", 0));
        label_6->setText(QApplication::translate("SendMsgServerClass", "Remote Server Port:", 0));
        label_3->setText(QApplication::translate("SendMsgServerClass", "Local Server Port:", 0));
        editPort->setText(QApplication::translate("SendMsgServerClass", "2888", 0));
        label_7->setText(QApplication::translate("SendMsgServerClass", "Encode Hex:", 0));
        keys->setText(QApplication::translate("SendMsgServerClass", "0xA8", 0));
        label_8->setText(QApplication::translate("SendMsgServerClass", "Show Message:", 0));
        checkBoxShowMessage->setText(QApplication::translate("SendMsgServerClass", "Show Local and Remote Message", 0));
        btnStart->setText(QApplication::translate("SendMsgServerClass", "Start Server", 0));
        btnStop->setText(QApplication::translate("SendMsgServerClass", "Stop Server", 0));
        btnClear->setText(QApplication::translate("SendMsgServerClass", "Clear Page", 0));
        about->setText(QApplication::translate("SendMsgServerClass", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class SendMsgServerClass: public Ui_SendMsgServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDMSGSERVER_H
