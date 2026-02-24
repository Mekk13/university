#include "Person.h"
#include <string>
#include <iostream>
#include <fstream>

void Person::addAnalysis(MedicalAnalysis* analysis)
{
	std::shared_ptr<MedicalAnalysis> analysisPtr(analysis);
	analyses.push_back(analysisPtr);
}

std::vector<std::shared_ptr<MedicalAnalysis>> Person::getAllAnalyses()
{
	return this->analyses;
}

std::vector<std::shared_ptr<MedicalAnalysis>> Person::getAnalysisByMonth(int month)
{
	std::vector<std::shared_ptr<MedicalAnalysis>> filtered;
	for (auto& a : this->analyses) {
		int m = stoi(a->getDate().substr(5, 2));
		if (m == month) {
			filtered.push_back(a);
		}
	}
	return filtered;
}

bool Person::isIll(int month)
{
	std::vector<std::shared_ptr<MedicalAnalysis>> filtered = getAnalysisByMonth(month);
	for (auto& a : filtered) {
		if (a->isResultOk())
			return 0;
	}
	return 1;
}

std::vector<std::shared_ptr<MedicalAnalysis>> Person::getAnalysisBetweenDates(std::string date1, std::string date2)
{
	std::vector<std::shared_ptr<MedicalAnalysis>> filtered;
	for (auto& a : this->getAllAnalyses()) {
		if (a->getDate() >= date1 && a->getDate() <= date2)
			filtered.push_back(a);
	}
	return filtered;
}

void Person::writeToFile(std::string fileName, std::string date1, std::string date2)
{
	std::ofstream file(fileName);
	if (file.is_open()) {
		file << "Person: " << this->name << "\n";
		file << "Analyses between " << date1 << " and " << date2 << ":\n";
		for (auto& a : getAnalysisBetweenDates(date1, date2)) {
			file << a->toString()<<" "<<a->isResultOk() << "\n";
		}
		file.close();
	}
	else {
		std::cerr << "Unable to open file";
	}
}





