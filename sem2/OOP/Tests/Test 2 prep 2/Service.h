#pragma once
#include "Appliance.h"
#include <iostream>
#include <vector>
#include <memory>


class Service {
private:
	std::vector<std::shared_ptr<Appliance>> AllAppliances;
public:
	Service();
	~Service();
	void addAppliance(Appliance* a);
	std::vector<std::shared_ptr<Appliance>> getAllAppliances();
	std::vector<std::shared_ptr<Appliance>> getAllWithConsumedElectricityLessThan(double maxElectricity);
	std::vector<std::shared_ptr<Appliance>> getAllInefficient();
	void writeToFile(std::string FileName,double val);
};