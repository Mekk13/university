/********************************************************************************
** Form generated from reading UI file 'QtWidgetsClass.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSCLASS_H
#define UI_QTWIDGETSCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsClassClass
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QProgressBar *progressBar;

    void setupUi(QWidget *QtWidgetsClassClass)
    {
        if (QtWidgetsClassClass->objectName().isEmpty())
            QtWidgetsClassClass->setObjectName("QtWidgetsClassClass");
        QtWidgetsClassClass->resize(792, 550);
        verticalLayout = new QVBoxLayout(QtWidgetsClassClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        checkBox = new QCheckBox(QtWidgetsClassClass);
        checkBox->setObjectName("checkBox");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, checkBox);

        pushButton = new QPushButton(QtWidgetsClassClass);
        pushButton->setObjectName("pushButton");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, pushButton);

        progressBar = new QProgressBar(QtWidgetsClassClass);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, progressBar);


        verticalLayout->addLayout(formLayout);


        retranslateUi(QtWidgetsClassClass);

        QMetaObject::connectSlotsByName(QtWidgetsClassClass);
    } // setupUi

    void retranslateUi(QWidget *QtWidgetsClassClass)
    {
        QtWidgetsClassClass->setWindowTitle(QCoreApplication::translate("QtWidgetsClassClass", "QtWidgetsClass", nullptr));
        checkBox->setText(QCoreApplication::translate("QtWidgetsClassClass", "YES", nullptr));
        pushButton->setText(QCoreApplication::translate("QtWidgetsClassClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsClassClass: public Ui_QtWidgetsClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSCLASS_H
