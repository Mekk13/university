#pragma once
#include "Movie.h"
#include <vector>
#include "VectorUtils.h"

class Repo {
private:
	std::vector<Movie> All_Movies;
public:
	Repo(std::vector<Movie> movies = {});
	virtual ~Repo();
	std::vector<Movie> get_all_movies();
	virtual bool add_movie(Movie movie);
	virtual bool remove_movie(int index);
	virtual bool update_movie(int index, Movie movie);
	virtual int get_movie_index_by_title_and_genre(std::string title, std::string genre) const;
	virtual Movie get_movie_by_index(int index);

	//file
	void load_from_file(const std::string& filename);
	void save_to_file(const std::string& filename);
};