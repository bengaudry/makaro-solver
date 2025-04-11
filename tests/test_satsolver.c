#include "../3sat_solver.h"

int main(int argc, char** argv) {
    FNC fnc;

    fnc = read_fnc_from_dimacs_file(argv[1]);
    afficher_fnc(fnc);

    return 0;
}