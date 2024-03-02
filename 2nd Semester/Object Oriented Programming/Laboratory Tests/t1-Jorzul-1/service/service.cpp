//
// Created by User on 4/27/2023.
//

#include <cstdio>
#include <cstring>
#include "service.h"

void add_protein_service(char organism[], char name[], char sequence[])
/*
 * This function is used for adding a new protein to the repository. But this is the service function which calls for
 * the repository function.
 *
 * parameters: organism : The name of the organism
 *              name : The name of the protein
 *              sequence : The associated sequence of the protein
 *
 */
{
    if (add_protein_to_repository(create_protein(organism, name, sequence), organism, name) == 0)
        printf("Protein already exists.\n");
    else
        printf("Protein added successfully.\n");
}

void show_proteins_service()
{
    int size;
    Protein* all_proteins;

    all_proteins = get_all_proteins(&size);

    for (int i = 0; i < size; i++)
        toString(all_proteins[i]);
}

void show_protein_of_name_service(char name[])
/*
 * This function retrieves all proteins with a given name, sorted by organisms. If the protein does not exist in the repository, a message is
 * printed.
 *
 * parameters: name: The name of the protein.
 */
{
    int size, count = 0;
    Protein* all_proteins;
    bool valid = false;

    all_proteins = get_all_proteins(&size);

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(all_proteins[j].organism, all_proteins[j + 1].organism) > 0) {
                Protein temp = all_proteins[j];
                all_proteins[j] = all_proteins[j + 1];
                all_proteins[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (strcmp(all_proteins[i].name, name) == 0) {
            toString(all_proteins[i]);
            count++;
            valid = true;
        }
    }

    if (valid)
        printf("There are %d organisms having such protein.\n", count);
    else
        printf("No protein with such name.\n");
}
