#pragma once
#include "Repo.h"

class User_Service {
private:
	Repo& repo;
	DynamicVector<Movie> Watchlist;
public:
	User_Service(Repo& repo);
	DynamicVector<Movie> get_movies_from_genre(std::string genre);
	DynamicVector<Movie> get_watchlist();
	bool add_movie_to_watchlist(std::string title, std::string genre);
	bool delete_movie_from_watchlist(std::string title, std::string genre);
	bool like_a_movie(std::string title, std::string genre);
};