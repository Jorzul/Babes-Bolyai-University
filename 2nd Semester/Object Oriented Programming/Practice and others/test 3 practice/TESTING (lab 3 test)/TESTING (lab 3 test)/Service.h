#pragma once
//
// Created by User on 4/27/2023.
//

#include "domain.h"
#include "Repository.h"

void add_protein_service(char organism[], char name[], char sequence[]);

void show_proteins_service();

void show_protein_of_name_service(char name[]);
