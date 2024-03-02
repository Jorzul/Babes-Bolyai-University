//
// Created by User on 4/27/2023.
//

#include <cstdio>
#include <cstring>
#include "ui.h"

void input_5_initial_proteins()
{
    add_protein_service("Human", "Myosin-2", "MDSDSMFSFASNFA");
    add_protein_service("Human", "Keratin", "TGCDAFNFG");
    add_protein_service("Mouse", "Keratin", "MLWJFDSANFJJN");
    add_protein_service("E_Coli", "tufA", "JFSDGKSDFNGJ");
    add_protein_service("E_Coli", "cspE", "MSLDFKSADJMKDASFAJ");
}

void add_protein_ui()
{
    char organism[50];
    char name[50];
    char sequence[50];

    printf("Organism: ");
    fgets(organism, 50, stdin);
    organism[strcspn(organism, "\n")] = '\0';

    printf("Name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Associated sequence: ");
    fgets(sequence, 50, stdin);
    sequence[strcspn(sequence, "\n")] = '\0';

    add_protein_service(organism, name, sequence);
}

void show_protein_ui()
{
    show_proteins_service();
}

void show_protein_of_name_ui()
{
    char name[50];

    printf("Name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    if (strlen(name) == 0) {
        printf("No name specified.");
        return;
    }

    show_protein_of_name_service(name);
}

void print_options()
{
    printf("\n");
    printf("1. Add a protein.\n");
    printf("2. Show all proteins.\n");
    printf("3. Show all proteins of a given name.\n");
    printf("0. Exit.\n");
}

void run_menu()
{
    int command = 0;
    char term;

    input_5_initial_proteins();

    while (true)
    {
        print_options();
        printf(">");
        scanf("%d", &command);
        scanf("%c", &term);

        if (command == 1) {
            add_protein_ui();

        }else if (command == 2) {
            show_protein_ui();

        }else if (command == 3) {
            show_protein_of_name_ui();

        }else if (command == 0) {
            break;

        }else
            printf("Invalid command.");
    }
}