#pragma once
#include "Repo.h"
#include "Validator.h"
#include "WatchlistRepo.h"

class User_Service {
private:
	Repo& repo;
	Watch_Repository& Watch_repo;
	Validator valid;
public:
	User_Service(Repo& repo,Watch_Repository& W);
	std::vector<Movie> get_movies_from_genre(std::string genre);
	std::vector<Movie> get_watchlist();
	void add_movie_to_watchlist(std::string title, std::string genre);
	void delete_movie_from_watchlist(std::string title, std::string genre);
	void like_a_movie(std::string title, std::string genre);
	void set_file(std::string s);
	std::string get_file_type();
	int getWatchlistCount() { return this->get_watchlist().size(); }
};