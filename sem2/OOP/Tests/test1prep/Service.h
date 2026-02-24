#pragma once
#include "Repo.h"

class Service {
private:
	Repository& repo;
public:
	Service(Repository& repo);
	bool add_car(std::string name, std::string model, std::string colour, int year);
	bool remove_car(std::string model, int year);
	DynamicVector<Car> get_all_cars_sorted();
	DynamicVector<Car> get_all_vintage_sorted();
	DynamicVector<Car> get_all_vintage();
};