#pragma once
#include "Human.h"
#include <vector>
#include <memory>

class Controller {
private:
	std::vector<std::shared_ptr<Human>> humans;
public:
	Controller() {};
	~Controller();
	void addFamily(Family* f);
	void addPerson(Person* p);
	std::vector<std::shared_ptr<Human>> getall();
	std::vector<std::shared_ptr<Human>> getallcitizenship();
	void saveFile(std::string Filename1, std::string Filename2);

};