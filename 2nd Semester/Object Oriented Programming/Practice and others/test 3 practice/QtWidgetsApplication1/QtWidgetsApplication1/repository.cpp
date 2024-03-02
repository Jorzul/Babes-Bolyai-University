//
// Created by User on 4/27/2023.
//

#include <cstdlib>
#include <cstring>
#include "repository.h"

Car* carList;
static int _capacity = 0;
static int _size = 0;

int add_car_to_repository(Car car, char model[], int year)
{
    if (_size + 1 > _capacity)
    {
        if (_capacity > 0)
            _capacity *= 2;
        else
            _capacity++;

        Car* new_carList = (Car*)malloc(_capacity * sizeof(Car));

        for (int i = 0; i < _size; i++)
            new_carList[i] = carList[i];

        free(carList);

        carList = new_carList;
    }

    for (int i = 0; i <= _size; i++)
    {
        if (strcmp(carList[i].model, model) == 0 && carList[i].year == year)
            return 0;
    }

    carList[_size++] = car;
    return 1;
}

int delete_car_from_repository(char name[], char model[])
{
    int target_index = -1;

    for (int i = 0; i < _size; i++)
        if (strcmp(name, carList[i].name) == 0 && strcmp(model, carList[i].model) == 0)
        {
            target_index = i;
            break;
        }

    if (target_index == -1)
        return 0;

    for (int i = target_index; i < _size; i++)
        carList[i] = carList[i + 1];

    _size--;
    return 1;
}

Car* get_all_cars(int* size)
{
    Car* allCars;
    *size = _size;

    allCars = (Car*)malloc(_capacity * sizeof(Car));

    for (int i = 0; i < _size; i++)
        allCars[i] = carList[i];

    return allCars;
}
