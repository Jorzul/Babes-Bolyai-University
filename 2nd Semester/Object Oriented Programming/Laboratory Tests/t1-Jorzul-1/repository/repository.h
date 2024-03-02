//
// Created by User on 4/27/2023.
//

#ifndef T1_JORZUL_1_REPOSITORY_H
#define T1_JORZUL_1_REPOSITORY_H

#include "../domain/domain.h"

int add_protein_to_repository(Protein protein, char organism[], char name[]);

Protein* get_all_proteins(int* size);

#endif //T1_JORZUL_1_REPOSITORY_H
