/********************************************************************************
** Form generated from reading UI file 'testprep3.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTPREP3_H
#define UI_TESTPREP3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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

class Ui_testprep3Class
{
public:
    QWidget *centralWidget;
    QListView *listViewbills;
    QPushButton *pushButton;
    QLineEdit *company;
    QCheckBox *PaidCheckBox;
    QCheckBox *UnpaidCheckBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *OwedSum;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *testprep3Class)
    {
        if (testprep3Class->objectName().isEmpty())
            testprep3Class->setObjectName("testprep3Class");
        testprep3Class->resize(532, 351);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(testprep3Class->sizePolicy().hasHeightForWidth());
        testprep3Class->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(testprep3Class);
        centralWidget->setObjectName("centralWidget");
        listViewbills = new QListView(centralWidget);
        listViewbills->setObjectName("listViewbills");
        listViewbills->setGeometry(QRect(20, 20, 256, 271));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 200, 91, 24));
        company = new QLineEdit(centralWidget);
        company->setObjectName("company");
        company->setGeometry(QRect(290, 170, 113, 21));
        PaidCheckBox = new QCheckBox(centralWidget);
        PaidCheckBox->setObjectName("PaidCheckBox");
        PaidCheckBox->setGeometry(QRect(300, 40, 75, 20));
        UnpaidCheckBox = new QCheckBox(centralWidget);
        UnpaidCheckBox->setObjectName("UnpaidCheckBox");
        UnpaidCheckBox->setGeometry(QRect(300, 70, 75, 20));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 20, 49, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 150, 131, 16));
        OwedSum = new QLineEdit(centralWidget);
        OwedSum->setObjectName("OwedSum");
        OwedSum->setGeometry(QRect(290, 240, 113, 21));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(290, 270, 113, 21));
        testprep3Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(testprep3Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 532, 22));
        testprep3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(testprep3Class);
        mainToolBar->setObjectName("mainToolBar");
        testprep3Class->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(testprep3Class);
        statusBar->setObjectName("statusBar");
        testprep3Class->setStatusBar(statusBar);

        retranslateUi(testprep3Class);

        QMetaObject::connectSlotsByName(testprep3Class);
    } // setupUi

    void retranslateUi(QMainWindow *testprep3Class)
    {
        testprep3Class->setWindowTitle(QCoreApplication::translate("testprep3Class", "testprep3", nullptr));
        pushButton->setText(QCoreApplication::translate("testprep3Class", "Calculate Total:", nullptr));
        PaidCheckBox->setText(QCoreApplication::translate("testprep3Class", "Paid Bills", nullptr));
        UnpaidCheckBox->setText(QCoreApplication::translate("testprep3Class", "Unpaid Bills", nullptr));
        label->setText(QCoreApplication::translate("testprep3Class", "Show:", nullptr));
        label_2->setText(QCoreApplication::translate("testprep3Class", "Insert company name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testprep3Class: public Ui_testprep3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTPREP3_H
