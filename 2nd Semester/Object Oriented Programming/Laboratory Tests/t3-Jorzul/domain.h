//
// Created by User on 5/24/2023.
//

#pragma once
#include <vector>
#include <iostream>

using namespace std;

typedef struct {
    string category;
    string name;
    int quantity;
}Item;

Item Create_Item(string category, string name, int quantity);

string get_category(Item the_item);

string get_name(Item the_item);