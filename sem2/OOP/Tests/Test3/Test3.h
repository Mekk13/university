#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test3.h"
#include <QListView>
#include <QPushButton>
#include <vector>
#include "Repo.h"

class Test3 : public QMainWindow
{
    Q_OBJECT

public:
    Test3(QWidget *parent = nullptr);
    ~Test3();

private:
    Ui::Test3Class ui;
    Repo repo;

private slots:
    void readFromFile();
    void populateList();
    void onaddpushed();
	void onsolutionpushed();
};

