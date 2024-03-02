#pragma once
//
// Created by User on 4/27/2023.
//

typedef struct {
    char organism[50];
    char name[50];
    char sequence[50];
} Protein;

Protein create_protein(char organism[], char name[], char sequence[]);

void toString(Protein p);
