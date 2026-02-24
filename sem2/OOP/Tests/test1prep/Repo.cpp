#include "Repo.h"

Repository::Repository(DynamicVector<Car> cars): AllCars(cars)
{
}

DynamicVector<Car> Repository::get_all_cars()
{
	return this->AllCars;
}

/// <summary>
/// Adds a given car to the dynamic array that contains all the cars 
/// </summary>
/// <param name="car"></param> the car object being added
/// <returns></returns> true if car was added false if it already exists
bool Repository::add_car(Car car)
{
	int i = this->AllCars.findPositionOfElement(car);
	if (i != -1)
		return false;
	this->AllCars.add(car);
	return true;
}

bool Repository::remove_car(int index)
{
	if (index < 0 || index >= this->AllCars.getSize())
		return false;
	this->AllCars.remove_element(index);
	return true;
}

int Repository::get_car_index_by_model_and_year(std::string model, int year)
{
	Car car("", model, "", year);
	int i = this->AllCars.findPositionOfElement(car);
	return i;
}

