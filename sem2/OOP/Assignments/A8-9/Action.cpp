#include "Action.h"


void ActionAdd::executeUndo()
{
	int index = this->repo.get_movie_index_by_title_and_genre(this->addedMovie.getTitle(), this->addedMovie.getGenre());
	this->repo.remove_movie(index);
}

void ActionAdd::executeRedo()
{
	this->repo.add_movie(this->addedMovie);
}

void ActionRemove::executeUndo()
{
	this->repo.add_movie(this->removedMovie);
}

void ActionRemove::executeRedo()
{
	int index = this->repo.get_movie_index_by_title_and_genre(this->removedMovie.getTitle(), this->removedMovie.getGenre());
	this->repo.remove_movie(index);
}

void ActionUpdate::executeUndo()
{
	int index = this->repo.get_movie_index_by_title_and_genre(this->newMovie.getTitle(), this->newMovie.getGenre());
	this->repo.update_movie(index, this->oldMovie);
}

void ActionUpdate::executeRedo()
{
	int index = this->repo.get_movie_index_by_title_and_genre(this->oldMovie.getTitle(), this->oldMovie.getGenre());
	this->repo.update_movie(index, this->newMovie);
}
