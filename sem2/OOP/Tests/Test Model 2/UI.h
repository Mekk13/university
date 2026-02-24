#pragma once
#include "Person.h"

class UI {
private:
	Person& p;
public:
	UI() : p(*(new Person("John Doe"))) {};
	void add_analysis();
	void show_all();
	void show_if_ill();
	void save_to_file();
	void start();
	void menu();
};