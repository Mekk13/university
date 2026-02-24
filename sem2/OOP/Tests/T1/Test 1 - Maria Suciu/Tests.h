#include "Service.h"
#include <cassert>


//this->serv.add_film("Interstellar", "Nolan", "Sci-Fi , Space");
//this->serv.add_film("Dune part 2", "Denis", "Sci-Fi , Adv");
//this->serv.add_film("Barbie", "Greta", "Comedy , Fantasy");
//this->serv.add_film("Titanic", "James", "Romance , Drama");
//this->serv.add_film("Pride and Prejudice", "Helena", "Romance , Drama");

void test_add(Service s) {
	int ok = s.add_film("Interstellar", "Nolan", "Sci-Fi , Space");
	assert(ok == 1);
	int ok2 = s.add_film("Interstellar", "Nolan", "Sci-Fi , Space");
	assert(ok2 == 0);
}


void run_tests() {
	DynamicVector<Film> f;
	Repository repo(f);
	Service serv(repo);
	test_add(serv);
}