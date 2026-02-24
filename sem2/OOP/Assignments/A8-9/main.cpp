#include "A89.h"
#include <QtWidgets/QApplication>
#include "ui_FileFormatDialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    A89 w;
    w.show();
    return a.exec();
}
