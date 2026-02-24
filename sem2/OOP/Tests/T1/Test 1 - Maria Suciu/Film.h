#pragma once
#include <iostream>

class Film {
private:
	std::string title, director, keywords;
public:
	Film();
	Film(std::string title, std::string director, std::string keywords);
	~Film();
	std::string get_title();
	std::string get_director();
	std::string get_keywords();

	int operator==(Film f);
	void operator=(Film f);
	std::string toString();
	
};