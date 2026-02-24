#pragma once
#include "Repo.h"

class Service {
private:
	Repository repo;
public:
	Service();
	Service(Repository r);
	int add_film(std::string title, std::string director, std::string keywords);
	DynamicVector<Film> get_all_films();
	DynamicVector<Film> get_films_with_keyword(std::string keyword);
	//int count_d(std::string dir,std::string key);
};