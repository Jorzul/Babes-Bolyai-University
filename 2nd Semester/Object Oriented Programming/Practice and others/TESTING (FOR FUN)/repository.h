//
// Created by User on 4/27/2023.
//

#ifndef TESTING_FOR_FUN_REPOSITORY_H
#define TESTING_FOR_FUN_REPOSITORY_H

#include "domain.h"

int add_car_to_repository(Car car, char model[], int year);

Car* get_all_cars(int *size);

int delete_car_from_repository(char name[], char model[]);

#endif //TESTING_FOR_FUN_REPOSITORY_H
