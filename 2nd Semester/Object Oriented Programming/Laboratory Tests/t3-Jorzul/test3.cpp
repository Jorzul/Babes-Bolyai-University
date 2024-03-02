//
// Created by User on 5/24/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Test3.h" resolved

#include "Test3.h"
#include "domain.h"
#include "service.h"

Test3::Test3(QWidget *parent)
        : QMainWindow(parent)
{
    ui.setupUi(this);

    populate_List();
}

Test3::~Test3()
{}

void Test3::populate_List()
{
    Repository repository;
    Service serv(repository);
    vector<Item> shopping_list = serv.get_all_items_from_shopping_list_service();

    for (auto& item_in_shopping_list : shopping_list)
    {
        this->ui.listWidget->addItem(QString::fromStdString(get_category(item_in_shopping_list) + " | " + get_name(item_in_shopping_list)));
    }
}
