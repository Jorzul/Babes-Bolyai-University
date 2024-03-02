//
// Created by User on 4/27/2023.
//

#include "domain.h"
#include <cstdio>
#include <cstring>

Car Create_Car(char name[], char model[], int year, char color[])
{
    Car car;
    strcpy(car.name, name);
    strcpy(car.model, model);
    car.year = year;
    strcpy(car.color, color);

    return car;
}

void toString(Car c)
{
    printf("%s | %s | %d | %s\n", c.name, c.model, c.year, c.color);
}

char* get_name(Car c)
{
    return c.name;
}

char* get_model(Car c)
{
    return c.model;
}