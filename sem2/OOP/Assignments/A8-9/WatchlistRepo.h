#pragma once
#include <stdio.h>
#include "Movie.h"
#include <vector>
#include <string>
#include "VectorUtils.h"

class Watch_Repository {
private:
	std::vector<Movie> Watchlist;
	std::string filetype;
public:
	Watch_Repository(std::vector<Movie> m = {});
	bool add_to_list(Movie m);
	bool remove_from_list(std::string title, std::string genre);
	void update(std::string title, std::string genre, Movie new_m);
	std::vector<Movie> get_watchlist_content();
	void set_filetype(std::string t);
	void export_csv();
	void export_html();
	void save_to_file();
	std::string get_file_type();
};

