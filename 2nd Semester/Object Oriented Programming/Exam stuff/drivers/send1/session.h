#pragma once
#include "subject.h"
#include "repository.h"
#include <string>


class Session : public Subject
{
private:
    Repository &repo;

public:
    Session(Repository&);

    void add(const std::string &desc, const std::string &reporter, const int lati, const int longi, const std::string &status);

    void validate(const int report_idx, const int reporter_idx);

    void send(const std::string &new_text);
};
