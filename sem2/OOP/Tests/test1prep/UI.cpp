#include "UI.h"
#include <string>

UI::UI(Service serv): serv(serv)
{
}

void UI::generate_cars()
{
	this->serv.add_car("Honda", "Jazz", "Green", 2015);
	this->serv.add_car("Toyota", "Camri", "Olive", 2017);
	this->serv.add_car("Toyota", "Hilux", "Red", 2014);
	this->serv.add_car("Dacia", "1300", "White", 1970);
	this->serv.add_car("Dacia", "Logan", "Cream", 2005);
}

void UI::menu()
{
	std::cout << "    -MENU-  \n";
	std::cout << "1. Add car\n";
	std::cout << "2. Remove car\n";
	std::cout << "3. Show all cars\n";
	std::cout << "4. Show all vintage\n";
	std::cout << "0. Exit\n";
}

bool is_numeric(std::string ok) {
	for (char c : ok) {
		if (!isdigit(c))
			return false;
	}
	return true;
}

void UI::handle_add()
{
	std::string m, n, c;
	int y;
	std::cout << "Manufacturer: ";
	std::getline(std::cin, n);

	std::cout << "Model: ";
	std::getline(std::cin, m);

	std::cout << "Colour: ";
	std::getline(std::cin, c);

	std::cout << "Fabrication Year: ";
	while (true) {
		if (std::cin.peek() == '\n') {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::string mor;
		std::getline(std::cin, mor);
		if (is_numeric(mor))
		{
			y = stoi(mor);
			break;
		}
		else {
			std::cout << "Enter a valid int.\n";
			continue;
		}
	}

	int ok =this->serv.add_car(n, m, c, y);
	if (ok)
		printf("success.\n");
	else
		printf("fail.\n");
}

void UI::handle_remove()
{
	std::string m, n, c;
	int y;
	std::cout << "Model: ";
	std::getline(std::cin, m);


	std::cout << "Fabrication Year: ";
	while (true) {
		if (std::cin.peek() == '\n') {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::string mor;
		std::getline(std::cin, mor);
		if (is_numeric(mor))
		{
			y = stoi(mor);
			break;
		}
		else {
			std::cout << "Enter a valid int.\n";
			continue;
		}
	}

	int ok = this->serv.remove_car(m, y);
	if (ok)
		printf("success.\n");
	else
		printf("fail.\n");

}

void UI::handle_show_all()
{
	DynamicVector<Car> c=	 this->serv.get_all_cars_sorted();
	for (int i = 0; i < c.getSize(); i++) {
		Car car = c.getElement(i);
		show_car(car);
	}
}

void UI::handle_vintage()
{
	DynamicVector<Car> c = this->serv.get_all_vintage_sorted();
	for (int i = 0; i < c.getSize(); i++) {
		Car car = c.getElement(i);
		show_car(car);
	}
}

void UI::start()
{
	int choice;
	generate_cars();
	while (true) {
		menu();
		std::cout << "Choice: ";
		while (true) {
			if (std::cin.peek() == '\n') {
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::string mor;
			std::getline(std::cin, mor);
			if (is_numeric(mor))
			{
				choice = stoi(mor);
				break;
			}
			else {
				std::cout << "Enter a valid int.\n";
				continue;
			}
		}
		if (choice < 0 || choice >4) {
			std::cout << "Enter a valid int.\n";
			continue;
		}
		switch (choice) {
		case 0:
			return;
		case 1:
			handle_add();
			break;
		case 2:
			handle_remove();
			break;
		case 3:
			handle_show_all();
			break; 
		case 4:
			handle_vintage();
			break;
		}
	}
}

void UI::show_car(Car c)
{
	printf("%s | %s | %d | %s\n", c.getManName().c_str(), c.getModel().c_str(), c.getFabYear(), c.getColour().c_str());
}
