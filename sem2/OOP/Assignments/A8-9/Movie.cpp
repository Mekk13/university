#include "Movie.h"

Movie::Movie(std::string title, std::string genre, std::string trailer, int year, int likes) {
	this->title = title;
	this->genre = genre;
	this->trailer = trailer;
	this->year = year;
	this->likes = likes;
}

std::string Movie::getTitle() const
{
	return this->title;
}

std::string Movie::getGenre() const
{
	return this->genre;
}

std::string Movie::getTrailer() const
{
	return this->trailer;
}

int Movie::getLikes() const
{
	return this->likes;
}

int Movie::getYear() const
{
	return this->year;
}

void Movie::setTitle(std::string Title)
{
	this->title = Title;
}

void Movie::setGenre(std::string Genre)
{
	this->genre = Genre;
}

void Movie::setTrailer(std::string Trailer)
{
	this->trailer = Trailer;
}

void Movie::setLikes(int Likes)
{
	this->likes = Likes;
}

void Movie::setYear(int Year)
{
	this->year = Year;
}

bool Movie::operator==(const Movie& movie_to_compare) const
{
	return (this->title == movie_to_compare.title && this->genre == movie_to_compare.genre);
}

void Movie::operator=(const Movie& movie_to_copy)
{
	this->title = movie_to_copy.title;
	this->genre = movie_to_copy.genre;
	this->trailer = movie_to_copy.trailer;
	this->likes = movie_to_copy.likes;
	this->year = movie_to_copy.year;
}

std::ostream& operator<<(std::ostream& os, const Movie& m)
{
	//ostream works with ofstream and others
	os << m.title << "," << m.genre << "," << m.trailer << "," << m.year << "," << m.likes;
	return os;
}

std::ifstream& operator>>(std::ifstream& is, Movie& m)
{
	std::getline(is, m.title, ',');
    std::getline(is, m.genre, ',');
    std::getline(is, m.trailer, ',');
    is >> m.year;
    is.ignore();
    is >> m.likes;
    is.ignore();
    return is;
}
