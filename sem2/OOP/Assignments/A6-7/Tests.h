#pragma once
#include "AdminService.h"
#include "UserService.h"
#include <cassert>


//TODO: ask about validators in repo/serv

void test_serv_add(User_Service u_serv, Admin_Service a_serv) {
	//printf("Testing add..\n");

	bool ok = a_serv.add_movie("Plush", "Cat", "hihi", "2000", "123");
	assert(ok == true);
	std::vector<Movie> check = a_serv.get_all_movies();
	assert(check[0].getTitle() == "Plush");
	assert(check[0].getGenre() == "Cat");
	assert(check[0].getTrailer() == "hihi");
	assert(check[0].getLikes() == 123);
	assert(check[0].getYear() == 2000);

	bool ok1 = a_serv.add_movie("Plush", "Cat", "hihi", "2000", "123");
	assert(ok1 == false);

	bool ok2 = a_serv.add_movie("Obama", "Prism", "hihi", "2000", "123");
	assert(ok2 == true);
}

void test_serv_remove(User_Service u_serv, Admin_Service a_serv) {
	//printf("Testing remove..\n");
	bool s = a_serv.remove_movie("Plush", "Cat");
	assert(s == true);
	std::vector<Movie>movies = a_serv.get_all_movies();
	assert(movies.size() == 1);

	bool s1 = a_serv.remove_movie("Plush", "Cat");
	assert(s1 == false);
}

void test_serv_update(User_Service u_serv, Admin_Service a_serv) {
	//printf("Testing update...");

	bool s = a_serv.update_movie("Obama", "Prism", "Lemon", "Curd", "lol", " 12", "1345");
	bool s1 = a_serv.remove_movie("Obama", "Prism");
	assert(s1 == false);

	std::vector<Movie> m = a_serv.get_all_movies();
	assert(m.size() == 1);
	assert(m[0].getTitle() == "Lemon");
	assert(m[0].getGenre() == "Curd");
	assert(m[0].getTrailer() == "lol");
	assert(m[0].getLikes() == 12);
	assert(m[0].getYear() == 1345);

	bool s2 = a_serv.update_movie("Obama", "Prism", "Lemon", "Curd", "lol", "12", "1345");
	assert(s2 == false);
}

void test_get_all_movies(User_Service u_serv, Admin_Service a_serv) {
	std::vector<Movie> m = a_serv.get_all_movies();
	assert(m.size() == 1);

	(void)a_serv.add_movie("Plush", "Cat", "hihi", " 2000", "123");

	std::vector<Movie> m2 = a_serv.get_all_movies();
	assert(m2.size() == 2);
}

void test_repo_get_movie_by(Repo repo) {
	bool i = repo.get_movie_index_by_title_and_genre("Lemon", "Curd");
	assert(i == 0);
	bool j = repo.get_movie_index_by_title_and_genre("Plush", "Cat");
	assert(j == 1);
}

void test_movie() {
	Movie m("A", "B", "C", 1000, 10);
	assert(m.getTitle() == "A");
	assert(m.getGenre() == "B");
	assert(m.getTrailer() == "C");
	assert(m.getYear() == 1000);
	assert(m.getLikes() == 10);

	m.setGenre("Kermit");
	m.setTitle("Bob");
	m.setTrailer("youtube.com");
	m.setLikes(69);
	m.setYear(2025);

	assert(m.getTitle() == "Bob");
	assert(m.getGenre() == "Kermit");
	assert(m.getTrailer() == "youtube.com");
	assert(m.getYear() == 2025);
	assert(m.getLikes() == 69);

	Movie second("Bob", "Kermit", "youtube.com", 2025, 69);
	assert(second == m);

	Movie third("Freshavocado", "DelTaco", "YouTube.com", 2014, 1005);
	m = third;
	assert(m.getTitle() == "Freshavocado");
	assert(m.getGenre() == "DelTaco");
	assert(m.getTrailer() == "YouTube.com");
	assert(m.getYear() == 2014);
	assert(m.getLikes() == 1005);

}


void test_get_movies_from_genre(User_Service u_serv, Admin_Service a_serv) {
	a_serv.add_movie("The Devil Wears Prada", "Drama", "https://tinyurl.com/4f4skkbb", "2006", "100");
	a_serv.add_movie("Inception", "Sci-Fi", "https://www.youtube.com/watch?v=YoHD9XEInc0", " 2010", " 950");
	a_serv.add_movie("The Grand Budapest Hotel", "Comedy", "https://www.youtube.com/watch?v=1Fg5iWmQjwk", " 2014", "720");
	a_serv.add_movie("Parasite", "Thriller", "https://www.youtube.com/watch?v=5xH0HfJHsaY", "2019", "860");
	a_serv.add_movie("La La Land", "Musical", "https://www.youtube.com/watch?v=0pdqf4P9MB8", "2016", " 780");
	a_serv.add_movie("Interstellar", "Sci-Fi", "https://www.youtube.com/watch?v=zSWdZVtXT7E", "2014", " 980");
	a_serv.add_movie("Whiplash", "Drama", "https://www.youtube.com/watch?v=7d_jQycdQGo", "2014", " 640");
	a_serv.add_movie("The Social Network", "Biography", "https://www.youtube.com/watch?v=lB95KLmpLR4", "2010", "690");
	a_serv.add_movie("Joker", "Crime", "https://www.youtube.com/watch?v=zAGVQLHvwOY", "2019", " 820");
	a_serv.add_movie("Pulp Fiction", "Crime", "https://www.youtube.com/watch?v=s7EdQ4FqbhY", "1994", "900");

	std::vector<Movie> movies = u_serv.get_movies_from_genre("Drama");
	assert(movies.size() == 2);

	std::vector<Movie> movies1 = u_serv.get_movies_from_genre("Goobligock");
	assert(movies1.size() == 0);

	std::vector<Movie> movies2 = u_serv.get_movies_from_genre("");
	assert(movies2.size() == 12);
}

void test_watchlist(User_Service u_serv, Admin_Service a_serv) {
	std::vector<Movie> w = u_serv.get_watchlist();
	assert(w.size() == 0);
	bool ex1 = false;
	try { u_serv.add_movie_to_watchlist("Whiplash", "Drama"); }
	catch (std::exception e) { ex1 = true; };
	assert(ex1 == false);
	std::vector<Movie> w1 = u_serv.get_watchlist();
	assert(w1.size() == 1);

	try { u_serv.delete_movie_from_watchlist("Whiplash", "Drama"); }
	catch (std::exception e) { assert(false); };
	std::vector<Movie> w2 = u_serv.get_watchlist();
	assert(w2.size() == 0);

	bool k1 = false;
	try { 
		u_serv.delete_movie_from_watchlist("Whiplash", "Drama"); 
	}
	catch(std::exception e) {
		k1 = true; 
	};
	assert(k1==true);
	bool k2 = false;
	try { u_serv.add_movie_to_watchlist("Idontexist", "Drama"); }
	catch (std::exception e) { k2 = true; };
	assert(k2 == true);
}

void test_like_a_movie(User_Service u_serv, Admin_Service a_serv) {
	try { u_serv.like_a_movie("Whiplash", "Drama"); }
	catch (std::exception e) { assert(false); };

	bool i1 = false;
	try { u_serv.like_a_movie("IMNOTREAL", "Drama"); }
	catch (std::exception e) { i1 = true; };
	assert(i1 == true);

	std::vector<Movie> CAMION = a_serv.get_all_movies();
	Movie m = CAMION[8];
	assert(m.getLikes() == 641);

}


void run_tests() {
	std::vector<Movie> mock_movies;
	std::vector<Movie> w;
	Watch_Repository mock_watchlist(w);
	Repo mock_repo(mock_movies);
	Admin_Service ad(mock_repo);
	User_Service us(mock_repo,mock_watchlist);

	test_movie();

	test_serv_add(us, ad);
	test_serv_remove(us, ad);
	test_serv_update(us, ad);
	test_get_all_movies(us, ad);
	test_repo_get_movie_by(mock_repo);
	test_get_movies_from_genre(us, ad);
	test_watchlist(us, ad);
	test_like_a_movie(us, ad);
}