//
// Created by User on 6/14/2023.
//

#ifndef E914_JORZUL_VOLUNTEERS_H
#define E914_JORZUL_VOLUNTEERS_H

#include "Utils.h"

class Volunteer{
private:
    string name, email, list_of_interest, bel_department;

public:
    Volunteer();
    Volunteer(string name, string email, string list_of_interest, string bel_dep): name(name), email(email), list_of_interest(list_of_interest), bel_department(bel_dep) {}
    ~Volunteer();

public:
    string getName() const;
    void setName(string _name);

    string getEmail() const;
    void setEmail(string _email);

    string getList_of_interest() const;
    void setList_of_interest(string _interest);

    string getBel_department() const;
    void setBel_department(string _department);

    string toString();

    friend istream& operator>>(istream& stream, Volunteer& volunteer)
    {
        string input;
        getline(stream, input);
        vector<string> tokens = Utils::tokenize(input);
        if (tokens.size() != 4)
            return stream;

        volunteer.setName(tokens[0]);
        volunteer.setEmail(tokens[1]);
        volunteer.setList_of_interest(tokens[2]);
        volunteer.setBel_department(tokens[3]);

        return stream;
    }
};

#endif //E914_JORZUL_VOLUNTEERS_H
