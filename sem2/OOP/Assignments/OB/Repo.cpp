#include "Repo.h"
#include <fstream>
#include <sstream>
#include <string>

void Repo::load_file()
{
	ifstream uin("user_info.txt");
	ifstream iin("item_info.txt");

	string line;
	while (getline(uin, line)) {
		stringstream ss(line);
		string name, idStr, type;
		getline(ss, name, ';');
		getline(ss, idStr, ';');
		getline(ss, type, ';');
		int id = stoi(idStr);
		User user(name, id, type);
		users.push_back(user);
	}

	string line1;
	while (getline(iin, line1)) {
		string name, category, priceStr, offerStr;
		stringstream ss1(line1);
		getline(ss1, name, ';');
		getline(ss1, category, ';');
		getline(ss1, priceStr, ';');
		getline(ss1, offerStr, ';');

		int price = stoi(priceStr);
		Item item(name, category, price);
		stringstream offerSS(offerStr);
		string offerToken;

		while (getline(offerSS, offerToken, '|')) {
			if (offerToken.empty()) continue;

			//noow remove []
			if (offerToken.front() == '[') offerToken.erase(0, 1);
			if (offerToken.back() == ']') offerToken.pop_back();
			std::stringstream ot(offerToken);
			std::string idStr, date, amountStr;

			std::getline(ot, idStr, ',');
			std::getline(ot, date, ',');
			std::getline(ot, amountStr);

			int uid = std::stoi(idStr);
			int amt = std::stoi(amountStr);
			item.addOffer(uid, date, amt);
		}
		items.push_back(item);
	}
}

void Repo::save_file()
{
	ofstream uout("user_info.txt");
	ofstream iout("item_info.txt");
	for (auto& user : users) {
		uout << user.getName() << ";" << user.getId() << ";" << user.getType() << "\n";
	}
	for (auto& item : items) {
		string offerStr;
		for (auto& offer : item.getOffers()) {
			offerStr += "[" + std::to_string(std::get<0>(offer)) + "," + std::get<1>(offer) + "," + std::to_string(std::get<2>(offer)) + "]";
			offerStr += "|";
		}
		if (!offerStr.empty()) {
			offerStr.pop_back(); // Remove the last '|'
		}
		iout << item.getName() << ";" << item.getCategory() << ";" << item.getPrice() << ";" << offerStr << "\n";
	}
}

vector<User> Repo::getUsers()
{
	return users;
}

vector<Item> Repo::getItems()
{
	return items;
}

void Repo::set_item_price(int itemIndex, int newPrice)
{
	if (itemIndex < 0 || itemIndex >= items.size()) {
		throw std::out_of_range("Item index out of range");
	}
	items[itemIndex].setPrice(newPrice);
	save_file(); 
}

void Repo::addItem(Item i)
{
	items.push_back(i);
	save_file();	
}

void Repo::addOffer(int itemIndex, int userId, string date, int amount)
{
	if (itemIndex < 0 || itemIndex >= items.size()) {
		throw std::out_of_range("Item index out of range");
	}
	items[itemIndex].addOffer(userId, date, amount);
	save_file();
}
