#include "Controller.h"
#include <fstream>
#include <iostream>

Controller::~Controller()
{
	
}

void Controller::addFamily(Family* f)
{
	std::shared_ptr<Family> family = std::make_shared<Family>(*f);
	this->humans.push_back(family);
}

void Controller::addPerson(Person* p)
{
	std::shared_ptr<Person> pers = std::make_shared<Person>(*p);
	this->humans.push_back(pers);
}

std::vector<std::shared_ptr<Human>> Controller::getall()
{
	return this->humans;
}

std::vector<std::shared_ptr<Human>> Controller::getallcitizenship()
{
	std::vector<std::shared_ptr<Human>> filtered;
	for (auto& a : this->humans) {
		if (a->receiveCitizenship()) {
			filtered.push_back(a);
		}
	}
	return filtered;
}

void Controller::saveFile(std::string Filename1, std::string Filename2)
{
	std::vector<std::shared_ptr<Human>> filtered = this->getallcitizenship();
	std::vector<std::shared_ptr<Human>> all = this->getall();
	std::vector<std::shared_ptr<Human>> filtered2;
	for (auto& a : all) {
		if (a->mustBeDeported())
			filtered2.push_back(a);
	}
	std::fstream fout1(Filename1);
	std::fstream fout2(Filename2);
	for (auto& a : filtered) {
		fout1 << a->toString() << std::endl;
	}
	for (auto& a : filtered2) {
		fout2 << a->toString() << std::endl;
	}
}

