#pragma once
#include "DynamicVector.h"
#include "Car.h"

class Repository {
private:
	DynamicVector<Car> AllCars;
public:
	Repository(DynamicVector<Car> cars = NULL);
	DynamicVector<Car> get_all_cars();
	bool add_car(Car car);
	bool remove_car(int index);
	int get_car_index_by_model_and_year(std::string model, int year);
};