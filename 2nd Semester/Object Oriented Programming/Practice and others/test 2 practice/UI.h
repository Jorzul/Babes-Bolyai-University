//
// Created by User on 5/10/2023.
//

#ifndef TEST_2_PRACTICE_UI_H
#define TEST_2_PRACTICE_UI_H

#pragma once
#include "Controller.h"

class UI
{
private:
    Controller applicationController;

public:
    UI(){};
    ~UI(){};
    void runApp();
    void addDepartment();
    void showAllDepartments();
    void showAllEfficientDeparments();
    void writeToFile();
};

#endif //TEST_2_PRACTICE_UI_H
