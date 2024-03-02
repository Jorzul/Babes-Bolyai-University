//
// Created by User on 5/11/2023.
//

#include "Car.h"

string Engine::toString() {
    std::string stringEngine;
    stringEngine = " | Fuel: " + fuelType + " | Price" + to_string(basePrice) + Car::toString();
    return stringEngine;
}

string ElectricEngine::toString() {
    string stringElectric = "Engine: Electric | " + Engine::toString();
    return stringElectric;
}

double TurboEngine::getPrice() {
    if (this->fuelType == "diesel")
        this->basePrice = this->basePrice + 1;

    if (this->fuelType == "gasoline")
        this->basePrice = this->basePrice + 2;
    return this->basePrice;
}

string TurboEngine::toString() {
    string stringTurbo = "Engine: Turbo | " + Engine::toString();
    return stringTurbo;
}

string Car::toString() {
    string stringCar = " | Car type: " + bodyStyle;
}

double Car::computePrice() {
    return 9;
}