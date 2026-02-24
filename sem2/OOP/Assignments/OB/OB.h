#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OB.h"

class OB : public QMainWindow
{
    Q_OBJECT

public:
    OB(QWidget *parent = nullptr);
    ~OB();

private:
    Ui::OBClass ui;
};

