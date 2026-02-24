#pragma once
#include <stdio.h>
#include <string>

class Validator {
public:
	Validator() {};
	bool is_number(std::string x);
	bool is_negative(int x);
	bool is_year(std::string x);
	bool is_empty(std::string x);
	bool is_movie(std::string title, std::string genre, std::string trailer, std::string year, std::string likes);
};