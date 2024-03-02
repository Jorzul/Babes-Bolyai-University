//
// Created by User on 5/11/2023.
//

#ifndef TEST_2_PRACTICE_CAR_ENGINE_H
#define TEST_2_PRACTICE_CAR_ENGINE_H

#pragma once
#include <iostream>

class Engine
{
protected:
    std::string fuelType;
    double basePrice;

public:
    Engine(std ::string fuelType = "") : fuelType{fuelType}, basePrice{3000} {};
    virtual ~Engine(){};
    virtual double getPrice() { return 0; };
    virtual std::string toString();
};

class ElectricEngine : public Engine
{
private:
    int autonomy;

public:
    ElectricEngine(std::string fuelType = "", int autonomy = 0) : Engine{fuelType}, autonomy{autonomy} {};
    double getPrice();
    std::string toString();
};

class TurboEngine : public Engine
{
public:
    TurboEngine(std::string fuelType = "") : Engine{fuelType} {};
    double getPrice();
    std::string toString();
};

#endif //TEST_2_PRACTICE_CAR_ENGINE_H
