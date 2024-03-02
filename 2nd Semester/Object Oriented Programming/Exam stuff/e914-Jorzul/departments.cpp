//
// Created by User on 6/14/2023.
//

#include "departments.h"

Department::Department() {

}

Department::~Department() {

}

string Department::getName() const {
    return name;
}

void Department::setName(string _name) {
    this->name = _name;
}

string Department::getDescription() const {
    return description;
}

void Department::setDescription(string _description) {
    this->description = _description;
}

string Department::toString() {
    return name + " | " + description + "\n";
}
