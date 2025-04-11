#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "3sat_solver.h"

FNC read_fnc_from_dimacs_file(char* file_path) {
    FNC fnc;
    FILE* fnc_file;
    unsigned int nb_var, nb_clauses;

    fnc_file = fopen(file_path, "r");

    // Récupération en-tête
    if (!fscanf(fnc_file, "p cnf %d %d\n", &nb_var, &nb_clauses)) {
        fprintf(stderr, "En-tête malformée\n");
        exit(1);
    }

    fnc.nb_clauses = nb_clauses;
    fnc.nb_var = nb_var;

    // Récupération de chaque clause
    for (int idx_cl = 0; idx_cl < nb_clauses; idx_cl++) {
        if (!fscanf(fnc_file, "%d %d %d 0\n", &fnc.clauses[idx_cl].tab[0], &fnc.clauses[idx_cl].tab[1], &fnc.clauses[idx_cl].tab[2])) {
            printf("Clause %d malformée\n", idx_cl);
            exit(1);
        }
    }

    fclose(fnc_file);
    return fnc;
}

void afficher_fnc(FNC fnc) {
    printf("p cnf %d %d\n", fnc.nb_var, fnc.nb_clauses);

    for (int idx_cl = 0; idx_cl < fnc.nb_clauses; idx_cl++) {
        printf("%d %d %d 0\n", fnc.clauses[idx_cl].tab[0], fnc.clauses[idx_cl].tab[1], fnc.clauses[idx_cl].tab[2]);
    }
}

void solve_fnc(char* out_file_path) {
    FILE* out_file;

    out_file = fopen(out_file_path, "w");

    // Logique du sat solver
    // Choisir une assignation v uniformément au hasard

    fclose(out_file);
}
