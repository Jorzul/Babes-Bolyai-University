//
// Created by User on 5/11/2023.
//

#ifndef T2_JORZUL_1_SERVICE_H
#define T2_JORZUL_1_SERVICE_H

#include "Car.h"
#include "Engine.h"
#include <iostream>
#include <vector>
using namespace std;

class Service
{
private:
    vector<Car> cars;
    Engine *createEngine(string engineType, int autonomy);

public:
    Car get_last_added_car();

    void addCar(int numberOfDoors, string EngineType, int autonomy);
    void getCarsWithMaxPrice(double maxPrice);

    vector<Car> getAllCars();
};

#endif //T2_JORZUL_1_SERVICE_H
