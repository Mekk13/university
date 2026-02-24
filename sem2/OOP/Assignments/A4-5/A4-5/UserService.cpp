#include "UserService.h"

User_Service::User_Service(Repo& repo) : repo(repo) {}

DynamicVector<Movie> User_Service::get_movies_from_genre(std::string genre)
{	
	
	DynamicVector<Movie> all = this->repo.get_all_movies();
	if (genre == "")
		return all;
	DynamicVector<Movie> curated_list;
	for (int i = 0; i < all.getSize(); i++) {
		if (all[i].getGenre()== genre) {
			Movie m = all.getElement(i);
			curated_list.add(m);
		}
	}
	return curated_list;
}

/// <summary>
/// returns the watchlist 
/// </summary>
/// <returns></returns> the watchlist 
DynamicVector<Movie> User_Service::get_watchlist()
{
	return this->Watchlist;
}

bool User_Service::add_movie_to_watchlist(std::string title, std::string genre)
{
	int i = this->repo.get_movie_index_by_title_and_genre(title, genre);
	if (i == -1)
		return 0;
	DynamicVector<Movie> all = this->repo.get_all_movies();
	this->Watchlist.add(all.getElement(i));
	return 1;
}

bool User_Service::delete_movie_from_watchlist(std::string title, std::string genre)
{
	int i = -1;
	for (int j = 0; j < this->Watchlist.getSize(); j++)
	{
		if (this->Watchlist.getElement(j).getTitle() == title && this->Watchlist.getElement(j).getGenre() == genre) {
			i = j;
			break;
		}
	}
	if (i == -1)
		return 0;
	this->Watchlist.remove_element(i);
	return 1;
}

bool User_Service::like_a_movie(std::string title, std::string genre)
{
	int i = this->repo.get_movie_index_by_title_and_genre(title, genre);
	if (i == -1)
		return 0;
	DynamicVector<Movie> all = this->repo.get_all_movies();
	Movie m = all.getElement(i);
	m.setLikes(m.getLikes() + 1);
	this->repo.update_movie(i, m);
	return 1;
}
