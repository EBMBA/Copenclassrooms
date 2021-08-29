#include <stdio.h>
#include <stdlib.h>

void initMotMystere(char *motMystere, int tailleMot){
    for (size_t i = 0; i < tailleMot; i++)
    {   
        motMystere[i] = 42;
    }
    printf("Voici le mot à deviner : %s \nIl y a %d caracteres\n", motMystere, tailleMot);
}