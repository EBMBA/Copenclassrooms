#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "affiche.h"

int positionMaximum(int *tableau, int tailleTableau){
    int index = 0;
    for (int i = 0; i <= tailleTableau; i++)
    {
        if(tableau[index] < tableau[i]){
            index = i;
        }
    }
    
    return index;
}

void ordonnerTableau(int tableau[], int tailleTableau){
    
    for (int t = tailleTableau-1 ; t != 0; t--)
    {
       int temp = tableau[t] ;

       int indexMax = positionMaximum(tableau,t);

        tableau[t] = tableau[indexMax] ;

        tableau[indexMax] = temp ;
    }

}