#pragma once 
#include "Movie.h"
#include "AdminService.h"
#include "UserService.h"
#include <string>
#include <cstdlib>

class UI {
private:
	Admin_Service admin_serv;
	User_Service user_serv;

public:
	UI(Admin_Service admin,User_Service user);
	void start_application();
	void generate_10_movies();
	void print_movie(Movie current_movie);

	int get_correct_int_choice();
	bool is_numerical(std::string s);

	//ADMIN:
	void handle_add_movie();
	void handle_remove_movie();
	void handle_update_movie();
	void handle_display_all();
	void admin_menu();
	void admin_mode();

	//USER: TODO
	void handle_see_movies_one_by_one_from_genre();
	int handle_show_in_browser(Movie m);
	void add_movie_to_watchlist_ui(std::string title, std::string genre);
	void remove_movie_from_watchlist(std::string title, std::string genre);
	void handle_remove_movie_from_watchlist();
	void show_watchlist();
	void user_menu();
	void user_mode();
};