#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "affiche.h"
#include "somme.h"
#include "moyenne.h"
#include "copie.h"
#include "maximumTableau.h"
#include "ordonnerTableau.h"

int main(int argc, char *argv[]){

    int tableau[4] = {15, 81, 22, 13};
    int tableauCopie[4] = {0};

    // On affiche le contenu du tableau

    //affiche(tableau,4);
    //printf("%d\n", somme(tableau,4));
    //printf("%f\n", moyenne(tableau,4));
    copie(tableau, tableauCopie, 4);
    //affiche(tableauCopie, 4);
    //maximumTableau(tableauCopie,4,2);
    ordonnerTableau(tableauCopie,4);
    affiche(tableauCopie,4);

    return 0;

}