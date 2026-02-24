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

	std::shared_ptr<Action> m = std::make_shared<ActionAdd>(this->repo, movie);
	this->UndoStack.push(std::move(m));

	return this->repo.add_movie(movie);
}


bool Admin_Service::remove_movie(std::string title, std::string genre)
{
	int index = this->repo.get_movie_index_by_title_and_genre(title, genre);

	Movie m = this->repo.get_movie_by_index(index);
	std::shared_ptr<Action> a = std::make_shared<ActionRemove>(this->repo,m);
	this->UndoStack.push(std::move(a));

	return this->repo.remove_movie(index);
}


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

	Movie oldmovie = this->repo.get_movie_by_index(index);
	std::shared_ptr<Action> a = std::make_shared<ActionUpdate>(this->repo, oldmovie, updated_movie);
	this->UndoStack.push(std::move(a));

	return this->repo.update_movie(index, updated_movie);
}


std::vector<Movie> Admin_Service::get_all_movies()
{
	return this->repo.get_all_movies();
}

void Admin_Service::undo()
{
	if (!this->UndoStack.empty()) {
		std::shared_ptr<Action> action = std::move(this->UndoStack.top());
		this->UndoStack.pop();
		action->executeUndo();
		this->RedoStack.push(std::move(action));
	}
	else {
		throw MyException("Stack is empty!\n");
	}
}

void Admin_Service::redo()
{
	if (!this->RedoStack.empty()) {
		std::shared_ptr<Action> action = std::move(this->RedoStack.top());
		this->RedoStack.pop();
		action->executeRedo();
		this->UndoStack.push(std::move(action));
	}
	else {
		throw MyException("Stack is empty!\n");
	}
}
