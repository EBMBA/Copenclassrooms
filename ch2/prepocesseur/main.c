#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Les define 
#define LARGEUR_FENETRE  800
#define HAUTEUR_FENETRE  600
#define NOMBRE_PIXELS    (LARGEUR_FENETRE * HAUTEUR_FENETRE)

// MACRO
#define COUCOU() printf("coucou\n");
#define RACONTER_SA_VIE()   printf("Coucou, je m'appelle Brice\n"); \
                            printf("J'habite a Nice\n"); \
                            printf("J'aime la glisse\n"); \
                            printf("Super non ?\n");

// Macro avec paramètres 
#define MAJEUR(age) if (age >= 18){ \
                        printf("Vous etes majeur\n"); } \
                    else {\
                        printf("Vous etes mineur\n");}                    
#define MAJEURS(age, nom) if (age >= 18) \
                    printf("Vous etes majeur %s\n", nom);

// Les conditions préprocesseur
#define WINDOWS

#ifdef WINDOWS
    /* Code source pour Windows */
#endif

#ifdef LINUX
    /* Code source pour Linux */
#endif

#ifdef MAC
    /* Code source pour Mac */
#endif

// Condition préprocesseur pour eviter les boucles d'inclusion
#ifndef DEF_NOMDUFICHIER // Si la constante n'a pas été définie le fichier n'a jamais été inclus
#define DEF_NOMDUFICHIER // On définit la constante pour que la prochaine fois le fichier ne soit plus inclus

/* Contenu de votre fichier .h (autres include, prototypes, define...) */

#endif

int main(int argc, char const *argv[])
{
    COUCOU()

    // Constantes prédéfinies 
    printf("Erreur a la ligne %d du fichier %s\n", __LINE__, __FILE__);
    printf("Ce fichier a ete compile le %s a %s\n", __DATE__, __TIME__);

    RACONTER_SA_VIE()

    MAJEUR(21)
    MAJEURS(22, "Maxime")

    return 0;
}
