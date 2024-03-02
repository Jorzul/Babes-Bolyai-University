#include "driver.h"


Driver::Driver(std::string _name, int _lati, int _longi, int _score)
    : name{_name}, lati{_lati}, longi{_longi}, score{_score} {}


std::string Driver::get_name() const
{
    return this->name;
}


int Driver::get_lati() const
{
    return this->lati;
}


int Driver::get_longi() const
{
    return this->longi;
}


int Driver::get_score() const
{
    return this->score;
}


void Driver::set_score(int new_val)
{
    this->score = new_val;
}
