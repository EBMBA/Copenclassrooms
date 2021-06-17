#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int generateNumber(int min, int max){

    srand(time(NULL));

    int nombreMystere = ( rand() % ( max - min + 1 ) ) + min; 

    return nombreMystere;
}

void singlePlayer(int max){
    const int min =1;
    int nombreMystere = generateNumber(min,max);
    int nombreUser, coups = 0;

    bool nonTrouve = true, continuePartie = true;

    int reponse = 0;

    do
    {
        do
        {
            printf("Rentrer un nombre entre %d et %d :\n", min, max);
            scanf("%d", &nombreUser);

            while ((nombreUser < min ) || (nombreUser > max))
            {
                coups ++;
                printf("////////////////// ERREUR \\\\\\\\\\\\\\\\\\\\ \n");
                printf("Rentrer un nombre entre %d et %d :\n", min, max);
                scanf("%d", &nombreUser);
            }
            
            if (nombreUser < nombreMystere)
            {
                printf("Plus grand\n");
                coups ++;
            }

            else if (nombreUser > nombreMystere)
            {
                printf("Plus petit\n");
                coups ++;
            }

            else
            {   
                coups ++;
                printf("Bravo vous avez trouvé en %d coups\n", coups);
                nonTrouve = false;
                reponse = 0;
            }
        } while (nonTrouve);

        while ((reponse != 1 ) && (reponse != 2))
        {
            printf("Voulez-vous continuer la partie ?\n1. Oui\n2. Non\n");
            scanf("%d", &reponse);
        }
        
        

        switch (reponse)
        {
        case 1:
            continuePartie = true;
            nombreMystere = generateNumber(min,max);
            nombreUser, coups = 0;
            nonTrouve = true;
            break;
        
        case 2:
            continuePartie = false;
            printf("Merci d'avoir joué !");
            break;
        
        default:
            break;
        }

    } while (continuePartie);
}

void multiplayer(int max){
    const int min =1;
    int nombreMystere = -1;
    int nombreUser, coups = 0;

    bool nonTrouve = true, continuePartie = true;

    int reponse = 0;

    while ((nombreMystere < min ) || (nombreMystere > max))
    {
        printf("Donnez un nombre à deviner entre %d et %d:\n", min, max);
        scanf("%d", &nombreMystere);
    }

    do
    {
        do
        {
            printf("Rentrer un nombre entre %d et %d :\n", min, max);
            scanf("%d", &nombreUser);

            while ((nombreUser < min ) || (nombreUser > max))
            {
                coups ++;
                printf("////////////////// ERREUR \\\\\\\\\\\\\\\\\\\\ \n");
                printf("Rentrer un nombre entre %d et %d :\n", min, max);
                scanf("%d", &nombreUser);
            }
            
            if (nombreUser < nombreMystere)
            {
                printf("Plus grand\n");
                coups ++;
            }

            else if (nombreUser > nombreMystere)
            {
                printf("Plus petit\n");
                coups ++;
            }

            else
            {   
                coups ++;
                printf("Bravo vous avez trouvé en %d coups\n", coups);
                nonTrouve = false;
                reponse = 0;
            }
        } while (nonTrouve);

        while ((reponse != 1 ) && (reponse != 2))
        {
            printf("Voulez-vous continuer la partie ?\n1. Oui\n2. Non\n");
            scanf("%d", &reponse);
        }
        
        

        switch (reponse)
        {
        case 1:
            continuePartie = true;
            nombreMystere = -1;

            while ((nombreMystere < min ) || (nombreMystere > max))
            {
                printf("Donnez un nombre à deviner entre %d et %d :\n", min, max);
                scanf("%d", &nombreMystere);
            }

            nombreUser, coups = 0;
            nonTrouve = true;
            break;
        
        case 2:
            continuePartie = false;
            printf("Merci d'avoir joué !");
            break;
        
        default:
            break;
        }

    } while (continuePartie);
}

int main(int argc, char *argv[]) {
    int choixNiveauUser=-1;
    int max;

    while ((choixNiveauUser != 1) && (choixNiveauUser !=2) && (choixNiveauUser !=3))
    {
        printf("=== Menu choix du niveau ===\n");
        printf("1. Niveau 1\n2. Niveau 2\n3. Niveau 3\n");//
        printf("Votre choix ?\n");
        scanf("%d", &choixNiveauUser);
    }
    
    

    switch (choixNiveauUser)
    {
    case 1:
        max = 100;
        break;

    case 2:
        max = 1000;
        break;

    case 3:
        max = 10000;
        break;
    
    default:
        break;
    }

    int choixUser=-1;

    while ((choixUser != 1) && (choixUser !=2))
    {
        printf("=== Menu ===\n");
        printf("1. Solo\n2. Deux Joueurs\n");//
        printf("Votre choix ?\n");
        scanf("%d", &choixUser);
    }
    
    

    switch (choixUser)
    {
    case 1:
        singlePlayer(max);
        break;

    case 2:
        multiplayer(max);
        break;

    default:
        break;
    }

    return 0;
    
}