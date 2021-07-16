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

/* Pour allouer manuellement de la mémoire :
        malloc(« Memory ALLOCation », c'est-à-dire « Allocation de mémoire ») : 
            demande au système d'exploitation la permission d'utiliser de la mémoire ;

        free(« Libérer ») : permet d'indiquer à l'OS que l'on n'a plus besoin de la mémoire 
            qu'on avait demandée. La place en mémoire est libérée, un autre programme peut maintenant 
            s'en servir au besoin.
    Quand vous faites une allocation manuelle de mémoire, vous devez toujours suivre ces trois étapes :

        1.  appeler malloc pour demander de la mémoire ;

        2.  vérifier la valeur retournée parmallocpour savoir si l'OS a bien réussi à allouer la mémoire ;

        3.  une fois qu'on a fini d'utiliser la mémoire, on doit la libérer avec free. 
    
    

*/

int main(int argc, char const *argv[])
{
    printf("Coordonnees : %d octets\n", sizeof(Coordonnees));
    printf("char : %d octets\n", sizeof(char));
    printf("int : %d octets\n", sizeof(int));
    printf("long : %d octets\n", sizeof(long));
    printf("double : %d octets\n", sizeof(double));

    int *memoireAllouee = NULL; // On crée un pointeu sur int 

    memoireAllouee = malloc(sizeof(int)); // malloc inscrit dans notre pointeur l'adresse qui a été resrvée.

    if (memoireAllouee == NULL)
    {
        exit(0); // on arrete le programme 
    }
    
    printf("Quel age avez-vous ? \n");
    scanf("%d", memoireAllouee);
    printf("Vous avez %d ans\n", *memoireAllouee);
    
    free(memoireAllouee); // On n'a plus besoin de la mémoire, on la libère

    // Pour des tableaux :
    
    int nombreDAmis = 0, i = 0;
    int *ageAmis = NULL; // Ce pointeur va servir de tableau après l'appel du malloc 

    // On demande le nombre d'amis 
    printf("Combien avez-vous d'amis ?\n");
    scanf("%d", &nombreDAmis);

    if ( nombreDAmis > 0 )
    {
        ageAmis = malloc(sizeof(int) * nombreDAmis); 

        if (ageAmis == NULL)
        {
            exit(0);
        }
        
        for (int i = 0; i < nombreDAmis; i++)
        {
            printf("\n Quel age à l'amis numero %d : \n", i+1);
            scanf("%d", &ageAmis[i]);
        }
        
        // On affiche les ages stockés 
        for (int i = 0; i < nombreDAmis; i++)
        {
            printf("L'ami n°%d a %d ans\n", i+1, ageAmis[i]);
        }
        
        free(ageAmis);
    }
    


    return 0;
}
