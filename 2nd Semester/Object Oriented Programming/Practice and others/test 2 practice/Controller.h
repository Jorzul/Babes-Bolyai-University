//
// Created by User on 5/10/2023.
//

#ifndef TEST_2_PRACTICE_CONTROLLER_H
#define TEST_2_PRACTICE_CONTROLLER_H

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Departments.h"
using namespace std;

class Controller
{
private:
    vector<HospitalDepartment *> departments;

public:
    Controller()
    {
        HospitalDepartment *neonantalUnitSanovil = new NeonantalUnit("neon unit", 70, 9);
        HospitalDepartment *neonantalUnitReginaMaria = new NeonantalUnit("Regina Maria", 25, 7);

        HospitalDepartment *surgeryUnitSanovil = new Surgery("suji", 30, 60);
        HospitalDepartment *surgeryUnitReginaMaria = new Surgery("ramona", 10, 10);

        departments.push_back(neonantalUnitSanovil);
        departments.push_back(neonantalUnitReginaMaria);
        departments.push_back(surgeryUnitSanovil);
        departments.push_back(surgeryUnitReginaMaria);
    };
    ~Controller()
    {
        for (auto department : departments)
            delete department;
    };
    static inline bool comparisonFunction(HospitalDepartment *department1, HospitalDepartment *department2);
    void addDepartments(HospitalDepartment *department);
    std::vector<HospitalDepartment *> getAllDepartments();
    std::vector<HospitalDepartment *> getAllEficientDepartments();
    void writeToFile();
};

#endif //TEST_2_PRACTICE_CONTROLLER_H
