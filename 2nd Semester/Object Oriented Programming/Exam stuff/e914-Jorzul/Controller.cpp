//
// Created by User on 6/14/2023.
//

#include "Controller.h"

Controller::Controller(Repository &repository1): repository(repository1) {

}

vector<Volunteer> Controller::getAssignedVolunteers(string _department) {
    return repository.getAssignedVolunteers(_department);
}

vector<Department> Controller::getDepartments() {
    return repository.getDepartments();
}

vector<Volunteer> Controller::getAssignedVolunteersSorted(string _department) {
    vector<Volunteer> sorted = repository.getAssignedVolunteers(_department);

    sort(sorted.begin(), sorted.end(), [](Volunteer vol1, Volunteer vol2)
    {
        return vol1.getName() < vol2.getName();
    });

    return sorted;
}

void Controller::addVolunteer(string name, string email, string interests, string depart) {
    if (name == "" || email == "")
        throw exception();
    repository.addVolunteer(Volunteer{name, email, interests, depart});
}

Controller::~Controller() {

}
