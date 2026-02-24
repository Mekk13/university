#include "Chat_Window.h"
#include <QStringListModel>

Chat_Window::Chat_Window(std::string user,ChatSession *ses,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->user = user;
	this->setWindowTitle(QString::fromStdString(this->user));
	session = ses;
	session->resgisterOberver(this);
	connect(ui.Send, &QPushButton::clicked, this, &Chat_Window::onSendPushed);
	populate_listView();
	
}

Chat_Window::~Chat_Window()
{}

void Chat_Window::update()
{
	populate_listView();
}

void Chat_Window::populate_listView()
{
	ui.List->clear(); // Clear previous items
	for (const auto& message : session->getMessages()) {
		QString formatted = QString::fromStdString(message.first + ": " + message.second);
		QListWidgetItem* item = new QListWidgetItem(formatted, ui.List);
		if (message.first == user) {
			item->setTextAlignment(Qt::AlignRight);
		}
		else {
			item->setTextAlignment(Qt::AlignLeft);
		}
	}
	ui.List->scrollToBottom();
}


void Chat_Window::onSendPushed()
{
	std::string message = ui.Message->text().toStdString();
	if (!message.empty()) {
		session->addMessage(user, message);
		session->notify();
		ui.Message->clear();
	}
	ui.Message->setFocus();
	ui.List->scrollToBottom(); 
	ui.List->update(); 
}

