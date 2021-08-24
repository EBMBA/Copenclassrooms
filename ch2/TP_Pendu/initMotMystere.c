#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initMotMystere(char *pointeurMotMystere[], int nombreCaractere){
    for (int i = 0; i < nombreCaractere; i++)
    {
        *pointeurMotMystere[i] = "*";
    }
    
}