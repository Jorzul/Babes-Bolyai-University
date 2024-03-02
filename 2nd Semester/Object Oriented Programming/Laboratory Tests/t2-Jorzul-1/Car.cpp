//
// Created by User on 5/11/2023.
//

#include "Car.h"

double Car::computePrice() {
    double price = 7000 + this->engine->getPrice();
    if (numberOfDoors == 4)
        price += 1500;
    return price;
}

string Car::toString() {
    string CarString = "Number of doors: " + to_string(numberOfDoors) + this->engine->toString() + " | Price: " + to_string(computePrice());
    return CarString;
}