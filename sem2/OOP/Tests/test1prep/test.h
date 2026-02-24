#pragma once
#include <cassert>
#include "Service.h"


void test_add(Service& s) {
	bool ok = s.add_car("Toyota", "Camri", "Red", 2009);
	assert(ok == true);

	bool ok1 = s.add_car("Toyota", "Camri", "Red", 2009);
	assert(ok1 == false);

}

void test_vintage(Service& s) {
	(void)s.add_car("Toyota", "Hilux", "Red", 1970);
	(void)s.add_car("Dacia", "1300", "White", 1969);
	DynamicVector<Car> vintage = s.get_all_vintage_sorted();
	assert(vintage.getElement(0).getManName() == "Toyota");
	assert(vintage.getElement(1).getManName() == "Dacia");
}

void run_tests() {
	DynamicVector<Car> cars;
	Repository repo(cars);
	Service serv(repo);
	test_add(serv);
	test_vintage(serv);
}