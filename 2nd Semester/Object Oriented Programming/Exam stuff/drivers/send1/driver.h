#pragma once
#include <string>


class Driver
{
private:
    std::string name;
    int lati;
    int longi;
    int score;

public:
    Driver();

    Driver(std::string, int, int, int);

    std::string get_name() const;

    int get_lati() const;

    int get_longi() const;

    int get_score() const;

    void set_score(int);
};
