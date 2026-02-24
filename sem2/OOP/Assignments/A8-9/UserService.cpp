#include "UserService.h"
#include "MyException.h"
User_Service::User_Service(Repo& repo, Watch_Repository& W) : repo(repo), Watch_repo(W) {}


std::vector<Movie> User_Service::get_movies_from_genre(std::string genre)
{

	std::vector<Movie> all = this->repo.get_all_movies();
	if (genre.empty())
		return all;
	std::vector<Movie> curated_list;
	std::copy_if(all.begin(), all.end(), std::back_inserter(curated_list), [&genre](const Movie& m) 
		{return m.getGenre() == genre; });
	return curated_list;
}

/// <summary>
/// returns the watchlist 
/// </summary>
/// <returns></returns> the watchlist 
std::vector<Movie> User_Service::get_watchlist()
{
	return this->Watch_repo.get_watchlist_content();
}

void User_Service::add_movie_to_watchlist(std::string title, std::string genre)
{
	if (this->valid.is_empty(title)) {
		throw MyException("Title is empty!\n");
	}
	if (this->valid.is_empty(genre)) {
		throw MyException("Genre is empty!\n");
	}
	int i = this->repo.get_movie_index_by_title_and_genre(title, genre);
	if (i == -1)
		throw MyException("Movie not found!\n");
	std::vector<Movie> all = this->repo.get_all_movies();
	this->Watch_repo.add_to_list(all[i]);
}

void User_Service::delete_movie_from_watchlist(std::string title, std::string genre)
{
	if (this->valid.is_empty(title)) {
		throw MyException("Title is empty!\n");
	}
	if (this->valid.is_empty(genre)) {
		throw MyException("Genre is empty!\n");
	}
	bool ok = this->Watch_repo.remove_from_list(title, genre);
	if (!ok)
		throw MyException("Movie not found!\n");
}

void User_Service::like_a_movie(std::string title, std::string genre)
{
	if (this->valid.is_empty(title)) {
		throw MyException("Title is empty!\n");
	}
	if (this->valid.is_empty(genre)) {
		throw MyException("Genre is empty!\n");
	}
	int i = this->repo.get_movie_index_by_title_and_genre(title, genre);
	if (i == -1)
		throw MyException("Movie not found!\n");
	std::vector<Movie> all = this->repo.get_all_movies();
	Movie m = all[i];
	m.setLikes(m.getLikes() + 1);
	this->Watch_repo.update(title, genre, m);
	this->repo.update_movie(i, m);
}

void User_Service::set_file(std::string s)
{
	this->Watch_repo.set_filetype(s);
}

std::string User_Service::get_file_type()
{
	return this->Watch_repo.get_file_type();
}

