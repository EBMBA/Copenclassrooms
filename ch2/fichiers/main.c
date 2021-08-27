#include <stdlib.h>
#include <stdio.h>

/*
Voici les modes d'ouverture possibles.

    "r": lecture seule. Vous pourrez lire le contenu du fichier, mais pas y écrire. Le fichier doit avoir été créé au préalable.

    "w": écriture seule. Vous pourrez écrire dans le fichier, mais pas lire son contenu. Si le fichier n'existe pas, il sera créé.

    "a": mode d'ajout. Vous écrirez dans le fichier, en partant de la fin du fichier. Vous ajouterez donc du texte à la fin du fichier. Si le fichier n'existe pas, il sera créé.

    "r+": lecture et écriture. Vous pourrez lire et écrire dans le fichier. Le fichier doit avoir été créé au préalable.

    "w+": lecture et écriture, avec suppression du contenu au préalable. Le fichier est donc d'abord vidé de son contenu, vous pouvez y écrire, et le lire ensuite. Si le fichier n'existe pas, il sera créé.

    "a+": ajout en lecture / écriture à la fin. Vous écrivez et lisez du texte à partir de la fin du fichier. Si le fichier n'existe pas, il sera créé.

Pour chaque mode qu'on a vu là, si vous ajoutez un"b"après le premier caractère ("rb","wb","ab","rb+","wb+","ab+"), alors le fichier est ouvert en mode binaire.
*/

FILE* fopen(const char* nomDuFichier, const char* modeOuverture);

/*
Cette fonction prend un paramètre : votre pointeur sur le fichier.
Elle renvoie unintqui indique si elle a réussi à fermer le fichier. Cetintvaut :

    0: si la fermeture a marché ;

    EOF: si la fermeture a échoué.EOFest undefinesitué dansstdio.hqui correspond à un nombre spécial,
    utilisé pour dire soit qu'il y a eu une erreur, soit que nous sommes arrivés à la fin du fichier. 
    Dans le cas présent cela signifie qu'il y a eu une erreur. 
*/
int fclose(FILE* pointeurSurFichier);

/*
Voici les trois fonctions que nous allons étudier :

    fputc: écrit un caractère dans le fichier (UN SEUL caractère à la fois) ;

    fputs: écrit une chaîne dans le fichier ;

    fprintf: écrit une chaîne « formatée » dans le fichier, fonctionnement quasi-identique àprintf.
*/

/* 
fputc
Cette fonction écrit un caractère à la fois dans le fichier.
La fonction retourne un int, c'est un code d'erreur. Cet int vaut EOF si l'écriture a échoué, sinon il a une autre valeur.
*/
int fputc(int caractere, FILE* pointeurSurFichier);

/* 
fputs
Cette fonction est très similaire à fputc, à la différence près qu'elle écrit tout une chaîne, ce qui est en général plus pratique que d'écrire caractère par caractère.
La fonction renvoieEOFs'il y a eu une erreur, sinon c'est que cela a fonctionné. 
*/
//char* fputs(const char* chaine, FILE* pointeurSurFichier);

/*
fprintf
Voici un autre exemplaire de la fonction printf. Celle-ci peut être utilisée pour écrire dans un fichier. 
Elle s'utilise de la même manière que printf d'ailleurs, excepté le fait que vous devez indiquer un pointeur de FILE en premier paramètre.*/

/*
Nous pouvons utiliser quasiment les mêmes fonctions que pour l'écriture, le nom change juste un petit peu :

    fgetc: lit un caractère ;

    fgets: lit une chaîne ;

    fscanf: lit une chaîne formatée.
*/

/* 
fgetc
Cette fonction retourne un int: c'est le caractère qui a été lu.
Si la fonction n'a pas pu lire de caractère, elle retourne EOF.
int fgetc(FILE* pointeurDeFichier);
*/

/*
fgets
Cette fonction lit une chaîne dans le fichier. 
Ça vous évite d'avoir à lire tous les caractères un par un. 
La fonction lit au maximum une ligne (elle s'arrête au premier\nqu'elle rencontre).
Si vous voulez lire plusieurs lignes, il faudra faire une boucle.
char* fgets(char* chaine, int nbreDeCaracteresALire, FILE* pointeurSurFichier);
*/
#define TAILLE_MAX 1000 // Tableau de taille 1000

/*
fscanf
C'est le même principe que la fonctionscanf, là encore.
Cette fonction lit dans un fichier qui doit avoir été écrit d'une manière précise.
*/

/* 
Se déplacer dans un fichier 
Il existe trois fonctions à connaître :

    ftell: indique à quelle position vous êtes actuellement dans le fichier ; long ftell(FILE* pointeurSurFichier);

    fseek: positionne le curseur à un endroit précis ; int fseek(FILE* pointeurSurFichier, long deplacement, int origine);

    rewind: remet le curseur au début du fichier (c'est équivalent à demander à la fonctionfseekde positionner le curseur au début).
    void rewind(FILE* pointeurSurFichier);
*/

/* 
fseek
La fonctionfseekpermet de déplacer le curseur d'un certain nombre de caractères (indiqué pardeplacement) à partir de la position indiquée parorigine.

    Le nombredeplacementpeut être un nombre positif (pour se déplacer en avant), nul (= 0) ou négatif (pour se déplacer en arrière).

    Quant au nombreorigine, vous pouvez mettre comme valeur l'une des trois constantes (généralement desdefine) listées ci-dessous :

        SEEK_SET: indique le début du fichier ;

        SEEK_CUR: indique la position actuelle du curseur ;

        SEEK_END: indique la fin du fichier.
*/

/*
Renommer et supprimer un fichier
    rename: renomme un fichier ; int rename(const char* ancienNom, const char* nouveauNom);
La fonction renvoie 0 si elle a réussi à renommer, sinon elle renvoie une valeur différente de 0.
 
    remove: supprime un fichier. int remove(const char* fichierASupprimer);
*/


int main(int argc, char const *argv[])
{
    FILE* fichier = NULL;
    int age = 0;  
    int caractereActuel = 0;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
    int score[3] = {0}; // Tableau des 3 meilleurs scores

    fichier = fopen("test.txt", "r+");

    // Chemin absolu Windows :
    // fichier = fopen("C:\\Program Files\\Notepad++\\readme.txt", "r+");
    // Chemin absolu Linux :
    // fichier = fopen("/home/mateo/dossier/readme.txt", "r+");

    // Verification avant lecture / ecriture dans le fichiers 

    if (fichier != NULL)
    {
        // On peut lire et ecrire dans le fichier
        
        fputc('A', fichier); // Écriture du caractère A
        fputs("Salut les Zér0s\nComment allez-vous ?", fichier);
        // On demande l'âge
        printf("Quel age avez-vous ? ");
        scanf("%d", &age);
 
        // On l'écrit dans le fichier
        fprintf(fichier, "Le Monsieur qui utilise le programme, il a %d ans", age);
        

        // Boucle de lecture des caractères un à un
        
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        

       
       fgets(chaine, TAILLE_MAX, fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"
       printf("%s", chaine); // On affiche la chaîne

        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {

            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire

        } 
        

       
        fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]);

        printf("Les meilleurs scores sont : %d, %d et %d", score[0], score[1], score[2]);

        fclose(fichier); // On ferme le fichier qui a été ouvert
        
    }
    else{

        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }

    return 0;
}
