//
// Created by User on 5/24/2023.
//

#pragma once
#include "repository.h"

class Service {
private:
    Repository repo;

public:

    void add_new_item_to_shopping_list_service(string category, string name, int quantity);

    vector<Item> get_all_items_from_shopping_list_service();

    Service(const Repository& repo);

    Service() = default;
};