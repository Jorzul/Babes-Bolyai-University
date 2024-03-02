#include "session.h"
#include "repository.h"
#include <QString>
#include <iostream>
#include <string>


Session::Session(Repository &_repo) : repo{_repo} {}


void Session::add(const std::string &desc, const std::string &reporter, const int lati, const int longi, const std::string &status)
{
    this->repo.add_report(desc, reporter, lati, longi, status);
    this->notify(-1);
}


void Session::validate(const int report_idx, const int reporter_idx)
{
    auto &reports = this->repo.get_reports();
    reports[report_idx].set_nr_validations(reports[report_idx].get_nr_validations() + 1);
    if (reports[report_idx].get_nr_validations() == 2)
    {
        reports[report_idx].set_status();
        auto &drivers = this->repo.get_drivers();
        drivers[reporter_idx].set_score(drivers[reporter_idx].get_score() + 1);
    }
    this->notify(reporter_idx);
}


void Session::send(const std::string &new_text)
{
    this->repo.add_chat_text(new_text);
    this->notify(-1);
}
