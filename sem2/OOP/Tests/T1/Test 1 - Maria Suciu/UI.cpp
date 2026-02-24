#include "UI.h"
#include <string>
using namespace std;

UI::UI()
{
}

UI::UI(Service s)
{
	this->serv = s;
}

void UI::handle_add()
{
	string t, d, k;
	cout << "Title: ";
	if (cin.peek() == '\n')
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, t);

	cout << "Director: ";
	if (cin.peek() == '\n')
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, d);

	cout << "Keywords: ";
	if (cin.peek() == '\n')
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, k);

	int ok =this->serv.add_film(t, d, k);
	if (!ok)
		cout << "Movie already exists!\n";
}

void UI::handle_show()
{
	DynamicVector<Film> all = this->serv.get_all_films();
	for (int i = 0; i < all.getSize(); i++) {
		cout<<all.getElement(i).toString()<<endl;
	}
}

void UI::handle_show_keyword()
{
	string k;
	cout << "Keyword: ";
	if (cin.peek() == '\n')
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, k);
	DynamicVector<Film> all = this->serv.get_films_with_keyword(k);
	for (int i = 0; i < all.getSize(); i++) {
		cout << all.getElement(i).toString() << endl;
	}
}

void UI::start()
{
	add_5_movies();
	while (true) {
		int choice;
		menu();
		cout << "Choice: ";
		if (cin.peek() == '\n')
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
		switch (choice) {
		case 0:
			return;
		case 1:
			handle_add();
			break;
		case 2:
			handle_show();
			break;
		case 3:
			handle_show_keyword();
			break;
		default:
			cout << "Not a valid choice!\n";
			break;
		}
	}
}

void UI::menu()
{
	cout << "MENU\n";
	cout << "1. Add movie\n";
	cout << "2. Show all movies\n";
	cout << "3. Show all movies with a keyword\n";
	cout << "0. Exit\n";
}

void UI::add_5_movies()
{
	this->serv.add_film("Interstellar", "Nolan", "Sci-Fi , Space");
	this->serv.add_film("Dune part 2", "Denis", "Sci-Fi , Adv");
	this->serv.add_film("Barbie", "Greta", "Comedy , Fantasy");
	this->serv.add_film("Titanic", "James", "Romance , Drama");
	this->serv.add_film("Pride and Prejudice", "Helena", "Romance , Drama");
}
