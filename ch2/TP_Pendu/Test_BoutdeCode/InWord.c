#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char mot[] = "ROUGE";
    char lettre = 0, *lettreisIn =NULL;
    int nbrEssai = 10;

    printf("Entrez une lettre :\n");
    scanf("%c", &lettre); 

    // changement de la lettre en sa majuscule (ASCII)
    if (lettre > 97)
    {
        lettre = lettre - 32;
    }
    

    lettreisIn = strchr(mot, lettre);
    

    if(lettreisIn != NULL){
        printf("Bravo, la lettre %c est bien dans le mot\n", lettre);
    }

    else{
        nbrEssai --; 
        printf("Faux, la lettre %c n'est pas dans le mot.\nIl vous reste %d essai(s)\n", lettre, nbrEssai);       
    }

    return 0;
}
