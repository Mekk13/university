#include "FileRepo.h"
#include <string>
#include <sstream>

void FileRepo::read_file()
{
	std::ifstream fin(this->filename);
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
		Repo::add_movie(m);
	}
}

void FileRepo::write_file()
{
	std::ofstream fout(this->filename); // Open file for writing
	if (!fout) {
		std::cerr << "Error opening file for writing!" << std::endl;
		return;
	}

	for (const Movie& m : this->get_all_movies()) {
		fout << m << std::endl;  // Use the overloaded << operator
	}
}

FileRepo::FileRepo(std::string filename)
{
	this->filename = filename;
	read_file();
}

bool FileRepo::add_movie(Movie movie) {
	bool result = Repo::add_movie(movie);
	this->save_to_file(filename);
	return result;
}

bool FileRepo::remove_movie(int index) {
	bool result = Repo::remove_movie(index);
	this->save_to_file(filename);
	return result;
}

bool FileRepo::update_movie(int index, Movie movie) {
	bool result = Repo::update_movie(index, movie);
	this->save_to_file(filename);
	return result;
}