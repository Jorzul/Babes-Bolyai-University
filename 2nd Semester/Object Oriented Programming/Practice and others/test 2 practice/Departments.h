//
// Created by User on 5/10/2023.
//

#ifndef TEST_2_PRACTICE_DEPARTMENTS_H
#define TEST_2_PRACTICE_DEPARTMENTS_H

#pragma once
#include <iostream>

class HospitalDepartment
{
protected:
    std::string hospitalName;
    int numberOfDoctors;

public:
    HospitalDepartment() : hospitalName{""}, numberOfDoctors{0} {};
    HospitalDepartment(std::string hospitalName, int numberOfDoctors) : hospitalName{hospitalName}, numberOfDoctors{numberOfDoctors} {};
    virtual ~HospitalDepartment(){};
    virtual bool isEficient() { return false; };
    virtual std::string toString();
    std::string getName() { return this->hospitalName; };
};

class NeonantalUnit : public HospitalDepartment
{
private:
    double averageGrade;

public:
    NeonantalUnit(std::string hospitalName, int numberOfDoctors, double averageGrade) : HospitalDepartment{hospitalName, numberOfDoctors}, averageGrade{averageGrade} {};
    bool isEficient();
    std::string toString();
};

class Surgery : public HospitalDepartment
{
private:
    int numberOfPacients;

public:
    Surgery(std::string hospitalName, int numberOfDoctors, int numberOfPacients) : HospitalDepartment{hospitalName, numberOfDoctors}, numberOfPacients{numberOfPacients} {};
    bool isEficient();
    std::string toString();
};

#endif //TEST_2_PRACTICE_DEPARTMENTS_H
