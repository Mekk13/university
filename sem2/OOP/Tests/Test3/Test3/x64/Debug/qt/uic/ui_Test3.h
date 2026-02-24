/********************************************************************************
** Form generated from reading UI file 'Test3.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST3_H
#define UI_TEST3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test3Class
{
public:
    QWidget *centralWidget;
    QListView *listView;
    QPushButton *addButton;
    QLineEdit *aEdit;
    QLineEdit *bEdit;
    QLineEdit *cEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *solutionButton;
    QLineEdit *solution;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Test3Class)
    {
        if (Test3Class->objectName().isEmpty())
            Test3Class->setObjectName("Test3Class");
        Test3Class->resize(600, 400);
        centralWidget = new QWidget(Test3Class);
        centralWidget->setObjectName("centralWidget");
        listView = new QListView(centralWidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(20, 20, 256, 192));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(310, 30, 111, 24));
        aEdit = new QLineEdit(centralWidget);
        aEdit->setObjectName("aEdit");
        aEdit->setGeometry(QRect(390, 80, 113, 21));
        bEdit = new QLineEdit(centralWidget);
        bEdit->setObjectName("bEdit");
        bEdit->setGeometry(QRect(390, 110, 113, 21));
        cEdit = new QLineEdit(centralWidget);
        cEdit->setObjectName("cEdit");
        cEdit->setGeometry(QRect(390, 140, 113, 21));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 80, 21, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 110, 49, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 140, 49, 16));
        solutionButton = new QPushButton(centralWidget);
        solutionButton->setObjectName("solutionButton");
        solutionButton->setGeometry(QRect(30, 230, 111, 24));
        solution = new QLineEdit(centralWidget);
        solution->setObjectName("solution");
        solution->setGeometry(QRect(30, 270, 301, 41));
        Test3Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Test3Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        Test3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Test3Class);
        mainToolBar->setObjectName("mainToolBar");
        Test3Class->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Test3Class);
        statusBar->setObjectName("statusBar");
        Test3Class->setStatusBar(statusBar);

        retranslateUi(Test3Class);

        QMetaObject::connectSlotsByName(Test3Class);
    } // setupUi

    void retranslateUi(QMainWindow *Test3Class)
    {
        Test3Class->setWindowTitle(QCoreApplication::translate("Test3Class", "Test3", nullptr));
        addButton->setText(QCoreApplication::translate("Test3Class", "Add equation:", nullptr));
        label->setText(QCoreApplication::translate("Test3Class", "a:", nullptr));
        label_2->setText(QCoreApplication::translate("Test3Class", "b:", nullptr));
        label_3->setText(QCoreApplication::translate("Test3Class", "c:", nullptr));
        solutionButton->setText(QCoreApplication::translate("Test3Class", "Solution ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test3Class: public Ui_Test3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST3_H
