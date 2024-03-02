#pragma once
#include <vector>
#include <string>
#include "driver.h"
#include "report.h"


class Repository
{
private:
    std::string drivers_filename;
    std::string reports_filename;
    std::vector<Driver> drivers;
    std::vector<Report> reports;
    std::vector<std::string> chat_text;

public:
    Repository();

    Repository(std::string, std::string);

    void read_from_file();

    void save_to_file();

    void add_report(const std::string &desc, const std::string &reporter, const int lati, const int longi, const std::string &status);

    void add_chat_text(const std::string &text);

    std::vector<std::string> &get_chat_text();

    std::vector<Driver> &get_drivers();

    std::vector<Report> &get_reports();
};
