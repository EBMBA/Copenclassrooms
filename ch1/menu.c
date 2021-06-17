/*
Ci-dessous, ce sont des directives de préprocesseur.
Ces lignes permettent d'ajouter des fichiers au projet, 
fichiers que l'on appelle bibliothèques.
Grâce à ces bibliothèques, on disposera de fonctions toutes prêtes pour afficher
par exemple un message à l'écran.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ci-dessous, vous avez la fonction principale du programme, appelée main.
C'est par cette fonction que tous les programmes commencent.
Ici, ma fonction se contente d'afficher Bonjour à l'écran.
*/

int main(int argc, char *argv[])
{
    const char* menu[4] = {"Royal Cheese", "Mc Deluxe", "Mc Bacon", "Big Mac"};
    int choixUser;

    printf("=== Menu ===\n");

    for (int i = 1; i <= 4; i++)
    {
        printf("%d. %s\n", i, menu[i-1]);//
    }
    
    printf("Votre choix ?\n");

    scanf("%d", &choixUser);

    switch (choixUser)
    {
    case 1:
        printf("Tu as choisi le menu %s\n",menu[0]);
        break;

    case 2:
        printf("Tu as choisi le menu %s\n",menu[1]);
        break;

    case 3:
        printf("Tu as choisi le menu %s\n",menu[2]);
        break;

    case 4:
        printf("Tu as choisi le menu %s\n",menu[3]);
        break;

    default:
        break;
    }

    return 0;          // Le programme renvoie le nombre 0 puis s'arrête
}