#include "MedicalAnalysis.h"

MedicalAnalysis::~MedicalAnalysis()
{
}

std::string MedicalAnalysis::toString()
{
	return "Medical Analysis Date: " + date;
}

std::string MedicalAnalysis::getDate()
{
	return this->date;
}

bool BMI::isResultOk()
{
	return this->value>=18.5 && this->value<=25;
}

std::string BMI::toString()
{
	return "BMI: " + std::to_string(this->value) + " Date: " + MedicalAnalysis::toString();
}

bool BP::isResultOk()
{
	return this->systolicValue >= 90 && this->systolicValue <= 120 && this->diastolicValue >= 60 && this->diastolicValue <= 79;
}
std::string BP::toString()
{
	return "Blood Pressure: " + std::to_string(this->systolicValue) + "/" + std::to_string(this->diastolicValue) + " Date: " + MedicalAnalysis::toString();
}