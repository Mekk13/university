#include "Validator.h"
#include <string>
#include <exception>
#include "MyException.h"

bool Validator::is_number(std::string x)
{
	try {
		int y = stod(x);
		return true;
	}
	catch (std::exception e){
		return false;
	}
}

bool Validator::is_negative(int x)
{
	return x < 0;
}

bool Validator::is_year(std::string x)
{
	if (this->is_empty(x))
		return 0;
	if (!this->is_number(x))
		return 0;
	int x1 = stod(x);
	if (this->is_negative(x1))
		return 0;
	return x1 <= 2025 && x1 >= 1888;
}

bool Validator::is_empty(std::string x)
{
	return x.empty();
}

bool Validator::is_movie(std::string title, std::string genre, std::string trailer, std::string year, std::string likes)
{
	if (this->is_empty(title))
		throw MyException("Title is empty!\n");
	if (this->is_empty(genre))
		throw MyException("Genre is empty!\n");
	if (this->is_empty(trailer))
		throw MyException("Trailer is empty!\n");
	if (!this->is_number(year) || !this->is_number(likes))
		throw MyException("Invalid integer!\n");
	if (this->is_negative(stod(year)) || this->is_negative(stod(likes)))
		throw MyException("Number can not be negative!\n");
	return 1;
}
