//
// Created by User on 5/4/2023.
//

#ifndef A6_JORZUL_1_REPOSITORY_H
#define A6_JORZUL_1_REPOSITORY_H

#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "../Domain/Movie.h"
#include <iostream>
#include <vector>
using namespace std;

typedef Movie TElem;

class Repository {
private:
    vector<TElem> entities;

public:
    ~Repository();

    void add_entity(const TElem& entity);

    void delete_entity_at(int index);

    void update_entity_at(int index, const TElem& newEntity);

    TElem* get_all_entities();

    int get_size();

    vector<TElem> get_all_entities_STL();
};

#endif


#endif //A6_JORZUL_1_REPOSITORY_H
