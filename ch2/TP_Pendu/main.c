#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Headers/initMotMystere.h"
#include "Headers/lireCaractere.h"
#include "Headers/verifierLettre.h"

int main(int argc, char const *argv[])
{
    char mot[] = "ROOGE";
    char lettre = 0;
    bool lettreisIn = false;
    char motMystere[100], *checkLettre = NULL; 
    size_t tailleMot = strlen(mot);
    int nbrEssai = 0;
    char symbole = 42;

    // Init mot mystere
    initMotMystere(motMystere, tailleMot);


    while (nbrEssai < 10)
    {   
        lettreisIn = false;
        // Demande lettre 
        printf("Entrez une lettre :\n");
        lettre = lireCaractere();

        // Verification que la lettre n'a pas deja ete tape 
        checkLettre = strchr(motMystere, lettre);
        if (checkLettre == NULL)
        {
            verifierLettre(mot, motMystere, tailleMot, lettre, &lettreisIn, &nbrEssai);
        }
        
        else{
            printf("La lettre %c est déjà trouvée\n", lettre);
        }

        if (strcmp(motMystere, mot) == 0)
        {
            int nbrEssaiReussi = nbrEssai + tailleMot;  
            printf("Bravo vous avez trouvé en %d essais\n", nbrEssaiReussi);
            break; 
        }
        
    }
    
    return 0;
}