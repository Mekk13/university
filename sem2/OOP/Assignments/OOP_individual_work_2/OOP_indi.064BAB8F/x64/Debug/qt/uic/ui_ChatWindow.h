/********************************************************************************
** Form generated from reading UI file 'ChatWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindowClass
{
public:
    QWidget *centralWidget;
    QListView *List;
    QLineEdit *Message;
    QPushButton *Send;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChatWindowClass)
    {
        if (ChatWindowClass->objectName().isEmpty())
            ChatWindowClass->setObjectName("ChatWindowClass");
        ChatWindowClass->resize(458, 443);
        centralWidget = new QWidget(ChatWindowClass);
        centralWidget->setObjectName("centralWidget");
        List = new QListView(centralWidget);
        List->setObjectName("List");
        List->setGeometry(QRect(0, 0, 451, 311));
        Message = new QLineEdit(centralWidget);
        Message->setObjectName("Message");
        Message->setGeometry(QRect(0, 320, 361, 61));
        Send = new QPushButton(centralWidget);
        Send->setObjectName("Send");
        Send->setGeometry(QRect(370, 320, 80, 61));
        ChatWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChatWindowClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 458, 21));
        ChatWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChatWindowClass);
        mainToolBar->setObjectName("mainToolBar");
        ChatWindowClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ChatWindowClass);
        statusBar->setObjectName("statusBar");
        ChatWindowClass->setStatusBar(statusBar);

        retranslateUi(ChatWindowClass);

        QMetaObject::connectSlotsByName(ChatWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChatWindowClass)
    {
        ChatWindowClass->setWindowTitle(QCoreApplication::translate("ChatWindowClass", "ChatWindow", nullptr));
        Send->setText(QCoreApplication::translate("ChatWindowClass", "SEND", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindowClass: public Ui_ChatWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
