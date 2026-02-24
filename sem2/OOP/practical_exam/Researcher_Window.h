#pragma once

#include <QWidget>
#include "ui_Researcher_Window.h"
#include "Service.h"
#include "MyModel.h"

class Researcher_Window : public QWidget
{
	Q_OBJECT

public:
	Researcher_Window(Service& serv, TableModel* model,const std::string& name, const std::string& pos,QWidget *parent = nullptr);
	~Researcher_Window();

private:
	Ui::Researcher_WindowClass ui;
	Service& serv;
	TableModel* model;
	string name;
	string pos;

private slots:
	void populateTable();
	void onAddPushed();
	void onAcceptPushed();
	void onSavePushed();
	void onDevelopPushed();
};

