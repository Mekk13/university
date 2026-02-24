/********************************************************************************
** Form generated from reading UI file 'UserGUI.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERGUI_H
#define UI_USERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserGUI
{
public:
    QPushButton *SearchByGenreButton;
    QPushButton *NextMovieFromWatchlistButton;
    QPushButton *AddToWatchlistButton;
    QPushButton *DeleteFromWatchlistButton;
    QLabel *label;
    QLineEdit *GenreLineEdit;
    QTextEdit *DisplayMovieTextEdit;
    QLabel *label_2;
    QListView *WatchlistView;
    QPushButton *LikeMovieButton;
    QPushButton *OpenWatchlistInSavedFileButton;
    QPushButton *tableViewButton;

    void setupUi(QWidget *UserGUI)
    {
        if (UserGUI->objectName().isEmpty())
            UserGUI->setObjectName("UserGUI");
        UserGUI->resize(790, 590);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserGUI->sizePolicy().hasHeightForWidth());
        UserGUI->setSizePolicy(sizePolicy);
        SearchByGenreButton = new QPushButton(UserGUI);
        SearchByGenreButton->setObjectName("SearchByGenreButton");
        SearchByGenreButton->setGeometry(QRect(190, 40, 75, 24));
        NextMovieFromWatchlistButton = new QPushButton(UserGUI);
        NextMovieFromWatchlistButton->setObjectName("NextMovieFromWatchlistButton");
        NextMovieFromWatchlistButton->setGeometry(QRect(330, 80, 75, 31));
        AddToWatchlistButton = new QPushButton(UserGUI);
        AddToWatchlistButton->setObjectName("AddToWatchlistButton");
        AddToWatchlistButton->setGeometry(QRect(430, 80, 121, 31));
        DeleteFromWatchlistButton = new QPushButton(UserGUI);
        DeleteFromWatchlistButton->setObjectName("DeleteFromWatchlistButton");
        DeleteFromWatchlistButton->setGeometry(QRect(500, 270, 75, 24));
        label = new QLabel(UserGUI);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 71, 16));
        GenreLineEdit = new QLineEdit(UserGUI);
        GenreLineEdit->setObjectName("GenreLineEdit");
        GenreLineEdit->setGeometry(QRect(20, 40, 151, 21));
        DisplayMovieTextEdit = new QTextEdit(UserGUI);
        DisplayMovieTextEdit->setObjectName("DisplayMovieTextEdit");
        DisplayMovieTextEdit->setGeometry(QRect(20, 80, 291, 141));
        DisplayMovieTextEdit->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                            stop:0 #c2f0c2, stop:1 #ffffff);\n"
""));
        label_2 = new QLabel(UserGUI);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 240, 81, 16));
        WatchlistView = new QListView(UserGUI);
        WatchlistView->setObjectName("WatchlistView");
        WatchlistView->setGeometry(QRect(20, 270, 461, 301));
        LikeMovieButton = new QPushButton(UserGUI);
        LikeMovieButton->setObjectName("LikeMovieButton");
        LikeMovieButton->setGeometry(QRect(500, 310, 75, 24));
        OpenWatchlistInSavedFileButton = new QPushButton(UserGUI);
        OpenWatchlistInSavedFileButton->setObjectName("OpenWatchlistInSavedFileButton");
        OpenWatchlistInSavedFileButton->setGeometry(QRect(500, 350, 131, 24));
        tableViewButton = new QPushButton(UserGUI);
        tableViewButton->setObjectName("tableViewButton");
        tableViewButton->setGeometry(QRect(500, 400, 141, 24));

        retranslateUi(UserGUI);

        QMetaObject::connectSlotsByName(UserGUI);
    } // setupUi

    void retranslateUi(QWidget *UserGUI)
    {
        UserGUI->setWindowTitle(QCoreApplication::translate("UserGUI", "Form", nullptr));
        SearchByGenreButton->setText(QCoreApplication::translate("UserGUI", "Search", nullptr));
        NextMovieFromWatchlistButton->setText(QCoreApplication::translate("UserGUI", "Next", nullptr));
        AddToWatchlistButton->setText(QCoreApplication::translate("UserGUI", "Add To Watchlist", nullptr));
        DeleteFromWatchlistButton->setText(QCoreApplication::translate("UserGUI", "Delete", nullptr));
        label->setText(QCoreApplication::translate("UserGUI", "Pick a genre:", nullptr));
        label_2->setText(QCoreApplication::translate("UserGUI", "Watchlist: ", nullptr));
        LikeMovieButton->setText(QCoreApplication::translate("UserGUI", "Like", nullptr));
        OpenWatchlistInSavedFileButton->setText(QCoreApplication::translate("UserGUI", "Open in Saved FIle", nullptr));
        tableViewButton->setText(QCoreApplication::translate("UserGUI", "TableView Watchlist UI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserGUI: public Ui_UserGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERGUI_H
