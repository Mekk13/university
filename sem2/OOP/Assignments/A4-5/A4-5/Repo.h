#pragma once
#include "Movie.h"
#include "DynamicVector.h"

class Repo {
private:
	DynamicVector<Movie> All_Movies;
public:
	Repo(DynamicVector<Movie> movies = {});
	DynamicVector<Movie> get_all_movies();
	bool add_movie(Movie movie);
	bool remove_movie(int index);
	bool update_movie(int index, Movie movie);
	int get_movie_index_by_title_and_genre(std::string title, std::string genre);
};