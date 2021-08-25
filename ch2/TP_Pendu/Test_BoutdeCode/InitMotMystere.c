#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char mot[] = "ROUGE";
    char motMystere[100]; 
    size_t tailleMot = strlen(mot);

    for (size_t i = 0; i < tailleMot; i++)
    {   
        printf("%c\n", mot[i]);
        motMystere[i] = 42;
    }

    printf("%s\n", motMystere);

    return 0;
}
