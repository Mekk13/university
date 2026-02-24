#pragma once
#include "Repo.h"
#include "Validator.h"
#include "MyException.h"
#include <stdio.h>
class Admin_Service {
private:
	Repo& repo;
	Validator valid;
public:
	Admin_Service(Repo& repo);
	bool add_movie(std::string title, std::string genre, std::string trailer, std::string year, std::string likes);
	bool remove_movie(std::string title, std::string genre);
	bool update_movie(std::string title, std::string genre, std::string new_title, std::string new_genre, std::string new_trailer, std::string new_likes, std::string new_year);
	std::vector<Movie> get_all_movies();
};