#include "UI.h"
#include <crtdbg.h>
#include "Tests.h"
int main() {
	{
		run_tests();
		DynamicVector<Film> f;
		Repository repo(f);
		Service serv(repo);
		UI console(serv);
		console.start();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}