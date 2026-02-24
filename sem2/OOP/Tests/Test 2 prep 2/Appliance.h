#pragma once 
#include <string>

class Appliance {
private:
	std::string id;
public:
	Appliance(std::string id) : id(id) {};
	virtual ~Appliance();
	virtual double consumedElectricity() = 0;
	virtual std::string toString();
};

class Refrigerator : public Appliance {
private:
	std::string electricityUsageClass;
	bool hasFreezer;
public:
	Refrigerator(std::string id, std::string electricityUsageClass, bool hasFreezer) : Appliance(id), electricityUsageClass(electricityUsageClass), hasFreezer(hasFreezer) {};
	~Refrigerator();
	double consumedElectricity();
	std::string toString();
};

class DishWasher : public Appliance {
private:
	double consumedElectricityForOneHour;
public:
	DishWasher(std::string id, double consumedElectricityForOneHour) : Appliance(id), consumedElectricityForOneHour(consumedElectricityForOneHour) {};
	~DishWasher();
	double consumedElectricity();
	std::string toString();
};