#pragma once
#include "Service.h"

class Ui {
private:
	Service* s;
public:
	Ui() : s(new Service()) {};
	~Ui();
	void addAppliance();
	void showAll();
	void showIneffiecient();
	void saveToFile();
	void menu();
	void start();
};