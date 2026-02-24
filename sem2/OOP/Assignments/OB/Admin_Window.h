#pragma once

#include <QWidget>
#include "ui_Admin_Window.h"
#include "Observer.h"
#include "Service.h"

class Admin_Window : public QWidget,public Observer
{
	Q_OBJECT

public:
	Admin_Window(User user, Service* serv,QWidget *parent = nullptr);
	~Admin_Window();

private:
	Ui::Admin_WindowClass ui;
	Service* service;
	User user;
	void update() override;
	void populate_combo();

private slots:
	void populateItemList();
	void on_add_clicked();
	void on_selected_item();

};

