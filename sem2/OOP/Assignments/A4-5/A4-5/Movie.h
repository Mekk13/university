#pragma once
#include <iostream>

class Movie {
private:
	std::string title, genre, trailer;
	int year, likes;

public:
	Movie(std::string title, std::string genre, std::string trailer, int year, int likes);
	Movie() :title{ "" }, genre{ "" }, trailer{ "" }, year{ 0 }, likes{ 0 }{}

	//getters
	std::string getTitle();
	std::string getGenre();
	std::string getTrailer();
	int getLikes();
	int getYear();

	//setters
	void setTitle(std::string Title);
	void setGenre(std::string Genre);
	void setTrailer(std::string Trailer);
	void setLikes(int Likes);
	void setYear(int Year);

	bool operator==(const Movie& movie_to_compare);
	void operator=(const Movie& movie_to_copy);
};