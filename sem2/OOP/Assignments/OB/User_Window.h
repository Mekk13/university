#pragma once

#include <QWidget>
#include "ui_User_Window.h"
#include "Observer.h"
#include "Repo.h"
#include "Service.h"

class User_Window : public QWidget, public Observer
{
	Q_OBJECT

public:
	User_Window(User user,Service* serv,QWidget *parent = nullptr);
	~User_Window();

private:
	Ui::User_WindowClass ui;
	User user;
	Service* service;
	void update() override;

	void populate_combo();

private slots:
	void populateItemList();
	void on_bid_pushed();
};

