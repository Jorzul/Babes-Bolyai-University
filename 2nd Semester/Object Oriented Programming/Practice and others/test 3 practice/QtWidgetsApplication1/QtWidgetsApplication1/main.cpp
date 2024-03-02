#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>
#include "repository.h"
#include "service.h"

int main(int argc, char *argv[])
{
    char type[] = "Audi";
    char model[] = "A3";
    char color[] = "black";

    add_car_service(type, model, 2012, color);

    QApplication a(argc, argv);
    QtWidgetsApplication1 w;
    w.show();

    return a.exec();
}
