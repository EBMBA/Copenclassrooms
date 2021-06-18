#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau){

    for (int i = 0; i < tailleTableau; i++)
    {
        tableauCopie[i] = tableauOriginal[i];
    }
    
}