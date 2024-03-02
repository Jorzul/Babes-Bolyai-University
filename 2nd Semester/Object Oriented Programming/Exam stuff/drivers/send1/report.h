#pragma once
#include <string>


class Report
{
private:
    std::string description;
    std::string reporter;
    int lati;
    int longi;
    bool valid_status;
    int nr_validations;

public:
    Report();

    Report(std::string, std::string, int, int, bool);

    std::string get_desc() const;

    std::string get_reporter() const;

    int get_lati() const;

    int get_longi() const;

    bool get_status() const;

    void set_status();

    int get_nr_validations() const;

    void set_nr_validations(int);
};
