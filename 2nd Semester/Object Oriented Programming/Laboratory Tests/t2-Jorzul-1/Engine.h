//
// Created by User on 5/11/2023.
//

#ifndef T2_JORZUL_1_ENGINE_H
#define T2_JORZUL_1_ENGINE_H

#include <iostream>
using namespace std;

class Engine
{
protected:
    double basePrice;

public:
    Engine() : basePrice{3000} {};
    virtual ~Engine() {};

    virtual double getPrice() {return this->basePrice; };
    virtual string toString();
};

class ElectricEngine : public Engine
{
private:
    int autonomy;

public:
    ElectricEngine(int autonomy = 0) : Engine{}, autonomy{autonomy} {};
    double getPrice();
    string toString();
};

class TurboEngine : public Engine
{
public:
    TurboEngine() : Engine{} {};
    double getPrice();
    string toString();
};

#endif //T2_JORZUL_1_ENGINE_H
