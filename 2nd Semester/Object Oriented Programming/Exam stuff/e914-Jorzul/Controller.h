//
// Created by User on 6/14/2023.
//

#ifndef E914_JORZUL_CONTROLLER_H
#define E914_JORZUL_CONTROLLER_H

#include "repository.h"

class Controller{
private:
    Repository &repository;

public:
    Controller(Repository &repository1);
    vector<Volunteer> getAssignedVolunteers(string _department);
    vector<Department> getDepartments();
    vector<Volunteer> getAssignedVolunteersSorted(string _department);

    void addVolunteer(string name, string email, string interests, string depart);

    ~Controller();
};

#endif //E914_JORZUL_CONTROLLER_H
