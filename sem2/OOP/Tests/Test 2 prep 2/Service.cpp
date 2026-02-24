#include "Service.h"
#include <fstream>

Service::Service()
{
}

Service::~Service()
{
	delete[] &this->AllAppliances;
}

void Service::addAppliance(Appliance* a)
{
    std::shared_ptr<Appliance> Ptr(a);
	this->AllAppliances.push_back(Ptr);
}

std::vector<std::shared_ptr<Appliance>> Service::getAllAppliances()
{
	return this->AllAppliances;
}

std::vector<std::shared_ptr<Appliance>> Service::getAllWithConsumedElectricityLessThan(double maxElectricity)
{
	std::vector<std::shared_ptr<Appliance>> filtered;
	for (auto& a : this->AllAppliances) {
		if (a->consumedElectricity() < maxElectricity) {
			filtered.push_back(a);
		}
	}
	return filtered;
}

std::vector<std::shared_ptr<Appliance>> Service::getAllInefficient()
{
	std::vector<std::shared_ptr<Appliance>> filtered;
	for (auto& a : this->AllAppliances) {
		if (a->consumedElectricity() > 100) {
			filtered.push_back(a);
		}
	}
	return filtered;
}

void Service::writeToFile(std::string FileName, double val)
{
	std::vector<std::shared_ptr<Appliance>> filtered = getAllWithConsumedElectricityLessThan(val);
	std::ofstream fout(FileName);
	if (!fout.is_open()) {
		std::cerr << "Error opening file: " << FileName << std::endl;
		return;
	}
	for (auto& a : filtered) {
		fout << a->toString() << std::endl;
	}

}
