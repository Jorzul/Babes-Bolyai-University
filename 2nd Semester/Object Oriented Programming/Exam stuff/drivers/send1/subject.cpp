#include "subject.h"
#include "observer.h"
#include <memory>


void Subject::add_observer(const std::shared_ptr<Observer> &obs)
{
    this->observers.emplace_back(obs);
}


void Subject::notify(const int reporter_idx)
{
    for (const auto &obs : this->observers)
    {
        obs->update(reporter_idx);
    }
}
