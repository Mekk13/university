/********************************************************************************
** Form generated from reading UI file 'User_Window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_WINDOW_H
#define UI_USER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_User_WindowClass
{
public:
    QListWidget *item_list;
    QComboBox *comboBox;
    QPushButton *bid_button;
    QLineEdit *bid_line_edit;
    QLabel *label;

    void setupUi(QWidget *User_WindowClass)
    {
        if (User_WindowClass->objectName().isEmpty())
            User_WindowClass->setObjectName("User_WindowClass");
        User_WindowClass->resize(600, 400);
        item_list = new QListWidget(User_WindowClass);
        item_list->setObjectName("item_list");
        item_list->setGeometry(QRect(20, 80, 256, 261));
        comboBox = new QComboBox(User_WindowClass);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(30, 30, 231, 24));
        bid_button = new QPushButton(User_WindowClass);
        bid_button->setObjectName("bid_button");
        bid_button->setGeometry(QRect(310, 250, 80, 24));
        bid_line_edit = new QLineEdit(User_WindowClass);
        bid_line_edit->setObjectName("bid_line_edit");
        bid_line_edit->setGeometry(QRect(310, 210, 113, 24));
        label = new QLabel(User_WindowClass);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 180, 71, 16));

        retranslateUi(User_WindowClass);

        QMetaObject::connectSlotsByName(User_WindowClass);
    } // setupUi

    void retranslateUi(QWidget *User_WindowClass)
    {
        User_WindowClass->setWindowTitle(QCoreApplication::translate("User_WindowClass", "User_Window", nullptr));
        bid_button->setText(QCoreApplication::translate("User_WindowClass", "Place bid", nullptr));
        label->setText(QCoreApplication::translate("User_WindowClass", "Bid for item:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User_WindowClass: public Ui_User_WindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_WINDOW_H
