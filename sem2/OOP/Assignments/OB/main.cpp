#include "OB.h"
#include <QtWidgets/QApplication>

#include "Service.h"
#include "User_Window.h"
#include "Admin_Window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	Repo repo;
	Service service(&repo);

	for (auto& user : service.getUsers()) {
		if (user.getType() == "administrator") {
			auto* win1 = new Admin_Window(user, &service);
			win1->show();
		}
		else if (user.getType() == "collector") {
			auto* win2 = new User_Window(user, &service);
			win2->show();
		}
		
	}

    return app.exec();
}
