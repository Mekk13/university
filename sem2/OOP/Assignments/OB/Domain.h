#pragma once
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class User {
private:
	string name;
	int id;
	string type;
public:
	User(string n, int i, string t) :name(n), id(i), type(t) {}
	string getName() { return name; }
	string getType() { return type; }
	int getId() { return id; }
};

class Item {
private:
	string name, category;
	int price;
	vector<tuple<int, string, int>> offers;
public:
	Item() : name(""), category(""), price(0) {}
	Item(string n, string c, int p) :name(n), category(c), price(p) {}
	void addOffer(int user_id, string date, int price) { offers.push_back(make_tuple(user_id,date,price)); }
	vector<tuple<int, string, int>> getOffers() { return offers; }
	string getName() { return name; }
	string getCategory() { return category; }
	int getPrice() { return price; }
	void setPrice(int p) { price = p; }

};