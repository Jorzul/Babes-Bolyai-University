//
// Created by User on 5/11/2023.
//

#ifndef TEST_2_PRACTICE_ME_CAR_H
#define TEST_2_PRACTICE_ME_CAR_H

#include <iostream>
#pragma once
using namespace std;

class Engine
{
protected:
    string fuelType;
    double basePrice;
public:
    Engine() : fuelType{""}, basePrice{0} {};
    Engine(string fuelType, double basePrice) : fuelType{fuelType}, basePrice{basePrice} {};
    virtual double getPrice() { return this->basePrice; };
    virtual string toString();
};

class ElectricEngine : public Engine
{
private:
    int autonomy;
public:
    double getPrice() { return this->basePrice + 0.01 * autonomy; };
    string toString();
};

class TurboEngine : public Engine
{
public:
    double getPrice();
    string toString();
};

class Car
{
protected:
    static string bodyStyle;
    Engine engine;
public:
    double computePrice();
    static string toString();
};

#endif //TEST_2_PRACTICE_ME_CAR_H
