#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void verifierLettre(const char *mot, char *motMystere, int tailleMot, char lettre, bool *lettreisIn, int *nbrEssai){
    for (size_t i = 0; i < tailleMot; i++)
        {
            if(mot[i] == lettre){
                printf("Bravo, la lettre %c est bien dans le mot\n", lettre);
                *lettreisIn = true;
                motMystere[i] = lettre;
            }
        }
    
        printf("Mot mystère : %s\n", motMystere);

        if(*lettreisIn == false){
            *nbrEssai = *nbrEssai + 1 ;
            int temp = *nbrEssai ;
            int nbrEssaiRestant = 10 - temp ;
            printf("Faux, la lettre %c n'est pas dans le mot.\nIl vous reste %d essai(s)\n", lettre, nbrEssaiRestant);

            if(temp == 10){
                printf("Vous avez perdu... Le mot etait %s\n", mot);
            }       
        }
}