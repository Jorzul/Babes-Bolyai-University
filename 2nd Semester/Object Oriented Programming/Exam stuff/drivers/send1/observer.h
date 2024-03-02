#pragma once


class Observer
{
public:
    virtual void update(const int reporter_idx) = 0;

    virtual ~Observer() = default;
};
