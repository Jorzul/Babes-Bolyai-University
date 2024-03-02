//
// Created by User on 5/10/2023.
//

#include "Departments.h"
std::string HospitalDepartment::toString()
{
    std::string stringHospital = "Name: " + hospitalName + " | Number Of Doctors: " + std::to_string(numberOfDoctors);
    return stringHospital;
}

bool NeonantalUnit::isEficient()
{
    return averageGrade > 8.5;
}

std::string NeonantalUnit::toString()
{
    return "Type: Neonatal Unit | " + HospitalDepartment::toString() + " | Average Grade: " + std::to_string(averageGrade) + "\n";
}

bool Surgery::isEficient()
{
    double result = double(numberOfPacients) / double(numberOfDoctors);
    return result >= 2;
}

std::string Surgery::toString()
{
    return "Type: Surgery Unit | " + HospitalDepartment::toString() + " | Number of Pacients: " + std::to_string(numberOfPacients) + '\n';
}