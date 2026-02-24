#include "AdminService.h"
#include <string>

Admin_Service::Admin_Service(Repo& repo) : repo(repo) {}

bool Admin_Service::add_movie(std::string title, std::string genre, std::string trailer, std::string year, std::string likes)
{
	try {
		bool ok = this->valid.is_movie(title, genre, trailer, year, likes);
	}
	catch (MyException& e) {
		throw MyException(e.what());
	}
	int y = stod(year);
	int l = stod(likes);
	Movie movie(title, genre, trailer, y, l);
	return this->repo.add_movie(movie);
}

/// <summary>
/// removes movie by title and genre given
/// </summary>
/// <param name="title"></param>
/// <param name="genre"></param>
/// <returns></returns> true if successful, false if not
bool Admin_Service::remove_movie(std::string title, std::string genre)
{
	int index = this->repo.get_movie_index_by_title_and_genre(title, genre);
	return this->repo.remove_movie(index);
}

/// <summary>
/// updates movie by title and genre given
/// </summary>
/// <param name="title"></param>
/// <param name="genre"></param>
/// <returns></returns> true if successful, false if not
bool Admin_Service::update_movie(std::string title, std::string genre, std::string new_title, std::string new_genre, std::string new_trailer, std::string new_likes, std::string new_year)
{
	try {
		bool ok = this->valid.is_movie(new_title, new_genre, new_trailer, new_year, new_likes);
	}
	catch (MyException& e) {
		throw MyException(e);
	}
	int y = stod(new_year);
	int l = stod(new_likes);
	Movie updated_movie(new_title, new_genre, new_trailer, y, l);
	int index = this->repo.get_movie_index_by_title_and_genre(title, genre);
	return this->repo.update_movie(index, updated_movie);
}


std::vector<Movie> Admin_Service::get_all_movies()
{
	return this->repo.get_all_movies();
}
