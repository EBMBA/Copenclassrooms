struct NomDeVotreStructure
{
    int variable1;
    int variable2;
    int autreVariable;
    double nombreDecimal;
};

// Nous allons ajouter une instruction appelée typedef qui sert à créer un alias de structure, 
// c'est-à-dire à dire qu'écrire telle chose équivaut à écrire telle autre chose.
typedef struct Coordonnees Coordonnees; 
struct Coordonnees
{
    int x;
    int y;
};

typedef struct Personne Personne;
struct Personne
{
    char nom[100];
    char prenom[100];
    char adresse[1000];
    
    int age;
    int genre; // Booléen : 1 = garçon, 0 = fille
};
