#include "AdminService.h"

Admin_Service::Admin_Service(Repo& repo): repo(repo) {}

bool Admin_Service::add_movie(std::string title, std::string genre, std::string trailer, int year, int likes)
{
	Movie movie(title, genre,trailer,year,likes );
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
bool Admin_Service::update_movie(std::string title, std::string genre, std::string new_title, std::string new_genre, std::string new_trailer, int new_likes, int new_year)
{
	Movie updated_movie(new_title, new_genre, new_trailer, new_year, new_likes);
	int index = this->repo.get_movie_index_by_title_and_genre(title, genre);
	return this->repo.update_movie(index,updated_movie);
}


DynamicVector<Movie> Admin_Service::get_all_movies()
{
	return this->repo.get_all_movies();
}
