#include "UI.h"
#include <crtdbg.h>
#include <windows.h>
#include <shellapi.h>
#include "Tests.h"
#include "FileRepo.h"
#include "WatchlistRepo.h"
int main() {
	{
		///run_tests();
		std::vector<Movie> all_movies;
		std::vector<Movie> watchlist;
		Repo* repo;
		Watch_Repository watch_repo(watchlist);
		std::cout << "1 - memory, 2 - file: ";
		int choice;
		std::cin >> choice;

		if (choice == 1)
			repo = new Repo;
		else
			repo = new FileRepo("movies.txt");
		Admin_Service admin_serv(*repo);
		User_Service user_serv(*repo,watch_repo);
		UI console(admin_serv, user_serv);
		console.start_application(int(choice));
		delete repo;
	}
	_CrtDumpMemoryLeaks();
	return 0;
}