#include "OOP_individual_work_2.h"
#include <QtWidgets/QApplication>
#include "Chat_Window.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChatSession session;
	Chat_Window w("Ana", &session);
	Chat_Window w1("Alexa",&session);
	w.show();
	w1.show();
	return a.exec();

}
