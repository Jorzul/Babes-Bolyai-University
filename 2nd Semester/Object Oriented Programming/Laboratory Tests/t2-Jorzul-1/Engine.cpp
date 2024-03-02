//
// Created by User on 5/11/2023.
//

#include "Engine.h"

string Engine::toString() {
    string EngineString = "";
    return EngineString;
}

double ElectricEngine::getPrice() {
    return this->basePrice + autonomy * 0.01;
}

string ElectricEngine::toString() {
    string ElectricString = "Engine: Electric | Autonomy: " + to_string(autonomy);
    return ElectricString;
}

double TurboEngine::getPrice() {
    return this->basePrice + 100;
}

string TurboEngine::toString() {
    string TurboString = "Engine: Turbo | ";
    return TurboString;
}