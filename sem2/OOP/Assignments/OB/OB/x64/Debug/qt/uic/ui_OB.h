/********************************************************************************
** Form generated from reading UI file 'OB.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OB_H
#define UI_OB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OBClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OBClass)
    {
        if (OBClass->objectName().isEmpty())
            OBClass->setObjectName("OBClass");
        OBClass->resize(600, 400);
        menuBar = new QMenuBar(OBClass);
        menuBar->setObjectName("menuBar");
        OBClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OBClass);
        mainToolBar->setObjectName("mainToolBar");
        OBClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(OBClass);
        centralWidget->setObjectName("centralWidget");
        OBClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(OBClass);
        statusBar->setObjectName("statusBar");
        OBClass->setStatusBar(statusBar);

        retranslateUi(OBClass);

        QMetaObject::connectSlotsByName(OBClass);
    } // setupUi

    void retranslateUi(QMainWindow *OBClass)
    {
        OBClass->setWindowTitle(QCoreApplication::translate("OBClass", "OB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OBClass: public Ui_OBClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OB_H
