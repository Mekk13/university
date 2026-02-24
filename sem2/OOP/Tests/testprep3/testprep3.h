#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_testprep3.h"
#include <vector>


struct Bill {
    QString name, serialnr;
    double sum;
    bool ispaid;
};
class testprep3 : public QMainWindow
{
    Q_OBJECT

public:
    testprep3(QWidget *parent = nullptr);
    ~testprep3();

private:
	Ui::testprep3Class ui;
    std::vector<Bill> bills;

private slots:

    void readFromFile();
    void populateList();
    void onPaidChecked();
    void onUnPaidChecked();
    void onButtonPressed();

};

