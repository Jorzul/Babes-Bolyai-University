//
// Created by User on 5/11/2023.
//

#include "Sensor.h"

string Sensor::toString() {
    string sensorString = "Producer: " + producer + " | Recordings: ";
    for (auto recording: recordings)
    {
        sensorString += to_string(recording);
        sensorString += " ";
    }
    sensorString += "\n";
    return sensorString;
}

string TemperatureSensor::toString() {

}

bool TemperatureSensor::sendAlert() {
    int count = 0;

}

double TemperatureSensor::getPrice() {
    if (this->diameter < 3 && this->length < 50)
        return 17;
    return 9;
}