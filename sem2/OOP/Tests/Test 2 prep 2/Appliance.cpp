#include "Appliance.h"

Appliance::~Appliance()
{

}

std::string Appliance::toString()
{
	return "id: " + this->id;
}

Refrigerator::~Refrigerator()
{
}

double Refrigerator::consumedElectricity()
{
	double usage = 30;
	if (this->electricityUsageClass == "A++") {
		usage *=2;
	}
	else if (this->electricityUsageClass == "A") {
		usage *= 3;
	}
	if (this->hasFreezer) {
		usage += 20;
	}
	return usage;
}

std::string Refrigerator::toString()
{
	return Appliance::toString() + " electricityUsageClass: " + this->electricityUsageClass + " hasFreezer: " + (this->hasFreezer ? "true" : "false") + "\n" + std::to_string(consumedElectricity()) + " kWh\n";

}

DishWasher::~DishWasher()
{
}

double DishWasher::consumedElectricity()
{
	double usage = this->consumedElectricityForOneHour * 20;
	return usage;
}

std::string DishWasher::toString()
{
	return Appliance::toString() + " consumedElectricityForOneHour: " + std::to_string(this->consumedElectricityForOneHour)+"\n" + std::to_string(consumedElectricity()) + " kWh\n";
}
