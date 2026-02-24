#pragma once
#include "UI.h"
#include "test.h"

int main() {
	{
		run_tests();
		DynamicVector<Car> cars;
		Repository repo(cars);
		Service serv(repo);
		UI console(serv);
		console.start();
	}
	return 0;
}