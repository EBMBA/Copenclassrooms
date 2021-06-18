#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "affiche.h"
#include "somme.h"

int main(int argc, char *argv[]){

    int tableau[4] = {10, 15, 3};

    // On affiche le contenu du tableau

    affiche(tableau,4);
    printf("%d\n", somme(tableau,4));

    return 0;

}