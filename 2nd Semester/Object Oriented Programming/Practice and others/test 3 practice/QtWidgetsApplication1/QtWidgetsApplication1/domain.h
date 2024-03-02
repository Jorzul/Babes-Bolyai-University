#pragma once
//
// Created by User on 4/27/2023.
//

typedef struct {
    char name[50];
    char model[50];
    int year;
    char color[50];
} Car;

Car Create_Car(char name[], char model[], int year, char color[]);

void toString(Car c);

char* get_name(Car c);

char* get_model(Car c);