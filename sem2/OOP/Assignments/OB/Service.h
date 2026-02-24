#pragma once
#include <algorithm>
#include "Repo.h"
#include "Subject.h"

class Service : public Subject {
private:
	Repo* repo;
public:
	Service(Repo* r) : repo(r) {
		repo->load_file();
	}
	vector<User> getUsers() {
		return repo->getUsers();
	}
	vector<Item> getItems() {
		return repo->getItems();
	}
	vector<Item> getitemsSorted() {
		vector<Item> items = repo->getItems();
		sort(items.begin(), items.end(), []( Item a, Item b) {
			return a.getPrice() < b.getPrice();
			});
		return items;
	}
	void addItem(const Item& item) {
		repo->addItem(item);
		
	}
	void addOffer(int itemIndex, int userId, const string& date, int amount) {
		repo->addOffer(itemIndex, userId, date, amount);
		
	}
	vector<tuple<int, string, int>> getOffersForItemSortedByDate(int itemIndex) {
		vector<Item> items = repo->getItems();
		if (itemIndex < 0 || itemIndex >= items.size()) {
			return {};
		}
		vector<tuple<int, string, int>> offers = items[itemIndex].getOffers();
		sort(offers.begin(), offers.end(), [](const tuple<int, string, int>& a, const tuple<int, string, int>& b) {
			return get<1>(a) < get<1>(b); 
			});
		return offers;
	}
	int getItemIndex(Item i) {
		vector<Item> items = repo->getItems();
		auto it = find_if(items.begin(), items.end(), [&i]( Item& item) {
			return item.getName() == i.getName() && item.getCategory() == i.getCategory() && item.getPrice() == i.getPrice();
			});
		if (it != items.end()) {
			return distance(items.begin(), it);
		}
		return -1; // Item not found
	}
	void change_item_price(int itemIndex, int newPrice) {
		if (itemIndex < 0 || itemIndex >= repo->getItems().size()) {
			throw std::out_of_range("Item index out of range");
		}
		repo->set_item_price(itemIndex, newPrice);
	}	
};