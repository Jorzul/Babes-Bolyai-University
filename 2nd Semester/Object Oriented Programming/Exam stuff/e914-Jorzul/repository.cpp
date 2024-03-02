//
// Created by User on 6/14/2023.
//

#include "repository.h"

void Repository::loadVolunteers() {
    ifstream input("../volunteers.txt");
    Volunteer volunteer{};

    while (input >> volunteer)
        volunteers.push_back(volunteer);
    input.close();
}

void Repository::loadDepartments() {
    ifstream input("../departments.txt");
    Department department{};

    while (input >> department)
        departments.push_back(department);

    input.close();
}

Repository::Repository(bool load) {
    if (load)
    {
        loadVolunteers();
        loadDepartments();
    }
}

vector<Department> &Repository::getDepartments() {
    return departments;
}

vector<Volunteer> Repository::getAssignedVolunteers(string _department) {
    vector<Volunteer> Volunteer_list;
    for (auto &v : volunteers)
        if (v.getBel_department() == _department)
            Volunteer_list.push_back(v);
    return Volunteer_list;
}

vector<Volunteer> Repository::getUnassignedVolunteers() {
    vector<Volunteer> Volunteer_list;
    for (auto &v : volunteers)
        if (v.getBel_department() == "")
            Volunteer_list.push_back(v);
    return Volunteer_list;
}

void Repository::addVolunteer(Volunteer volunteer) {
    if (volunteer.getEmail() == "" || volunteer.getName() == "")
        throw exception();
    volunteers.push_back(volunteer);
}

Repository::~Repository() {

}


