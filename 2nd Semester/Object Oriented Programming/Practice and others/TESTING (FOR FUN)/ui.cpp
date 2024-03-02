//
// Created by User on 4/27/2023.
//

#include <cstdio>
#include <cstring>
#include "ui.h"

void add_car_ui()
{
    char name[50];
    char model[50];
    int year;
    char color[50];

    printf("Name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Model: ");
    fgets(model, 50, stdin);
    model[strcspn(model, "\n")] = '\0';

    printf("Color: ");
    fgets(color, 50, stdin);
    color[strcspn(color, "\n")] = '\0';

    printf("Year: ");
    scanf("%d", &year);

    add_car_service(name, model, year, color);
}

void show_cars_ui()
{
    show_cars_service();
}

void delete_car_ui()
{
    char name[50];
    char model[50];

    printf("Name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("model: ");
    fgets(model, 50, stdin);
    model[strcspn(model, "\n")] = '\0';

    delete_car_service(name, model);
}

void show_options()
{
    printf("\n");
    printf("1. Add a car\n");
    printf("2. Show cars\n");
    printf("3. Delete car\n");
    printf("0. Exit\n");
}

void ui_run()
{
    int choice = 0;
    char term;

    while (true)
    {
        show_options();

        printf(">");
        scanf("%d", &choice);
        scanf("%c", &term);

        if (choice == 1) {
            add_car_ui();

        }else if (choice == 2) {
            show_cars_ui();

        }else if (choice == 3) {
            delete_car_ui();

        }else if (choice == 0) {
            printf("Program done\n");
            break;

        }else {
            printf ("Invalid option\n");
        }
    }
}
