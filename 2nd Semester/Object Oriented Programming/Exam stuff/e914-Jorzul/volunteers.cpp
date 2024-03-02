//
// Created by User on 6/14/2023.
//

#include "volunteers.h"

Volunteer::Volunteer() {

}

Volunteer::~Volunteer() {

}

string Volunteer::getName() const {
    return name;
}

void Volunteer::setName(string _name) {
    this->name = _name;
}

string Volunteer::getEmail() const {
    return email;
}

void Volunteer::setEmail(string _email) {
    this->email = _email;
}

string Volunteer::getList_of_interest() const {
    return list_of_interest;
}

void Volunteer::setList_of_interest(string _interest) {
    this->list_of_interest = _interest;
}

string Volunteer::getBel_department() const {
    return bel_department;
}

void Volunteer::setBel_department(string _department) {
    this->bel_department = _department;
}

string Volunteer::toString() {
    return name + " | " + email + " | " + list_of_interest + " | " + bel_department + "\n";
}
