#include <stdlib.h>
#include <stdio.h>

/* Pour avoir la taille d'une variable (fonctionnalité du langage C): 
    sizeof();

Ex :

    printf("char : %d octets\n", sizeof(char));
    printf("int : %d octets\n", sizeof(int));
    printf("long : %d octets\n", sizeof(long));
    printf("double : %d octets\n", sizeof(double));
*/

typedef struct Coordonnees Coordonnees;
struct Coordonnees
{
    int x;
    int y;
};

int main(int argc, char const *argv[])
{
    printf("Coordonnees : %d octets\n", sizeof(Coordonnees));
    printf("char : %d octets\n", sizeof(char));
    printf("int : %d octets\n", sizeof(int));
    printf("long : %d octets\n", sizeof(long));
    printf("double : %d octets\n", sizeof(double));
    return 0;
}
