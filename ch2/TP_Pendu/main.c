#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "initMotMystere.h"

int main(int argc, char const *argv[])
{
    printf("Bienvenue dans le Pendu !");

    char motMystere[5] = "ROUGE"; 
    int nombreCaractere = 0, i = 0, nombreDEssais = 10;

    nombreCaractere = strlen(motMystere); // pour obtenir la taille du mot mystere 
    char *motDecouvert = NULL;
    //motDecouvert = malloc(nombreCaractere * sizeof(char));
    for (int i = 0; i < nombreCaractere; i++)
    {
        motDecouvert[i]="*";
    }

    //char *pointeurMotDecouvert = &motDecouvert;

    //initMotMystere(motDecouvert, nombreCaratere);
    
    printf("%s\n", motDecouvert);
    

/*
    while( i < nombreDEssais )
    {
        char lettrePropose = NULL;
        printf("Il vous rester %d coups à jouer\n", nombreDEssais-i);
        printf("Quel est le mot secret ? %c\n", motDecouvert);
        printf("Proposez une lettre : ");
        scanf("%c", &lettrePropose);
    }
    
*/
    //free(motDecouvert);
    return 0;
}
