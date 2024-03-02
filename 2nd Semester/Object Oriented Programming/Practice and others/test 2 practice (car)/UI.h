//
// Created by User on 5/11/2023.
//

#ifndef TEST_2_PRACTICE_CAR_UI_H
#define TEST_2_PRACTICE_CAR_UI_H

#pragma once
#include "Service.h"
#include <iostream>
#include <fstream>
using namespace std;


class UI
{
private:
    Service service;

public:
    UI(){};
    ~UI(){};
    void addCar();
    void showAllCars();
    void writeCarsWithSmallerPriceToFile();
    void runApp();
};

#endif //TEST_2_PRACTICE_CAR_UI_H
