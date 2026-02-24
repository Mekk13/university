#pragma once
#include "Controller.h"

class UI {
private:
	Controller* c;
public:
	UI() : c(new Controller()) {};
	~UI();
	void addFamily();
	void addPerson();
	void showAll();
	void showAllCitizenship();
	void saveFile();
	void menu();
	void start();
};