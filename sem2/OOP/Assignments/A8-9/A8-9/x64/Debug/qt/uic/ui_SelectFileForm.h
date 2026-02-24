/********************************************************************************
** Form generated from reading UI file 'SelectFileForm.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTFILEFORM_H
#define UI_SELECTFILEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SelectFileFormClass
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *HTMLButton;
    QPushButton *CSVButton;

    void setupUi(QDialog *SelectFileFormClass)
    {
        if (SelectFileFormClass->objectName().isEmpty())
            SelectFileFormClass->setObjectName("SelectFileFormClass");
        SelectFileFormClass->resize(380, 113);
        verticalLayout = new QVBoxLayout(SelectFileFormClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(SelectFileFormClass);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        HTMLButton = new QPushButton(SelectFileFormClass);
        HTMLButton->setObjectName("HTMLButton");

        verticalLayout->addWidget(HTMLButton);

        CSVButton = new QPushButton(SelectFileFormClass);
        CSVButton->setObjectName("CSVButton");

        verticalLayout->addWidget(CSVButton);


        retranslateUi(SelectFileFormClass);

        QMetaObject::connectSlotsByName(SelectFileFormClass);
    } // setupUi

    void retranslateUi(QDialog *SelectFileFormClass)
    {
        SelectFileFormClass->setWindowTitle(QCoreApplication::translate("SelectFileFormClass", "SelectFileForm", nullptr));
        label->setText(QCoreApplication::translate("SelectFileFormClass", "Pick the file in which you want to save your Watchlist:", nullptr));
        HTMLButton->setText(QCoreApplication::translate("SelectFileFormClass", "HTML", nullptr));
        CSVButton->setText(QCoreApplication::translate("SelectFileFormClass", "CSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectFileFormClass: public Ui_SelectFileFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTFILEFORM_H
