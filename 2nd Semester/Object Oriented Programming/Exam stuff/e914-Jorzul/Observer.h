//
// Created by User on 6/14/2023.
//

#ifndef E914_JORZUL_OBSERVER_H
#define E914_JORZUL_OBSERVER_H

class Observer{
public:
    Observer() = default;;
    virtual ~Observer() = default;;
    virtual void update() const = 0;
};

#endif //E914_JORZUL_OBSERVER_H
