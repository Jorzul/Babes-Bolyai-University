//
// Created by User on 5/11/2023.
//

#include "UI.h"

void UI::add_car()
{
    int numberOfDoors;
    string engineType;
    int autonomy = 0;

    cout << "Nr of doors: ";
    cin>>numberOfDoors;

    cout <<"Engine type: ";
    cin>>engineType;

    if (engineType == "Electric")
    {
        cout << "Autonomy: ";
        cin >> autonomy;
    }

    this->service.addCar(numberOfDoors, engineType, autonomy);
    cout << "The price of this car is " << this->service.get_last_added_car().computePrice() << '\n';
}

void UI::show_all_cars()
{

}

void UI::save_to_file_cars()
{

}

void UI::runApp()
{
    int option;
    while (true)
    {
        printf("What do you want to do?");
        printf("1. Add a car.");
        printf("2. Show all cars.");
        printf("3. Save to file.");
        printf("0. Exit");
        cin >> option;

        if (option == 1)
            add_car();
        if (option == 2)
            show_all_cars();
        if (option == 3)
            save_to_file_cars();
        if (option == 0)
            break;
    }
}
