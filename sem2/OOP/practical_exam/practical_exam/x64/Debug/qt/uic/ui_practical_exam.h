/********************************************************************************
** Form generated from reading UI file 'practical_exam.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTICAL_EXAM_H
#define UI_PRACTICAL_EXAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_practical_examClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *practical_examClass)
    {
        if (practical_examClass->objectName().isEmpty())
            practical_examClass->setObjectName("practical_examClass");
        practical_examClass->resize(600, 400);
        menuBar = new QMenuBar(practical_examClass);
        menuBar->setObjectName("menuBar");
        practical_examClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(practical_examClass);
        mainToolBar->setObjectName("mainToolBar");
        practical_examClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(practical_examClass);
        centralWidget->setObjectName("centralWidget");
        practical_examClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(practical_examClass);
        statusBar->setObjectName("statusBar");
        practical_examClass->setStatusBar(statusBar);

        retranslateUi(practical_examClass);

        QMetaObject::connectSlotsByName(practical_examClass);
    } // setupUi

    void retranslateUi(QMainWindow *practical_examClass)
    {
        practical_examClass->setWindowTitle(QCoreApplication::translate("practical_examClass", "practical_exam", nullptr));
    } // retranslateUi

};

namespace Ui {
    class practical_examClass: public Ui_practical_examClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICAL_EXAM_H
