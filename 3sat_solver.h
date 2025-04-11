#ifndef _3SAT_SOLVER_H_
#define _3SAT_SOLVER_H_

#define MAX_CLAUSES 1000

typedef int Var;
typedef struct {
    Var tab[3];
} Clause;
typedef struct {
    unsigned int nb_var;
    unsigned int nb_clauses;
    Clause clauses[MAX_CLAUSES];
} FNC;

FNC read_fnc_from_dimacs_file(char* file_path);

void afficher_fnc(FNC fnc);

#endif
