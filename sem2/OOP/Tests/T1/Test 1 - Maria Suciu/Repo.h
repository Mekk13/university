#pragma once
#include "Dynamic_Vector.h"
#include "Film.h"

class Repository {
private:
	DynamicVector<Film> films;
public:
	Repository();
	Repository(DynamicVector<Film> f);
	bool add_film(Film f);
	bool delete_film(Film f);
	int get_film_index_by_title_and_director(std::string title, std::string director);
	DynamicVector<Film> getAll();
};