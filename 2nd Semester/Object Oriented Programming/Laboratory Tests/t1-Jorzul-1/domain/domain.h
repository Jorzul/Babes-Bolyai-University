//
// Created by User on 4/27/2023.
//

#ifndef T1_JORZUL_1_DOMAIN_H
#define T1_JORZUL_1_DOMAIN_H

typedef struct {
    char organism[50];
    char name[50];
    char sequence[50];
} Protein;

Protein create_protein(char organism[], char name[], char sequence[]);

void toString(Protein p);

#endif //T1_JORZUL_1_DOMAIN_H
