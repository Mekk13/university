#pragma once
#include <string>

class MedicalAnalysis {
private:
	std::string date;
public:
	MedicalAnalysis(std::string d) :date(d) {};
	virtual ~MedicalAnalysis();
	virtual bool isResultOk() = 0;
	virtual std::string toString();
	virtual std::string getDate();
};

class BMI :public MedicalAnalysis {
private:
	double value;
public:
	BMI(double v, std::string d) :MedicalAnalysis(d), value(v) {};
	bool isResultOk();
	std::string toString();
};

class BP :public MedicalAnalysis {
private:
	int systolicValue;
	int diastolicValue;
public:
	BP(int s, int d, std::string date) :MedicalAnalysis(date), systolicValue(s), diastolicValue(d) {};
	bool isResultOk();
	std::string toString();
};