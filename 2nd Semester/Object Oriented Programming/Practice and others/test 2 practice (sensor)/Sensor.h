//
// Created by User on 5/11/2023.
//

#ifndef TEST_2_PRACTICE_SENSOR_SENSOR_H
#define TEST_2_PRACTICE_SENSOR_SENSOR_H

#include <iostream>
#include <vector>
using namespace std;

class Sensor
{
protected:
    string producer;
    vector<double> recordings;

public:
    Sensor(string producer) : producer(producer) {};
    virtual ~Sensor() {};

    virtual bool sendAlert() { return true; };
    virtual double getPrice() { return 0; };
    virtual string toString();
};

class TemperatureSensor : public Sensor
{
private:
    double diameter;
    double length;

public:
    TemperatureSensor(string producer, double diameter, double length) : Sensor(producer), diameter(diameter), length(length) {};

    bool sendAlert();
    double getPrice();
    string toString();
};

class HumiditySensor : public Sensor
{
public:
    HumiditySensor(string producer) : Sensor(producer) {};

    bool sendAlert();
    double getPrice();
    string toString();
};

class SmokeSensor : public Sensor
{
public:
    SmokeSensor(string producer) : Sensor(producer) {};

    bool sendAlert();
    double getPrice();
    string toString();
};

#endif //TEST_2_PRACTICE_SENSOR_SENSOR_H
