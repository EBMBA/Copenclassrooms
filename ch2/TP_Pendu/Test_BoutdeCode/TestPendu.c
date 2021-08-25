#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char lireCaractere() 
{ 
    char caractere = 0;
 
    caractere = getchar(); // On lit le premier caractère
    // changement de la lettre en sa majuscule (ASCII)
    if (caractere > 97)
    {
        caractere = caractere - 32;
    } 
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer) 
    while (getchar() != '\n') ;
 
    return caractere; // On retourne le premier caractère qu'on a lu 
}

void initMotMystere(char *motMystere, int tailleMot){
    for (size_t i = 0; i < tailleMot; i++)
    {   
        motMystere[i] = 42;
    }
    printf("Voici le mot à deviner : %s\nIl y a %d caracteres\n", motMystere, tailleMot);
}

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
        }
}

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