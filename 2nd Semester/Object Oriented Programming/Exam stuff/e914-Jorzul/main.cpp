//
// Created by User on 6/14/2023.
//
#include <QtWidgets/QApplication>
#include "Controller.h"
#include "gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repository repository{true};
    Controller controller{ repository };

    gui w{repository, ""};

    w.show();

    return a.exec();
}