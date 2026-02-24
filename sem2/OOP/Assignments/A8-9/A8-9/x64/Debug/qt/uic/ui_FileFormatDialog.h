/********************************************************************************
** Form generated from reading UI file 'FileFormatDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEFORMATDIALOG_H
#define UI_FILEFORMATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FileDialogUser
{
public:
    QLabel *label;
    QPushButton *CSVButton;
    QPushButton *HTMLButton;

    void setupUi(QDialog *FileDialogUser)
    {
        if (FileDialogUser->objectName().isEmpty())
            FileDialogUser->setObjectName("FileDialogUser");
        FileDialogUser->resize(349, 110);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FileDialogUser->sizePolicy().hasHeightForWidth());
        FileDialogUser->setSizePolicy(sizePolicy);
        label = new QLabel(FileDialogUser);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 271, 16));
        CSVButton = new QPushButton(FileDialogUser);
        CSVButton->setObjectName("CSVButton");
        CSVButton->setGeometry(QRect(80, 60, 75, 24));
        HTMLButton = new QPushButton(FileDialogUser);
        HTMLButton->setObjectName("HTMLButton");
        HTMLButton->setGeometry(QRect(180, 60, 75, 24));

        retranslateUi(FileDialogUser);

        QMetaObject::connectSlotsByName(FileDialogUser);
    } // setupUi

    void retranslateUi(QDialog *FileDialogUser)
    {
        FileDialogUser->setWindowTitle(QCoreApplication::translate("FileDialogUser", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FileDialogUser", "Pick a type of file in which to save your watchlist:", nullptr));
        CSVButton->setText(QCoreApplication::translate("FileDialogUser", "CSV", nullptr));
        HTMLButton->setText(QCoreApplication::translate("FileDialogUser", "HTML", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileDialogUser: public Ui_FileDialogUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEFORMATDIALOG_H
