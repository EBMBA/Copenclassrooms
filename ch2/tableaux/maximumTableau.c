#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void maximumTableau(int tableau[], int tailleTableau, int valeurMax){

    for (int i = 0; i < tailleTableau; i++)
    {
        if(tableau[i] > valeurMax){
            tableau[i] = 0;
        }
    }
    
}