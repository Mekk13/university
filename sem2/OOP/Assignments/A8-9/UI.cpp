#include "UI.h"
#include <limits>
#include <algorithm>

#include "Sort.h"

UI::UI(Admin_Service admin, User_Service user) : admin_serv(admin), user_serv(user) {}

//Beginning interface for the app
void UI::start_application(int way)
{
	std::cout << "Welcome to 'Movies database C++' App!\n" << std::endl;
	std::vector<Movie> m = this->admin_serv.get_all_movies();
	if(m.empty())
		generate_10_movies();
	if(way==2)
	std::cout << "What mode do you want to enter the app? (administrator/user)\n" << "Type 'exit' to close app\n\n";
	std::string accessMode;
	while (true) {
		std::cout << "Enter mode: ";
		std::cin >> accessMode;
		if (accessMode.compare("administrator") == 0)
			admin_mode();
		else if (accessMode.compare("user") == 0)
			user_mode(way);
		else if (accessMode.compare("exit") == 0)
		{
			std::cout << "\nApplication exited successfully!\n";
			return;
		}
		else
			std::cout << "\nInvalid access mode!\nHint: administrator/user/exit\n\n";
	}
}

void UI::generate_10_movies()
{
	this->admin_serv.add_movie("The Devil Wears Prada", "Drama", "https://tinyurl.com/4f4skkbb", "2006", "100");
	this->admin_serv.add_movie("Inception", "Sci-Fi", "https://www.youtube.com/watch?v=YoHD9XEInc0", "2010", "950");
	this->admin_serv.add_movie("The Grand Budapest Hotel", "Comedy", "https://www.youtube.com/watch?v=1Fg5iWmQjwk", "2014", "720");
	this->admin_serv.add_movie("Parasite", "Thriller", "https://www.youtube.com/watch?v=5xH0HfJHsaY", "2019", "860");
	this->admin_serv.add_movie("La La Land", "Musical", "https://www.youtube.com/watch?v=0pdqf4P9MB8", "2016", "780");
	this->admin_serv.add_movie("Interstellar", "Sci-Fi", "https://www.youtube.com/watch?v=zSWdZVtXT7E", "2014", "980");
	this->admin_serv.add_movie("Whiplash", "Drama", "https://www.youtube.com/watch?v=7d_jQycdQGo", "2014", "640");
	this->admin_serv.add_movie("The Social Network", "Biography", "https://www.youtube.com/watch?v=lB95KLmpLR4", "2010", "690");
	this->admin_serv.add_movie("Joker", "Crime", "https://www.youtube.com/watch?v=zAGVQLHvwOY", "2019", "820");
	this->admin_serv.add_movie("Pulp Fiction", "Crime", "https://www.youtube.com/watch?v=s7EdQ4FqbhY", "1994", "900");
}

/// Adds a movie using the service, takes input from user
void UI::handle_add_movie()
{
	std::string t = "", g = "", tr = "";
	int l{ 0 }, y{ 0 };
	std::cout << "Title: ";
	if (std::cin.peek() == '\n')
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, t);

	std::cout << "Genre: ";
	std::getline(std::cin, g);

	std::cout << "Trailer Link: ";
	std::getline(std::cin, tr);

	std::string year_input;
	while (true) {
		std::cout << "Release Year: ";
		std::cin >> year_input;

		if (this->valid.is_year(year_input)){
			break;
		}
		else {
			std::cout << "Invalid input! Please enter a valid year.\n";
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer
	}

	std::string likes_input;
	while (true) {
		std::cout << "Likes: ";
		std::cin >> likes_input;

		if (this->valid.is_number(likes_input)) {
			if (!this->valid.is_negative(stod(likes_input))) {
				break;
			}
			else
				std::cout << "Invalid input! Please enter a valid number of likes.\n";
		}
		else {
			std::cout << "Invalid input! Please enter a valid number of likes.\n";
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer
	}
	try {
		bool check_add = this->admin_serv.add_movie(t, g, tr, year_input, likes_input);
		if (check_add) {
			std::cout << "Movie added successfully!\n";
		}
		else
			std::cout << "A movie with that title and genre exists!\n";
	}
	catch (MyException& e) {
		std::cout << e.what();
	}

}

// Removies a movie by taking input from user. 
void UI::handle_remove_movie()
{
	std::string t = "", g = "";
	std::cout << "Title: ";
	if (std::cin.peek() == '\n')
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, t);

	std::cout << "Genre: ";
	std::getline(std::cin, g);

	if (this->valid.is_empty(t) || this->valid.is_empty(g)){
		std::cout << "Title and genre should not be empty!\n";
	}
	bool check_remove = this->admin_serv.remove_movie(t, g);
	if (check_remove) {
		std::cout << "Movie removed successfully!\n";
	}
	else
		std::cout << "A movie with that title and genre does not exist!\n";
}

//updates the movie by taking user input
void UI::handle_update_movie()
{
	std::string t = "", g = "";
	std::cout << "Title of movie you wish to update: ";
	if (std::cin.peek() == '\n')
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, t);

	std::cout << "Genre of movie you wish to update: ";
	std::getline(std::cin, g);

	std::string new_t = "", new_g = "", new_tr = "";
	std::cout << "New title: ";
	std::getline(std::cin, new_t);

	std::cout << "New genre: ";
	std::getline(std::cin, new_g);

	std::cout << "New Trailer Link: ";
	std::getline(std::cin, new_tr);

	std::string year_input;
	while (true) {
		std::cout << "Release Year: ";
		std::cin >> year_input;

		if (this->valid.is_year(year_input)) {
			break;
		}
		else {
			std::cout << "Invalid input! Please enter a valid year.\n";
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::string likes_input;
	while (true) {
		std::cout << "Likes: ";
		std::cin >> likes_input;

		if (this->valid.is_number(likes_input)) {
			if (!this->valid.is_negative(std::stod(likes_input))) {
				break;
			}
			else {
				std::cout << "Invalid input! Please enter a valid number of likes.\n";
			}
		}
		else {
			std::cout << "Invalid input! Please enter a valid number of likes.\n";
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	try {
		bool check_update = this->admin_serv.update_movie(t, g, new_t, new_g, new_tr, likes_input, year_input);
		if (check_update) {
			std::cout << "Movie updated successfully!\n";
		}
		else {
			std::cout << "A movie with that title and genre does not exist!\n";
		}
	}
	catch (MyException& e) {
		std::cout << e.what();
	}
}


//Displays all movies
void UI::handle_display_all()
{
	std::vector<Movie> all = this->admin_serv.get_all_movies();
	if (all.size() == 0)
	{
		std::cout << "No movies exist.\n";
		return;
	}
	int i = 0;
	for (const auto& current_movie : all) {
		i++;
		std::cout << i << ".\n";
		std::cout << "Title: " << current_movie.getTitle() << "  Genre: " << current_movie.getGenre() << "\n";
		std::cout << "Release year: " << current_movie.getYear() << "  Likes: " << current_movie.getLikes() << "\n";
		std::cout << "Trailer Link: " << current_movie.getTrailer() << "\n\n";
	}
}

void UI::admin_menu()
{
	std::cout << "\n     --ADMIN MENU--  \n";
	std::cout << "1. Add Movie\n";
	std::cout << "2. Remove Movie\n";
	std::cout << "3. Update Movie\n";
	std::cout << "4. See all database movies\n";
	std::cout << "0. Exit\n";
}


/// <summary>
/// handler for administrator mode
/// prints the menu and executes choices
/// </summary>
void UI::admin_mode()
{
	int option;
	while (true) {
		admin_menu();
		std::cout << "Enter your option: ";
		option = get_correct_int_choice();
		if (option < 0 || option>4) {
			std::cout << "Invalid input! Please enter a valid option.\n";
			continue;
		}
		switch (option) {
		case 0:
			return;
		case 1:
			handle_add_movie();
			break;
		case 2:
			handle_remove_movie();
			break;
		case 3:
			handle_update_movie();
			break;
		case 4:
			handle_display_all();
			break;
		default:
			std::cout << "\nInvalid option! Please try again!\n\n";
			break;
		}

	}
}

/// Function for handling choice reading
static std::string choice() {
	std::cout << ">" << std::flush;
	std::string bugs_bunny;
	std::getline(std::cin, bugs_bunny);
	return bugs_bunny;
}

// Function that prints a movie in the absense of a tostring
void UI::print_movie(Movie current_movie) {
	std::cout << "Title: " << current_movie.getTitle() << "  Genre: " << current_movie.getGenre() << "\n";
	std::cout << "Release year: " << current_movie.getYear() << "  Likes: " << current_movie.getLikes() << "\n";
	std::cout << "Trailer Link: " << current_movie.getTrailer() << "\n\n";
}


//Function that checks if the choice is an integer
int UI::get_correct_int_choice()
{
	while (true) {
		while (std::cin.peek() == '\n') std::cin.ignore();

		std::string choice;
		std::getline(std::cin, choice);

		if (!is_numerical(choice) || choice.empty()) {
			std::cout << "Invalid input. Try again.\n";
			continue;
		}
		return stoi(choice);
	}
}

// Funtion that checks if a string is made up only of numbers
bool UI::is_numerical(std::string s)
{
	for (char c : s) {
		if (!isdigit(c))
			return false;
	}
	return true;
}


// FUnction that opens a movie's trailer in browser
int UI::handle_show_in_browser(Movie m) {
	print_movie(m);
	std::string s = m.getTrailer();
	std::string command = "start " + s;
	system(command.c_str());
	std::cout << "Do you want to add this movie to your watchlist? Y/N" << std::endl;
	while (true) {
		std::string ch = choice();
		if (ch == "Y") {
			add_movie_to_watchlist_ui(m.getTitle(), m.getGenre());
			return 0;
		}
		else if (ch == "exit")
			return -1;
		else if (ch == "N")
			return 0;
	}
}


// Function that prints movies from a given genre (by the user) and opens their trailers one by one
void UI::handle_see_movies_one_by_one_from_genre()
{
	std::string genre;
	std::cout << "Enter the genre: ";
	if (std::cin.peek() == '\n')
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, genre);
	std::vector<Movie> cardi_b = this->user_serv.get_movies_from_genre(genre);

	if (cardi_b.size() < 1) {
		std::cout << "No movies belonging to that genre were found!\n";
		return;
	}

	int i = 0;

	int k = handle_show_in_browser(cardi_b[i]);
	if (k == -1)
		return;
	std::cout << "Type 'next' to see the next movie and trailer, exit to exit .\n";
	while (true) {
		std::string cho = choice();
		if (cho == "exit") {
			return;
		}
		else if (cho == "next") {
			i++;
			if (i == cardi_b.size())
				i = 0;
			k = handle_show_in_browser(cardi_b[i]);
			if (k == -1)
				return;
		}

	}

}

//Adds a movie to the user's watchlist
void UI::add_movie_to_watchlist_ui(std::string title, std::string genre)
{
	try {
		this->user_serv.add_movie_to_watchlist(title, genre);
	}
	catch(std::exception& e){
		std::cout << e.what();
	}
}


//Removes a movie from user's watchlist
void UI::remove_movie_from_watchlist(std::string title, std::string genre)
{
	try { 
		this->user_serv.delete_movie_from_watchlist(title, genre); 
		std::cout << "Successfully deleted movie from watchlist. \n ";
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
}

//Handler toremove a movie from watchlist
//Prompts the user to check if they want to leave a like
void UI::handle_remove_movie_from_watchlist() {
	bool ok = true;
	std::cout << "Title: ";
	std::string t, g;
	if (std::cin.peek() == '\n')
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, t);
	std::cout << "Genre: ";
	if (std::cin.peek() == '\n')
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, g);
	std::cout << "Do you wish to leave a like for this movie? Y/N\n";
	while (true) {
		std::string answer;
		std::cout << ">";
		while (std::cin.peek() == '\n')
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, answer);
		if (answer == "Y") {
			try {
				this->user_serv.like_a_movie(t, g);
			}
			catch(std::exception& e){
				std::cout << e.what();
				ok = false;
			}
			break;
		}
		else if (answer == "N")
		{
			break;
		}

	}
	if (ok == true) {
		remove_movie_from_watchlist(t, g);
	}

}

//Prints the watchlist
void UI::show_watchlist()
{
	std::vector<Movie> watchlist = this->user_serv.get_watchlist();
	if (watchlist.size() < 1)
	{
		std::cout << "Watchlist is empty!\n";
		return;
	}
	std::cout << '\n';
	for (const Movie& m : watchlist) {
		print_movie(m);
	}
}
void UI::open_file(std::string type) {
	if (type == "csv")
		system("start watchlist.csv");
	else
		system("start watchlist.html");
}

void UI::show_sorted_movies()
{
	std::vector<Movie> movies = this->admin_serv.get_all_movies();

	ComparatorAscendingByTitle<Movie> t;
	ComparatorDescendingByGenre<Movie> g;

	genericSort<Movie>(movies, t);
	std::cout << "Sorted ascending by title:\n\n";
	for (const auto& m : movies) {
		print_movie(m);
	}
	std::cout << "\n\n\n\n";

	genericSort<Movie>(movies, g);
	std::cout << "Sorted descending by genre:\n\n";
	for (const auto& m : movies) {
		print_movie(m);
	}
}

//user menu
void UI::user_menu()
{
	std::cout << "\n     --USER MENU--  \n";
	std::cout << "1. See the movies in the database having a given genre\n";
	std::cout << "2. Delete a movie from the watch list\n";
	std::cout << "3. See the watch list\n";
	std::cout << "4. Open the watch list in the saved file\n";
	std::cout << "5. Show movies sorted in 2 ways\n";
	std::cout << "0. Exit\n";
}

/// <summary>
/// user handler
/// </summary>
void UI::user_mode(int way)
{
	std::string whatfile;
	std::string file = whatfile;
	if (way != 1)
	{
		std::cout << "Your watchlist will be saved in a:\n1)csv\n2)html\nFile.\nPick one of them. Or else.\n";
		std::string whatfile;
		if (std::cin.peek() == '\n')
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, whatfile);
		if (whatfile == "1")
			file = "csv";
		else if (whatfile == "2")
			file = "html";
		this->user_serv.set_file(file);
	}
	else
		file = "notset";
	int option;
	while (true) {
		user_menu();
		std::cout << "Pick an option: ";
		option = get_correct_int_choice();
		if (option < 0 || option>5) {
			std::cout << "Pick an option between 0 and 5.\n";
			continue;
		}
		switch (option) {
		case 0:
			return;
		case 1:
			handle_see_movies_one_by_one_from_genre();
			break;
		case 2:
			handle_remove_movie_from_watchlist();
			break;
		case 3:
			show_watchlist();
			break;
		case 4:
			open_file(file);
			break;
		case 5:
			show_sorted_movies();
			break;
		default:
			break;
		}

	}
}


