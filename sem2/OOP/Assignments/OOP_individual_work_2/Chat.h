#pragma once
#include "Subject.h"
#include <QWidget>

class ChatSession : public Subject {
public:
	ChatSession()=default;
	~ChatSession();
	void addMessage(std::string user, std::string message);
	std::vector < std::pair<std::string, std::string>> getMessages();
private:
	std::vector < std::pair<std::string, std::string>> users_chats;
};


