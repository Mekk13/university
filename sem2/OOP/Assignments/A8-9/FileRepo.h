#pragma once
#include "Repo.h"

class FileRepo : public Repo {
	std::string filename;
	void read_file();
	void write_file();
public:
	FileRepo(std::string filename);
	bool add_movie(Movie movie);
	bool remove_movie(int index);
	bool update_movie(int index, Movie movie);

};