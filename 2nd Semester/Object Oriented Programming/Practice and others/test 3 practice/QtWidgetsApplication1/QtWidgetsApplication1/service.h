#pragma once
//
// Created by User on 4/27/2023.
//

#include "domain.h"
#include "repository.h"

void add_car_service(char name[], char model[], int year, char color[]);

void show_cars_service();

void delete_car_service(char name[], char model[]);
