#include "Subject.h"

void Subject::resgisterOberver(Observer* obs)
{
	this->observers.push_back(obs);
}

void Subject::unregisterObserver(Observer* obs)
{
	auto it = std::remove(observers.begin(), observers.end(), obs);
	if (it != observers.end()) {
		observers.erase(it, observers.end());
	}
}

void Subject::notify()
{
	for (auto& ob : this->observers) {
		ob->update();
	}
}
