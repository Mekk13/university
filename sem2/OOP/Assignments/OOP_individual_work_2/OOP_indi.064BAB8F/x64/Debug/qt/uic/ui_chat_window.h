/********************************************************************************
** Form generated from reading UI file 'Chat_Window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_WINDOW_H
#define UI_CHAT_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat_WindowClass
{
public:
    QLineEdit *Message;
    QPushButton *Send;
    QListWidget *List;

    void setupUi(QWidget *Chat_WindowClass)
    {
        if (Chat_WindowClass->objectName().isEmpty())
            Chat_WindowClass->setObjectName("Chat_WindowClass");
        Chat_WindowClass->resize(457, 389);
        Message = new QLineEdit(Chat_WindowClass);
        Message->setObjectName("Message");
        Message->setGeometry(QRect(0, 320, 361, 61));
        Send = new QPushButton(Chat_WindowClass);
        Send->setObjectName("Send");
        Send->setGeometry(QRect(370, 320, 80, 61));
        List = new QListWidget(Chat_WindowClass);
        List->setObjectName("List");
        List->setGeometry(QRect(0, 10, 451, 301));

        retranslateUi(Chat_WindowClass);

        QMetaObject::connectSlotsByName(Chat_WindowClass);
    } // setupUi

    void retranslateUi(QWidget *Chat_WindowClass)
    {
        Chat_WindowClass->setWindowTitle(QCoreApplication::translate("Chat_WindowClass", "Chat_Window", nullptr));
        Send->setText(QCoreApplication::translate("Chat_WindowClass", "SEND", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat_WindowClass: public Ui_Chat_WindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_WINDOW_H
