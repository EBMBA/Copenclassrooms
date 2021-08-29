#ifdef _WIN32
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "Headers/initMotMystere.h"
#include "Headers/lireCaractere.h"
#include "Headers/verifierLettre.h"
#include <Windows.h>
#define TAILLE_MAX 1000 // Tableau de taille 1000
#endif

#ifdef linux
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "Headers/initMotMystere.h"
#include "Headers/lireCaractere.h"
#include "Headers/verifierLettre.h"
#include  <unistd.h>
#define TAILLE_MAX 1000 // Tableau de taille 1000
#endif 

int main(int argc, char const *argv[])
{
    char lettre = 0;
    bool lettreisIn = false;
    char motMystere[100] = "", *checkLettre = NULL; 
    int nbrEssai = 0;
    char symbole = 42;
    FILE* fichier=NULL;
    char motsFichier[TAILLE_MAX]="";
    int nombreMots = 0;

    // Ouvrir le fichier
    fichier = fopen("Dictionnaire/dictionnaire.dico", "r");
    
    // Ligne du fichier
    int ligneActuel = 0;

    // Message de bienvenue
    printf("#############################\n");
    printf("Bienvenue dans le Pendu !\n");
    printf("#############################\n\n");

    printf("Voici les mots disponibles : \n");
    // Verification avant lecture dans le fichiers 
    if (fichier != NULL )
    {
        while (fgets(motsFichier, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            
            printf("%d. %s",ligneActuel ,motsFichier); // On affiche la chaîne qu'on vient de lire
            nombreMots ++, ligneActuel++;
        } 

        // Remet le curseur au debut du fichier
        rewind(fichier);

        //printf("%d\n", nombreMots);
        printf("\nChoisir un mot a faire deviner en ecrivant son numero :\n");
        scanf("%d", &ligneActuel);
        int ligneTemp = -1, caractereActuel = 0;

        do
        {
            fgets(motsFichier, TAILLE_MAX, fichier);

            ligneTemp++;
            
        } while (ligneTemp != ligneActuel);
        
        printf("Mot choisi :%d. %s \n",ligneTemp ,motsFichier);
        printf("Merci de patienter");
        sleep(3);
        

        for (size_t i = 0; i < 100; i++)
        {
            printf("\n");
        }
        
        size_t tailleMot = strlen(motsFichier);

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
                verifierLettre(motsFichier, motMystere, tailleMot, lettre, &lettreisIn, &nbrEssai);
            }
            
            else{
                printf("La lettre %c est déjà trouvée\n", lettre);
            }

            if (strcmp(motMystere, motsFichier) == 0)
            {
                int nbrEssaiReussi = nbrEssai + tailleMot;  
                printf("Bravo vous avez trouvé en %d essais\n", nbrEssaiReussi);
                break; 
            }
            
        }

        fclose(fichier);// On ferme le fichier qui a été ouvert
        
    }
    else{

        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier des mots disponibles");
    }
    
    return 0;
}