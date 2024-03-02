//
// Created by User on 4/27/2023.
//

#include <cstring>
#include <cstdio>
#include "service.h"

void add_car_service(char name[], char model[], int year, char color[])
{
    if (add_car_to_repository(Create_Car(name, model, year, color), model, year) == 0)
        printf("Car already exists.");
    else
        printf("Car added successfully");
}

void delete_car_service(char name[], char model[])
{
    if (delete_car_from_repository(name, model) == 0)
        printf("Car does not exist.");
    else
        printf("Car deleted successfully");
}

void show_cars_service()
{
    int size;
    Car* all_cars;

    all_cars = get_all_cars(&size);

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (strcmp(all_cars[j].name, all_cars[j + 1].name) == 0 && strcmp(all_cars[j].model, all_cars[j+1].model) > 0)
            {
                Car temp = all_cars[j];
                all_cars[j] = all_cars[j + 1];
                all_cars[j + 1] = temp;
            } else if (strcmp(all_cars[j].name, all_cars[j+1].name) > 0)
            {
                Car temp = all_cars[j];
                all_cars[j] = all_cars[j + 1];
                all_cars[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
        toString(all_cars[i]);

}