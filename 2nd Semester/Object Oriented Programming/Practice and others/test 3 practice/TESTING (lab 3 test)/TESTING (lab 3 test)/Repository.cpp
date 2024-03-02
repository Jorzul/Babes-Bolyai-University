//
// Created by User on 4/27/2023.
//

#include <cstdlib>
#include <cstring>
#include "Repository.h"

Protein* proteinList;
static int _capacity = 0;
static int _size = 0;

int add_protein_to_repository(Protein protein, char organism[], char name[])
/*
 * This function adds a protein to the repository. If the protein is already in the repository, we return 0, otherwise 1
 *
 * parameters: protein : The protein we want to add
 *              organism : The name of the organism
 *              name : The name of the protein
 *
 * return: 0 if the protein is already part of the repository
 *          1 if the protein was added successfully
 */
{
    if (_size + 1 > _capacity) {
        if (_capacity > 0)
            _capacity *= 2;
        else
            _capacity++;

        Protein* new_proteinList = (Protein*)malloc(_capacity * sizeof(Protein));

        for (int i = 0; i < _size; i++)
            new_proteinList[i] = proteinList[i];

        free(proteinList);

        proteinList = new_proteinList;
    }

    for (int i = 0; i < _size; i++)
        if (strcmp(proteinList[i].organism, organism) == 0 && strcmp(proteinList[i].name, name) == 0)
            return 0;

    proteinList[_size++] = protein;
    return 1;
}

Protein* get_all_proteins(int* size)
{
    Protein* all_proteins;
    *size = _size;

    all_proteins = (Protein*)malloc(_capacity * sizeof(Protein));

    for (int i = 0; i < _size; i++)
        all_proteins[i] = proteinList[i];

    return all_proteins;
}
