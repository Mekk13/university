#include "Human.h"

Human::~Human()
{
}

int Human::years()
{
	return this->USbirthday;
}

std::string Human::toString()
{
	return "Number of years:  " + std::to_string(this->USbirthday) + '\n';
}

Family::~Family()
{
}

bool Family::receiveCitizenship()
{
	if (this->Americans > 0 && this->years() >= 10)
		return 1;
	return 0;
}

bool Family::mustBeDeported()
{
	if (this->Americans < 1 && this->years() <= 3)
		return 1;
	return 0;
}

std::string Family::toString()
{
	std::string s="False", d="False";
	if (receiveCitizenship())
		s = "True";
	if (mustBeDeported())
		d = "True";
	return "Number of years: " + std::to_string(this->years()) + " Members: " +std::to_string(this->membersNo) + " Americans: " + std::to_string(this->Americans) + " Citizenship: " + s + " Needs to be deported: " + d + '\n';
}

Person::~Person()
{
}

bool Person::receiveCitizenship()
{
	if (this->years() >= 10)
		return true;
	return false;
}

bool Person::mustBeDeported()
{
	if (this->years() < 5)
		return true;
	return false;
}

std::string Person::toString()
{
	std::string s = "False", d = "False";
	if (receiveCitizenship())
		s = "True";
	if (mustBeDeported())
		d = "True";
	return "Number of years: " + std::to_string(this->years()) + "  Citizenship: " + s + " Needs to be deported: " + d + '\n';
}
