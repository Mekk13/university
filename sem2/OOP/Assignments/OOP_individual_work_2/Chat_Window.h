#pragma once

#include <QWidget>
#include "ui_Chat_Window.h"
#include "Chat.h"
#include "Subject.h"
#include "Observer.h"

class Chat_Window : public QWidget,public Observer
{
	Q_OBJECT

public:
	Chat_Window(std::string user, ChatSession* ses,QWidget *parent = nullptr);
	~Chat_Window();

private:
	Ui::Chat_WindowClass ui;
	std::string user;
	ChatSession* session;
	void update() override;

private slots:
	void populate_listView();
	void onSendPushed();

};

