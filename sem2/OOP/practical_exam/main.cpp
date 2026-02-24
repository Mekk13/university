#include "practical_exam.h"
#include <QtWidgets/QApplication>
#include "Repo.h"
#include "Service.h"
#include "MyModel.h"
#include "Researcher_Window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Repo repo;
    Service serv(repo);
    vector<Researcher> researchers = serv.getResearchers();
    
	
    TableModel* sharedModel = new TableModel(serv);
    sharedModel->setitems(serv.getSortedIdeas());

    for (auto& r : researchers) {
        Researcher_Window* window = new Researcher_Window(serv, sharedModel, r.getName(),r.getPosition());
        window->show();
    }
    return app.exec();
}
