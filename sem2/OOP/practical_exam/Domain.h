#pragma once
#include <string>
#include <iostream>
using namespace std;

class Researcher {
private:
	string name, position;
public:
	Researcher(string n, string p) :name(n), position(p) {}
	~Researcher() = default;
	string getName() {
		return name;
	}
	string getPosition() {
		return position;
	}
};

class Idea {
private:
	string title, description, status, creator;
	int duration;

public:
	Idea(string t, string d, string s, string c, int i) : title{ t }, description{ d }, status{ s }, creator{ c }, duration{ i } {}
	~Idea() = default;
	void setStatus(string s) {
		status = s;
	}
	string getStatus() const {
		return status;
	}
	string getTitle() const {
		return title;
	} 
	string getDescription() const {
		return description;
	}
	void setDuration(int i) {
		duration = i;
	}
	string getCreator() {
		return creator;
	}
	int getDuration() {
		return duration;
	}
	void setDescription(const string& d) {
		description = d;
	}
};