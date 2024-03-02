//
// Created by User on 4/27/2023.
//

#include "domain.h"
#include <cstring>
#include <cstdio>

Protein create_protein(char organism[], char name[], char sequence[])
{
    Protein protein;
    strcpy(protein.organism, organism);
    strcpy(protein.name, name);
    strcpy(protein.sequence, sequence);

    return protein;
}

void toString(Protein p)
{
    printf("%s | %s | %s\n", p.organism, p.name, p.sequence);
}
