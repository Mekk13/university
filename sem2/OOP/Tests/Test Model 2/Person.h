#pragma once
#include <stdio.h>
#include <string>
#include "MedicalAnalysis.h"
#include <vector>
#include <memory>

class Person {
private:
	std::string name;
	std::vector<std::shared_ptr<MedicalAnalysis>> analyses;
public:
	Person(std::string n) :name(n) {};
	void addAnalysis(MedicalAnalysis* analysis);
	std::vector<std::shared_ptr<MedicalAnalysis>> getAllAnalyses();
	std::vector<std::shared_ptr<MedicalAnalysis>> getAnalysisByMonth(int month);
	bool isIll(int month);
	std::vector<std::shared_ptr<MedicalAnalysis>> getAnalysisBetweenDates(std::string date1,std::string date2);
	void writeToFile(std::string fileName,std::string date1, std::string date2);
};