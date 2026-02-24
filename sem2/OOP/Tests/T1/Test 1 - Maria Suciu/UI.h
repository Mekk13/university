#pragma once 
#include "Service.h"

class UI {
private:
	Service serv;
public:
	UI();
	UI(Service s);
	void handle_add();
	void handle_show();
	void handle_show_keyword();
	void start();
	void menu();
	void add_5_movies();
};