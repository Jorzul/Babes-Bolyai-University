//
// Created by User on 5/11/2023.
//

#include "Service.h"

Engine *Service::createEngine(string engineType, int autonomy)
{
    Engine *engine = nullptr;
    if (engineType == "Electric")
        engine = new ElectricEngine(autonomy);
    if (engineType == "Turbo")
        engine = new TurboEngine();
    return engine;
}

void Service::addCar(int numberOfDoors, string engineType, int autonomy)
{
    Engine *engine = createEngine(engineType, autonomy);
    this->cars.push_back(Car(numberOfDoors, engine));
}

Car Service::get_last_added_car()
{
    return this->cars.back();
}

void Service::getCarsWithMaxPrice(double maxPrice)
{
    return;
}

vector<Car> Service::getAllCars()
{
    return this->cars;
}