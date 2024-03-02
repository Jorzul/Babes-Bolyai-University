//
// Created by User on 5/24/2023.
//
#include "repository.h"

void Repository::add_item_to_shopping_list_repo(Item item)
{
    Shopping_List.push_back(item);
}

vector<Item> Repository::get_all_items_from_the_shopping_list()
{
    return Shopping_List;
}
