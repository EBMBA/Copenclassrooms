#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void affiche(int *tableau, int tailleTableau){

    for (int i = 0; i < tailleTableau; i++)
    {
        printf("%d\n", tableau[i]);
    }
    
}
