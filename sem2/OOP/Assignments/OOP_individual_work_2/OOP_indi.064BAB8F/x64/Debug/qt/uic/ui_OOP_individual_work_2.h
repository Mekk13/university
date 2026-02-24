/********************************************************************************
** Form generated from reading UI file 'OOP_individual_work_2.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OOP_INDIVIDUAL_WORK_2_H
#define UI_OOP_INDIVIDUAL_WORK_2_H

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

class Ui_OOP_individual_work_2Class
{
public:
    QWidget *centralWidget;
    QListView *List;
    QLineEdit *Message;
    QPushButton *Send;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OOP_individual_work_2Class)
    {
        if (OOP_individual_work_2Class->objectName().isEmpty())
            OOP_individual_work_2Class->setObjectName("OOP_individual_work_2Class");
        OOP_individual_work_2Class->resize(452, 444);
        centralWidget = new QWidget(OOP_individual_work_2Class);
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
        OOP_individual_work_2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OOP_individual_work_2Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 452, 21));
        OOP_individual_work_2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OOP_individual_work_2Class);
        mainToolBar->setObjectName("mainToolBar");
        OOP_individual_work_2Class->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OOP_individual_work_2Class);
        statusBar->setObjectName("statusBar");
        OOP_individual_work_2Class->setStatusBar(statusBar);

        retranslateUi(OOP_individual_work_2Class);

        QMetaObject::connectSlotsByName(OOP_individual_work_2Class);
    } // setupUi

    void retranslateUi(QMainWindow *OOP_individual_work_2Class)
    {
        OOP_individual_work_2Class->setWindowTitle(QCoreApplication::translate("OOP_individual_work_2Class", "OOP_individual_work_2", nullptr));
        Send->setText(QCoreApplication::translate("OOP_individual_work_2Class", "SEND", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OOP_individual_work_2Class: public Ui_OOP_individual_work_2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OOP_INDIVIDUAL_WORK_2_H
