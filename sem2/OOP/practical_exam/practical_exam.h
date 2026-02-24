#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_practical_exam.h"

class practical_exam : public QMainWindow
{
    Q_OBJECT

public:
    practical_exam(QWidget *parent = nullptr);
    ~practical_exam();

private:
    Ui::practical_examClass ui;
};

