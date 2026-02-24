#include "Car.h"

Car::Car(std::string man_name, std::string model, std::string colour, int fab_year):man_name(man_name), model(model), colour(colour),fab_year(fab_year)
{}

std::string Car::getManName()
{
	return this->man_name;
}

std::string Car::getModel()
{
	return this->model;
}

std::string Car::getColour()
{
	return this->colour;
}

int Car::getFabYear()
{
	return this->fab_year;
}

void Car::setManName(std::string name)
{
	this->man_name = name;
}

void Car::setModel(std::string model)
{
	this->model = model;
}

void Car::setColour(std::string colour)
{
	this->colour = colour;
}

void Car::setFabYear(int year)
{
	this->fab_year = year;
}

bool Car::operator==(const Car& car_to_compare)
{
	return (this->model == car_to_compare.model && this->fab_year == car_to_compare.fab_year);
}

void Car::operator=(const Car& car_to_copy)
{
	this->colour = car_to_copy.colour;
	this->fab_year = car_to_copy.fab_year;
	this->man_name = car_to_copy.man_name;
	this->model = car_to_copy.model;
}

