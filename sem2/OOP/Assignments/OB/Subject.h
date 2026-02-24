#pragma once
#include "Observer.h"
#include <vector>

class Subject {
private:
	std::vector<Observer*> observers;
public:
	Subject() {};
	virtual ~Subject() = default;
	virtual void registerObserver(Observer* obs);
	virtual void unregisterObserver(Observer* obs);
	virtual void notify();
};