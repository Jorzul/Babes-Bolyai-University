//
// Created by User on 5/11/2023.
//

#ifndef T2_JORZUL_1_UI_H
#define T2_JORZUL_1_UI_H

#include "Service.h"
#include <iostream>

class UI
{
private:
    Service service;

public:
    UI(){};
    ~UI(){};
    void add_car();
    void show_all_cars();
    void save_to_file_cars();
    void runApp();
};

#endif //T2_JORZUL_1_UI_H
