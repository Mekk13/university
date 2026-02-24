/********************************************************************************
** Form generated from reading UI file 'Admin_Window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_WINDOW_H
#define UI_ADMIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin_WindowClass
{
public:
    QListWidget *item_list;
    QComboBox *comboBox;
    QPushButton *add_button;
    QLineEdit *name_edit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *category_edit;
    QLabel *label_4;
    QLineEdit *price_edit;

    void setupUi(QWidget *Admin_WindowClass)
    {
        if (Admin_WindowClass->objectName().isEmpty())
            Admin_WindowClass->setObjectName("Admin_WindowClass");
        Admin_WindowClass->resize(600, 400);
        item_list = new QListWidget(Admin_WindowClass);
        item_list->setObjectName("item_list");
        item_list->setGeometry(QRect(30, 100, 256, 261));
        comboBox = new QComboBox(Admin_WindowClass);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(40, 40, 231, 24));
        add_button = new QPushButton(Admin_WindowClass);
        add_button->setObjectName("add_button");
        add_button->setGeometry(QRect(480, 230, 80, 24));
        name_edit = new QLineEdit(Admin_WindowClass);
        name_edit->setObjectName("name_edit");
        name_edit->setGeometry(QRect(410, 100, 113, 24));
        label = new QLabel(Admin_WindowClass);
        label->setObjectName("label");
        label->setGeometry(QRect(340, 60, 121, 16));
        label_2 = new QLabel(Admin_WindowClass);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(340, 100, 49, 21));
        label_3 = new QLabel(Admin_WindowClass);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(340, 140, 51, 21));
        category_edit = new QLineEdit(Admin_WindowClass);
        category_edit->setObjectName("category_edit");
        category_edit->setGeometry(QRect(410, 140, 113, 24));
        label_4 = new QLabel(Admin_WindowClass);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(340, 180, 49, 21));
        price_edit = new QLineEdit(Admin_WindowClass);
        price_edit->setObjectName("price_edit");
        price_edit->setGeometry(QRect(410, 180, 113, 24));

        retranslateUi(Admin_WindowClass);

        QMetaObject::connectSlotsByName(Admin_WindowClass);
    } // setupUi

    void retranslateUi(QWidget *Admin_WindowClass)
    {
        Admin_WindowClass->setWindowTitle(QCoreApplication::translate("Admin_WindowClass", "Admin_Window", nullptr));
        add_button->setText(QCoreApplication::translate("Admin_WindowClass", "Add item", nullptr));
        label->setText(QCoreApplication::translate("Admin_WindowClass", "Add an item:", nullptr));
        label_2->setText(QCoreApplication::translate("Admin_WindowClass", "Name:", nullptr));
        label_3->setText(QCoreApplication::translate("Admin_WindowClass", "Category:", nullptr));
        label_4->setText(QCoreApplication::translate("Admin_WindowClass", "Price:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin_WindowClass: public Ui_Admin_WindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_WINDOW_H
