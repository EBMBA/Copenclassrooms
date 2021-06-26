#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#include "main.h" // Inclusion du .h qui contient les prototypes et structures

void initialiserCoordonnees(Coordonnees* point);

int main(int argc, char *argv[])
{
    // Si pas de typedef :
    //struct Coordonnees point; // Création d'une variable "point" de type Coordonnees
    // Si typedef :
    Coordonnees point; // L'ordinateur comprend qu'il s'agit de "struct Coordonnees" grâce au typedef

    point.x = 10;
    point.y = 20;

    Personne utilisateur;

    printf("Quel est votre nom ? ");
    scanf("%s", utilisateur.nom);
    printf("Votre prenom ? ");
    scanf("%s", utilisateur.prenom);

    printf("Vous vous appelez %s %s\n", utilisateur.prenom, utilisateur.nom);

    Personne joueurs[2];

    for (int i = 0; i < 2; i++)
    {
        printf("Quel est votre nom ? ");
        scanf("%s", joueurs[i].nom);
        printf("Votre prenom ? ");
        scanf("%s", joueurs[i].prenom);
    
        printf("Vous vous appelez %s %s\n", joueurs[i].prenom, joueurs[i].nom);
    }

    // Initialisation correcte 
    Coordonnees pointNv = {0, 0};
    Personne utilisateurNv = {"", "", "", 0, 0};

    // pointeur de structure 
    Coordonnees* pointNv2 = NULL; 
    
    // Définire plusieurs pointeurs : Coordonnees *point1 = NULL, *point2 = NULL;

    Coordonnees monPoint;
    initialiserCoordonnees(&monPoint);

    return 0;
}

void initialiserCoordonnees(Coordonnees* point)
{
    // Initialisation de chacun des membres de la structure ici
    point->x=0; // au lieu de (*point).x = 0;
    point->y=0; // au lieu de (*point).y = 0;
}