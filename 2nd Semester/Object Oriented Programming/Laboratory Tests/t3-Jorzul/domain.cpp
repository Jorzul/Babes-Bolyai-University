//
// Created by User on 5/24/2023.
//

#include "domain.h"

Item Create_Item(string category, string name, int quantity)
{
    Item new_item;

    new_item.category = category;
    new_item.name = name;
    new_item.quantity = quantity;

    return new_item;
}

string get_category(Item the_item)
{
    return the_item.category;
}

string get_name(Item the_item)
{
    return the_item.name;
}
