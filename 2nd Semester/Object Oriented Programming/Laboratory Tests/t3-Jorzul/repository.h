//
// Created by User on 5/24/2023.
//

#pragma once

#include "domain.h"

class Repository {
private:
    vector<Item> Shopping_List;

public:

    void add_item_to_shopping_list_repo(Item item);

    vector<Item> get_all_items_from_the_shopping_list();

    Repository() = default;
};
