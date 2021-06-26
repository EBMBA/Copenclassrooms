#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"

/*
Une énumération ne contient pas de « sous-variables » comme c'était le cas pour les structures. C'est une liste de « valeurs possibles » pour une variable. 
Une énumération ne prend donc qu'une case en mémoire et cette case peut prendre une des valeurs que vous définissez (et une seule à la fois).
*/

int main(int argc, char const *argv[])
{
    Volume musique = MOYEN;

    return 0;
}
