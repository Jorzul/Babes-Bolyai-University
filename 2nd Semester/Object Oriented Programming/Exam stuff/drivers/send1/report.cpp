#include "report.h"


Report::Report(std::string _desc, std::string _reporter, int _lati, int _longi, bool _valid_status)
    : description{_desc}, reporter{_reporter}, lati{_lati}, longi{_longi}, valid_status{_valid_status}
{
    this->nr_validations = 0;
}


std::string Report::get_desc() const
{
    return this->description;
}


std::string Report::get_reporter() const
{
    return this->reporter;
}


int Report::get_lati() const
{
    return this->lati;
}


int Report::get_longi() const
{
    return this->longi;
}


bool Report::get_status() const
{
    return this->valid_status;
}


void Report::set_status()
{
    this->valid_status = true;
}


int Report::get_nr_validations() const
{
    return this->nr_validations;
}


void Report::set_nr_validations(int new_val)
{
    this->nr_validations = new_val;
}
