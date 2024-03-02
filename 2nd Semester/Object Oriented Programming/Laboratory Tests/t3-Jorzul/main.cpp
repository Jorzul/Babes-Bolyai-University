//
// Created by User on 5/24/2023.
//
#include "Test3.h"
#include <QtWidgets/QApplication>
#include "domain.h"
#include "repository.h"
#include "service.h"

int main(int argc, char *argv[])
{
    Repository repository;
    Service service(repository);

    service.add_new_item_to_shopping_list_service("Drinks", "Orange juice", 5);
    service.add_new_item_to_shopping_list_service("Dairy", "Yogurt", 6);
    service.add_new_item_to_shopping_list_service("Drinks", "Chocolate", 3);
    service.add_new_item_to_shopping_list_service("Drinks", "H", 4);

    QApplication a(argc, argv);
    Test3 w;
    w.show();
    return a.exec();
}
