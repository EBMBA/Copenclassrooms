#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int somme(int tableau[], int tailleTableau){
    int resultat;

    for (size_t i = 0; i < tailleTableau; i++)
    {
        resultat += tableau[i];
    }

    return resultat;
    
}