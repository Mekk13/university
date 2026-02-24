#pragma once

template <typename T>
class Comparator {
public:
	virtual bool compare(const T& a, const T& b) =0;

};

template <typename T>
class ComparatorAscendingByTitle : public Comparator<T> {
public:
	bool compare(const T& a, const T& b) override {
		return a.getTitle() < b.getTitle();
	}
};

template <typename T>
class ComparatorDescendingByGenre : public Comparator<T> {
public:
	bool compare(const T& a, const T& b) override {
		return a.getGenre() > b.getGenre();
	}
};

