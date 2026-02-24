#pragma once
#include <iostream>

class Car {
private:
	std::string man_name, model, colour;
	int fab_year;
public:
	Car(std::string man_name, std::string model, std::string colour, int fab_year);
	Car() :man_name(""), model(""), colour(""), fab_year(0) {}
	//getters
	std::string getManName();
	std::string getModel();
	std::string getColour();
	int getFabYear();

	//setters
	void setManName(std::string name);
	void setModel(std::string model);
	void setColour(std::string colour);
	void setFabYear(int year);

	bool operator==(const Car& car_to_compare);
	void operator=(const Car& car_to_copy);
};