#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double moyenne(int *tableau, int tailleTableau){
    double resultat; 

    for (int i = 0; i < tailleTableau; i++)
    {   
        resultat += tableau[i];
    }

    resultat /= tailleTableau;

    return resultat ;
    
}