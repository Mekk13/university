#pragma once
#include "Service.h"

class UI {
private: 
	Service serv;
public:
	UI(Service serv);
	void generate_cars();
	void menu();
	void handle_add();
	void handle_remove();
	void handle_show_all();
	void handle_vintage();
	void start();
	void show_car(Car c);

};