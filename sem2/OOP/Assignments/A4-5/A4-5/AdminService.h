#pragma once
#include "Repo.h"

class Admin_Service {
private:
	Repo& repo;
public:
	Admin_Service(Repo& repo);
	bool add_movie(std::string title, std::string genre, std::string trailer, int year, int likes);
	bool remove_movie(std::string title, std::string genre);
	bool update_movie(std::string title, std::string genre, std::string new_title, std::string new_genre, std::string new_trailer, int new_likes, int new_year);
	DynamicVector<Movie> get_all_movies();
};