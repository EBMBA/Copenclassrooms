#include <stdio.h>
#include <stdlib.h>

/* 
Il existe plusieurs fonctions standards en C qui permettent de récupérer une chaîne de texte. 
Hormis la fonction scanf (trop compliquée pour être étudiée ici), il existe :

    gets: une fonction qui lit toute une chaîne de caractères, mais très dangereuse car elle ne permet pas de contrôler les buffer overflow !

    fgets: l'équivalent de gets mais en version sécurisée, permettant de contrôler le nombre de caractères écrits en mémoire.
*/

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int lire(char *chaine, int longueur)

{

    char *positionEntree = NULL;

    // On lit le texte saisi au clavier

    if (fgets(chaine, longueur, stdin) != NULL)  // Pas d'erreur de saisie ?

    {

        positionEntree = strchr(chaine, '\n'); // On recherche l'"Entrée"

        if (positionEntree != NULL) // Si on a trouvé le retour à la ligne

        {

            *positionEntree = '\0'; // On remplace ce caractère par \0

        }

        else
        {
            viderBuffer();
        }

        return 1; // On renvoie 1 si la fonction s'est déroulée sans erreur

    }

    else

    {
        viderBuffer();
        return 0; // On renvoie 0 s'il y a eu une erreur

    }

}

long lireLong()
{
    char nombreTexte[100] = {0}; // 100 cases devraient suffire
 
    if (lire(nombreTexte, 100))
    {
        // Si lecture du texte ok, convertir le nombre en long et le retourner
        return strtol(nombreTexte, NULL, 10);
    }
    else
    {
        // Si problème de lecture, renvoyer 0
        return 0;
    }
}

double lireDouble(){
    char doubleTexte[100] = {0};
    char *positionVirgule = NULL ;

    if (lire(doubleTexte, 100))
    {

        positionVirgule = strchr(doubleTexte, ',');
        if (positionVirgule != NULL)
        {
            *positionVirgule = '.';
        }
        
        
        // Si lecture du texte ok, convertir le nombre en double et le retourner
        return strtod(doubleTexte, NULL);
    }

    else{
        // Si problème de lecture, renvoyer 0
       return 0;
    }
    
}

int main(int argc, char const *argv[])
{
    char nom[20] = {0};
    long age = 0;
    double poids = 0.0;

    printf("Quel est votre nom ? ");
    lire(nom, 20);
    
    printf("Ah ! Vous vous appelez donc %s !\n\n", nom);

    printf("Quel est votre age ? ");
    age = lireLong();
    printf("Ah ! Vous avez donc %ld ans !\n\n", age);

    printf("Quel est votre poids ? ");
    poids = lireDouble();
    printf("Ah ! Vous faites donc %lf kg !\n\n", poids);

    return 0;
}
