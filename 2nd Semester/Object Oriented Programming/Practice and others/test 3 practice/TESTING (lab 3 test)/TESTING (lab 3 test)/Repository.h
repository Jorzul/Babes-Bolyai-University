#pragma once
//
// Created by User on 4/27/2023.
//

#include "domain.h"

int add_protein_to_repository(Protein protein, char organism[], char name[]);

Protein* get_all_proteins(int* size);
