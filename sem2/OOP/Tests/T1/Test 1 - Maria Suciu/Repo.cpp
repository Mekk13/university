#include "Repo.h"

Repository::Repository()
{
}

Repository::Repository(DynamicVector<Film> f)
{
	this->films = f;
}

bool Repository::add_film(Film f)
{
	int index = this->films.findPositionOfElement(f);
	if (index != -1)
		return 0;
	this->films.add(f);
	return 1;
}

bool Repository::delete_film(Film f)
{
	int index = this->films.findPositionOfElement(f);
	if (index == -1)
		return 0;
	this->films.remove_element(index);
	return 1;
}

int Repository::get_film_index_by_title_and_director(std::string title, std::string director)
{
	Film f(title, director, "");
	return this->films.findPositionOfElement(f);
}

DynamicVector<Film> Repository::getAll()
{
	return this->films;
}




