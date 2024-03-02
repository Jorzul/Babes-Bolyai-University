//
// Created by User on 5/11/2023.
//

#ifndef TEST_2_PRACTICE_CAR_SERVICE_H
#define TEST_2_PRACTICE_CAR_SERVICE_H

#pragma once
#include "Car.h"
#include <fstream>
#include <vector>

class Service
{
private:
    std::vector<Car> cars;
    Engine *createEngine(std::string engineType, std::string fuelType, int autonomy = 0);

public:
    Service() { this->generateEntries(); };
    ~Service()
    {
        for (auto car : this->cars)
            car.~Car();
    };
    Car getLastAddedCar();
    void generateEntries();
    static inline bool comparisonFunction(Car car1, Car car2);
    void addCar(std::string bodyStyle, std::string engineType, std::string fuelType, int autonomy = 0);
    std::vector<Car> getCarsWithMaximumPrice(double maxPrice);
    std::vector<Car> getAllCars();
    void writeToFile(std::string fileName, std::vector<Car> cars);
};

#endif //TEST_2_PRACTICE_CAR_SERVICE_H
