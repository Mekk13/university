#include "UI.h"
#include <crtdbg.h>
#include <windows.h>
#include <shellapi.h>
#include "Tests.h"

int main() {
	{
		//run_tests();
		DynamicVector<Movie> all_movies;
		Repo repo(all_movies);
		Admin_Service admin_serv(repo);
		User_Service user_serv(repo);
		UI console(admin_serv,user_serv);
		console.start_application(); 

	}
	_CrtDumpMemoryLeaks();
	return 0;
}