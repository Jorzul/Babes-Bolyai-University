//
// Created by User on 5/24/2023.
//

#include "service.h"

void Service::add_new_item_to_shopping_list_service(string category, string name, int quantity)
{
    Item item_we_want_to_add = Create_Item(category, name, quantity);
    this->repo.add_item_to_shopping_list_repo(item_we_want_to_add);
}

vector<Item> Service::get_all_items_from_shopping_list_service()
{
    return this->repo.get_all_items_from_the_shopping_list();
}

Service::Service(const Repository& repository)
{
    this->repo = repository;
}
