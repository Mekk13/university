#include "Film.h"

Film::Film()
{
}

Film::Film(std::string title, std::string director, std::string keywords)
{
	this->title = title;
	this->director = director;
	this->keywords = keywords;
}

Film::~Film()
{
}

std::string Film::get_title()
{
	return this->title;
}

std::string Film::get_director()
{
	return this->director;
}

std::string Film::get_keywords()
{
	return this->keywords;
}

int Film::operator==(Film f)
{
	return(this->title == f.title && this->director == f.director);
}

void Film::operator=(Film f)
{
	this->title = f.title;
	this->director = f.director;
	this->keywords = f.keywords;
}

std::string Film::toString()
{
	return this->title + " | " + this->director + " | " + this->keywords;
}



