#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Movie {
	friend std::ostream& operator<<(std::ostream& os, const Movie& m);
	friend std::ifstream& operator>>(std::ifstream& is, Movie& m);
private:
	std::string title, genre, trailer;
	int year, likes;

public:
	Movie(std::string title, std::string genre, std::string trailer, int year, int likes);
	Movie() :title{ "" }, genre{ "" }, trailer{ "" }, year{ 0 }, likes{ 0 } {}

	//getters
	std::string getTitle() const;
	std::string getGenre() const;
	std::string getTrailer() const;
	int getLikes() const;
	int getYear() const;

	//setters
	void setTitle(std::string Title);
	void setGenre(std::string Genre);
	void setTrailer(std::string Trailer);
	void setLikes(int Likes);
	void setYear(int Year);

	bool operator==(const Movie& movie_to_compare) const;
	void operator=(const Movie& movie_to_copy);
};