/********************************************************************************
** Form generated from reading UI file 'Researcher_Window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESEARCHER_WINDOW_H
#define UI_RESEARCHER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Researcher_WindowClass
{
public:
    QTableView *tableView;
    QLabel *label;
    QLineEdit *position_edit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *titleEdit;
    QLabel *label_4;
    QLineEdit *descrEdit;
    QLabel *label_5;
    QLineEdit *DurationEdit;
    QPushButton *addButton;
    QPushButton *acceptButton;
    QPushButton *seniorButton;
    QPushButton *developButton;

    void setupUi(QWidget *Researcher_WindowClass)
    {
        if (Researcher_WindowClass->objectName().isEmpty())
            Researcher_WindowClass->setObjectName("Researcher_WindowClass");
        Researcher_WindowClass->resize(710, 477);
        tableView = new QTableView(Researcher_WindowClass);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 50, 421, 321));
        label = new QLabel(Researcher_WindowClass);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 49, 16));
        position_edit = new QLineEdit(Researcher_WindowClass);
        position_edit->setObjectName("position_edit");
        position_edit->setGeometry(QRect(80, 20, 113, 24));
        label_2 = new QLabel(Researcher_WindowClass);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(450, 50, 101, 16));
        label_3 = new QLabel(Researcher_WindowClass);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(450, 90, 49, 16));
        titleEdit = new QLineEdit(Researcher_WindowClass);
        titleEdit->setObjectName("titleEdit");
        titleEdit->setGeometry(QRect(520, 80, 113, 31));
        label_4 = new QLabel(Researcher_WindowClass);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(450, 140, 49, 16));
        descrEdit = new QLineEdit(Researcher_WindowClass);
        descrEdit->setObjectName("descrEdit");
        descrEdit->setGeometry(QRect(520, 130, 113, 31));
        label_5 = new QLabel(Researcher_WindowClass);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(450, 190, 49, 16));
        DurationEdit = new QLineEdit(Researcher_WindowClass);
        DurationEdit->setObjectName("DurationEdit");
        DurationEdit->setGeometry(QRect(520, 180, 113, 31));
        addButton = new QPushButton(Researcher_WindowClass);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(560, 230, 80, 24));
        acceptButton = new QPushButton(Researcher_WindowClass);
        acceptButton->setObjectName("acceptButton");
        acceptButton->setGeometry(QRect(460, 310, 151, 24));
        seniorButton = new QPushButton(Researcher_WindowClass);
        seniorButton->setObjectName("seniorButton");
        seniorButton->setGeometry(QRect(580, 420, 80, 24));
        developButton = new QPushButton(Researcher_WindowClass);
        developButton->setObjectName("developButton");
        developButton->setGeometry(QRect(430, 420, 80, 24));

        retranslateUi(Researcher_WindowClass);

        QMetaObject::connectSlotsByName(Researcher_WindowClass);
    } // setupUi

    void retranslateUi(QWidget *Researcher_WindowClass)
    {
        Researcher_WindowClass->setWindowTitle(QCoreApplication::translate("Researcher_WindowClass", "Researcher_Window", nullptr));
        label->setText(QCoreApplication::translate("Researcher_WindowClass", "Position:", nullptr));
        label_2->setText(QCoreApplication::translate("Researcher_WindowClass", "Add idea:", nullptr));
        label_3->setText(QCoreApplication::translate("Researcher_WindowClass", "title:", nullptr));
        label_4->setText(QCoreApplication::translate("Researcher_WindowClass", "descr.:", nullptr));
        label_5->setText(QCoreApplication::translate("Researcher_WindowClass", "Duration:", nullptr));
        addButton->setText(QCoreApplication::translate("Researcher_WindowClass", "Add idea!", nullptr));
        acceptButton->setText(QCoreApplication::translate("Researcher_WindowClass", "Accept Selected Idea", nullptr));
        seniorButton->setText(QCoreApplication::translate("Researcher_WindowClass", "SAVE ALL", nullptr));
        developButton->setText(QCoreApplication::translate("Researcher_WindowClass", "DEVELOP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Researcher_WindowClass: public Ui_Researcher_WindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESEARCHER_WINDOW_H
