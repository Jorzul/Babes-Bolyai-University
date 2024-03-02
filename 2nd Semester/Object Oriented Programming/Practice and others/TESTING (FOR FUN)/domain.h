//
// Created by User on 4/27/2023.
//

#ifndef TESTING_FOR_FUN_DOMAIN_H
#define TESTING_FOR_FUN_DOMAIN_H

typedef struct{
    char name[50];
    char model[50];
    int year;
    char color[50];
} Car;

Car Create_Car(char name[], char model[], int year, char color[]);

void toString(Car c);

#endif //TESTING_FOR_FUN_DOMAIN_H
