#include "Test3.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Test3 window;
    window.show();
    return app.exec();
}
