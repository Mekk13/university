#pragma once
#include "Observer.h"
#include <vector>
#include <qsharedpointer.h>

class Subject {
public:
	Subject()= default;
	virtual ~Subject()=default;
	virtual void resgisterOberver(Observer *obs);
	virtual void unregisterObserver(Observer *obs);
	virtual void notify();

private:
	std::vector<Observer*> observers;
};