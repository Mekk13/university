#include "Chat.h"
#include <QStringListModel>

ChatSession::~ChatSession()
{
}

void ChatSession::addMessage(std::string user, std::string message)
{
	this->users_chats.push_back(std::make_pair(user, message));
}

std::vector<std::pair<std::string, std::string>> ChatSession::getMessages()
{
	return this->users_chats;
}


