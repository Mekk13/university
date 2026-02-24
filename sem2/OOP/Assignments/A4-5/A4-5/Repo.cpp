#include "Repo.h"

Repo::Repo(DynamicVector<Movie> movies): All_Movies(movies) {}

DynamicVector<Movie> Repo::get_all_movies()
{
	return this->All_Movies;
}

bool Repo::add_movie(Movie movie)
{
	if (this->All_Movies.findPositionOfElement(movie) != -1)
		return false;
	this->All_Movies.add(movie);
	return true;
}

bool Repo::remove_movie(int index)
{
	if (index<0 || index >= this->All_Movies.getSize())
		return false;
	this->All_Movies.remove_element(index);
	return true;
}

bool Repo::update_movie(int index, Movie movie)
{
	if (index < 0 || index >= this->All_Movies.getSize())
		return false;
	this->All_Movies.update_element(index, movie);
	return true;
}

int Repo::get_movie_index_by_title_and_genre(std::string title, std::string genre)
{
	std::string a = "";
	int c{ 0 }, b{ 0 };
	Movie movie(title, genre, a, b, c);
	return this->All_Movies.findPositionOfElement(movie);
}
