//
// Created by User on 5/11/2023.
//

#ifndef TEST_2_PRACTICE_CAR_CAR_H
#define TEST_2_PRACTICE_CAR_CAR_H

#pragma once
#include "Engine.h"

class Car
{
private:
    std::string bodyStyle;
    Engine *engine;

public:
    Car(std::string bodyStyle = "", Engine *engine = nullptr) : bodyStyle{bodyStyle}, engine{engine} {};
    ~Car(){};
    double computePrice();
    std::string toString();
};

#endif //TEST_2_PRACTICE_CAR_CAR_H
