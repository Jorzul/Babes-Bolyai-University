//
// Created by User on 6/14/2023.
//

#ifndef E914_JORZUL_DEPARTMENTS_H
#define E914_JORZUL_DEPARTMENTS_H

#include "Utils.h"

class Department{
private:
    string name, description;
public:
    Department();
    Department(string name, string description) : name(name), description(description){}
    ~Department();

public:
    string getName() const;
    void setName(string _name);

    string getDescription() const;
    void setDescription(string _description);

    friend istream &operator>>(istream& stream, Department& department) {
        string input;
        getline(stream, input);
        vector<string> tokens = Utils::tokenize(input);
        if (tokens.size() != 2)
            return stream;
        department.setName(tokens[0]);
        department.setDescription(tokens[1]);
        return stream;
    }

    string toString();
};

#endif //E914_JORZUL_DEPARTMENTS_H
