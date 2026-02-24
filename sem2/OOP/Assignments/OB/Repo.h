#pragma once
#include "Domain.h"
#include <vector>

class Repo {
private:
	vector<User> users;
	vector<Item> items;
public:
	void load_file();
	void save_file();
	vector<User> getUsers();
	vector<Item> getItems();
	void set_item_price(int itemIndex, int newPrice);
	void addItem(Item i);
	void addOffer(int itemIndex, int userId, string date, int amount);
};