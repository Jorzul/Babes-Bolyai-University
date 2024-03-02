//
// Created by User on 4/27/2023.
//

#pragma once

#include "domain.h"

int add_car_to_repository(Car car, char model[], int year);

Car* get_all_cars(int* size);

int delete_car_from_repository(char name[], char model[]);
