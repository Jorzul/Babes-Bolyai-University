//
// Created by User on 4/27/2023.
//

#ifndef T1_JORZUL_1_SERVICE_H
#define T1_JORZUL_1_SERVICE_H

#include "../domain/domain.h"
#include "../repository/repository.h"

void add_protein_service(char organism[], char name[], char sequence[]);

void show_proteins_service();

void show_protein_of_name_service(char name[]);

#endif //T1_JORZUL_1_SERVICE_H
