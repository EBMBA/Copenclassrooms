#include <stdio.h>
#include <stdlib.h>

char lireCaractere() 
{ 
    char caractere = 0;
 
    caractere = getchar(); // On lit le premier caractère
    // changement de la lettre en sa majuscule (ASCII)
    if (caractere >= 97)
    {
        caractere = caractere - 32;
    } 
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer) 
    while (getchar() != '\n') ;
 
    return caractere; // On retourne le premier caractère qu'on a lu 
}
