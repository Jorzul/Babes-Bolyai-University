#pragma once
#include <vector>
#include "observer.h"
#include <memory>


class Subject
{
private:
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void add_observer(const std::shared_ptr<Observer> &obs);

    void notify(const int);
};
