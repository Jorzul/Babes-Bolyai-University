//
// Created by User on 5/11/2023.
//

#ifndef T2_JORZUL_1_CAR_H
#define T2_JORZUL_1_CAR_H

#include "Engine.h"

class Car
{
protected:
    int numberOfDoors;
    Engine *engine;

public:
    Car(int numberOfDoors = 0, Engine* engine = nullptr) : numberOfDoors{numberOfDoors}, engine{engine} {};
    double computePrice();
    string toString();
};

#endif //T2_JORZUL_1_CAR_H
