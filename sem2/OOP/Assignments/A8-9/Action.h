#pragma once
#include "Repo.h"

class Action {
public:
	
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
	virtual ~Action() {};
};

class ActionAdd :public Action {
private:
	Repo& repo;
	Movie addedMovie;
public:
	ActionAdd(Repo& r,Movie m):repo(r),addedMovie(m){}
	~ActionAdd() {}
	void executeUndo();
	void executeRedo();
};

class ActionRemove :public Action {
private:
	Repo& repo;
	Movie removedMovie;
public:
	ActionRemove(Repo & r, Movie m):repo(r), removedMovie(m){}
	~ActionRemove() {}
	void executeUndo();
	void executeRedo();
};

class ActionUpdate : public Action {
private:
	Repo& repo;
	Movie oldMovie,newMovie;
public:
	ActionUpdate(Repo& r, Movie m1, Movie m2) :repo(r), oldMovie(m1), newMovie(m2) {}
	~ActionUpdate() {}
	void executeUndo();
	void executeRedo();
};
