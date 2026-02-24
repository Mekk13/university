#include "Ui.h"
#include <stdio.h>

Ui::~Ui()
{
	delete s;
}

void Ui::addAppliance()
{
	std::cout << "Enter appliance type (1 for Refrigerator, 2 for DishWasher): ";
	int type;
	std::cin >> type;
	if (type != 1 && type != 2) {
		std::cout << "Wrong input.\n";
		return;
	}
	std::string id;
	std::cout << "Enter appliance id: ";
	std::cin >> id;
	if (type == 1) {
		std::cout << "Enter electricity usage class (A++, A): ";
		std::string electricityUsageClass;
		std::cin >> electricityUsageClass;
		std::cout << "Has freezer? (1 for yes, 0 for no): ";
		bool hasFreezer;
		std::cin >> hasFreezer;
		Appliance* a = new Refrigerator(id, electricityUsageClass, hasFreezer);
		this->s->addAppliance(a);
		std::cout << "Refrigerator added successfully!" << std::endl;
	}
	else if (type==2){
		std::cout << "Enter consumed electricity for one hour: ";
		double consumedElectricityForOneHour;
		std::cin >> consumedElectricityForOneHour;
		Appliance* a = new DishWasher(id, consumedElectricityForOneHour);
		this->s->addAppliance(a);
		std::cout << "DishWasher added successfully!" << std::endl;
	}
	else {
		std::cout << "Invalid appliance type!" << std::endl;
		return;
	}
}

void Ui::showAll()
{
	std::vector<std::shared_ptr<Appliance>> appliances = this->s->getAllAppliances();
	for (auto& a : appliances) {
		std::cout << a->toString() << std::endl;
	}
}

void Ui::showIneffiecient()
{
	std::vector<std::shared_ptr<Appliance>> appliances = this->s->getAllInefficient();
	for (auto& a : appliances) {
		std::cout << a->toString() << std::endl;
	}
}

void Ui::saveToFile()
{
	std::cout << "Save appliances with electricity less than: ";
	double val;
	std::cin >> val;
	std::string fileName;
	std::cout << "Enter file name to save: ";
	std::cin >> fileName;
	this->s->writeToFile(fileName,val);
	std::cout << "Data saved to " << fileName << std::endl;
}

void Ui::menu()
{
	std::cout << "1. Add Appliance" << std::endl;
	std::cout << "2. Show All Appliances" << std::endl;
	std::cout << "3. Show Inefficient Appliances" << std::endl;
	std::cout << "4. Save to File" << std::endl;
	std::cout << "5. Exit" << std::endl;
	
}

void Ui::start()
{
	this->s->addAppliance(new Refrigerator("1", "A++", true));
	this->s->addAppliance(new Refrigerator("2", "A", false));
	this->s->addAppliance(new DishWasher("3", 1.5));
	this->s->addAppliance(new DishWasher("4", 7.0));
	this->s->addAppliance(new Refrigerator("5", "A++", false));
	int choice;
	while (1) {
		this->menu();
		std::cout << "choice: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			this->addAppliance();
			break;
		case 2:
			this->showAll();
			break;
		case 3:
			this->showIneffiecient();
			break;
		case 4:
			this->saveToFile();
			break;
		case 5:
			exit(0);
		default:
			std::cout << "Invalid choice!" << std::endl;
		}
	}
}
