#include "repository.h"
#include "report.h"
#include <fstream>


Repository::Repository(std::string _drivers_filename, std::string _reports_filename)
    : drivers_filename{_drivers_filename}, reports_filename{_reports_filename}
{
    this->read_from_file();
}


void Repository::read_from_file()
{
    // read drivers
    std::ifstream fin(this->drivers_filename);
    int nr_drivers;
    fin >> nr_drivers;
    while (nr_drivers--)
    {
        std::string name;
        int lati, longi, score;
        fin >> name >> lati >> longi >> score;
        this->drivers.emplace_back(name, lati, longi, score);
    }
    fin.close();

    // read reports
    fin.open(this->reports_filename);
    int nr_reports;
    fin >> nr_reports;
    while (nr_reports--)
    {
        std::string desc, reporter, valid_status;
        int lati, longi;
        fin >> desc >> reporter >> lati >> longi >> valid_status;
        this->reports.emplace_back(desc, reporter, lati, longi, (valid_status == "false" ? 0 : 1));
    }
}


void Repository::save_to_file()
{
    std::ofstream fout(this->reports_filename);
    fout << this->reports.size() << "\n\n";
    for (auto &report : this->reports)
    {
        fout << report.get_desc() + "\n";
        fout << report.get_reporter() + "\n";
        fout << report.get_lati() << " " << report.get_longi() << "\n";
        fout << std::boolalpha << report.get_status() << "\n\n";
    }
}


void Repository::add_report(const std::string &desc, const std::string &reporter, const int lati, const int longi, const std::string &status)
{
    const Report report(desc, reporter, lati, longi, status == "true" ? 1 : 0);
    this->reports.emplace_back(report);
}


void Repository::add_chat_text(const std::string &text)
{
    this->chat_text.emplace_back(text);
}


std::vector<std::string>& Repository::get_chat_text()
{
    return this->chat_text;
}


std::vector<Driver>& Repository::get_drivers()
{
    return this->drivers;
}


std::vector<Report>& Repository::get_reports()
{
    return this->reports;
}
