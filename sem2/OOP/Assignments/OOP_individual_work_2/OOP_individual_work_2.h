#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OOP_individual_work_2.h"

class OOP_individual_work_2 : public QMainWindow
{
    Q_OBJECT

public:
    OOP_individual_work_2(QWidget *parent = nullptr);
    ~OOP_individual_work_2();

private:
    Ui::OOP_individual_work_2Class ui;
};

