#pragma once 
#include <vector>
struct Equation {
	double a, b, c;
};

class Repo {
private:
	std::vector<Equation> equations;
public:
	Repo() = default;
	void addEquation(const Equation& eq) {
		equations.push_back(eq);
	}
	const std::vector<Equation>& getEquations() const {
		return equations;
	}
};