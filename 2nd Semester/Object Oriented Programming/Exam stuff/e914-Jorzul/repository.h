//
// Created by User on 6/14/2023.
//

#ifndef E914_JORZUL_REPOSITORY_H
#define E914_JORZUL_REPOSITORY_H

#include "departments.h"
#include "volunteers.h"

class Repository{
private:
    vector<Department> departments;
    vector<Volunteer> volunteers;
    void loadVolunteers();
    void loadDepartments();

public:
    Repository(bool load);
    vector<Volunteer> getAssignedVolunteers(string _department);
    vector<Volunteer> getUnassignedVolunteers();
    vector<Department>& getDepartments();

    void addVolunteer(Volunteer volunteer);

    ~Repository();
};

#endif //E914_JORZUL_REPOSITORY_H
