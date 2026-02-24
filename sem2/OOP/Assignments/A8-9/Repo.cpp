#include "Repo.h"
#include <sstream>

Repo::Repo(std::vector<Movie> movies) : All_Movies(movies) {}

Repo::~Repo()
{
}

std::vector<Movie> Repo::get_all_movies()
{
	return this->All_Movies;
}

bool Repo::add_movie(Movie movie)
{
	if (findPositionOfElement(this->All_Movies,movie) != -1)
		return false;
	this->All_Movies.push_back(movie);
	return true;
}

bool Repo::remove_movie(int index)
{
	if (index < 0 || index >= this->All_Movies.size())
		return false;
	this->All_Movies.erase(this->All_Movies.begin() + index);
	return true;
}

bool Repo::update_movie(int index, Movie movie)
{
	if (index < 0 || index >= this->All_Movies.size())
		return false;
	this->All_Movies[index]=movie;
	return true;
}

int Repo::get_movie_index_by_title_and_genre(std::string title, std::string genre) const
{
	std::string a = "";
	int c{ 0 }, b{ 0 };
	Movie movie(title, genre, a, b, c);
	return findPositionOfElement(this->All_Movies,movie);
}

Movie Repo::get_movie_by_index(int index)
{
	return this->All_Movies[index];
}

void Repo::load_from_file(const std::string& filename)
{
	std::ifstream fin(filename);
	if (!fin) {
		std::cerr << "Error opening the file for readin! " << std::endl;
		return;
	}
	std::string line;
	while (std::getline(fin, line)) {
		std::stringstream ss(line);
		std::string title, genre, trailer;
		int year, likes;
		std::getline(ss, title, ',');
		std::getline(ss, genre, ',');
		std::getline(ss, trailer, ',');
		ss >> year;
		ss.ignore();  // Ignore the comma
		ss >> likes;
		Movie m(title, genre, trailer, year, likes);  // Create Movie object
		this->All_Movies.push_back(m);
	}
}

void Repo::save_to_file(const std::string& filename)
{
	std::ofstream fout(filename); // Open file for writing
	if (!fout) {
		std::cerr << "Error opening file for writing!" << std::endl;
		return;
	}

	for (const Movie& m : this->All_Movies) {
		fout << m << std::endl;  // Use the overloaded << operator
	}
}

