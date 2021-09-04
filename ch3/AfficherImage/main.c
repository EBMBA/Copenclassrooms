#include "SDL/SDL.h" // gcc -o executable main.c `sdl-config --cflags --libs`
#include "SDL/SDL_image.h" // gcc -o executable main.c `sdl-config --cflags --libs` -lSDL_image
#include <stdlib.h>
#include <stdio.h>

void pause(){
    int continuer = 1;

    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event) ;

        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
        }

    }
    
}

int main(int argc, char const *argv[])
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *icone = NULL, *zozor = NULL, *sapin = NULL;
    SDL_Rect positionFond, positionZozor, positionSapin;
    
    positionFond.x = 0 ;
    positionFond.y = 0 ;
    positionZozor.x = 500 ;
    positionZozor.y = 260 ;
    positionSapin.x = 250 ;
    positionSapin.y = 130 ;

    SDL_Init(SDL_INIT_VIDEO);

    // Chargement de l'icône AVANT SDL_SetVideoMode 
    icone = SDL_LoadBMP("img/sdl_icone.bmp");
    SDL_WM_SetIcon(icone, NULL);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);

    imageDeFond = SDL_LoadBMP("img/lac_en_montagne.bmp");
    
    if ( ecran == NULL ) // Démarrage de la SDL. Si erreur :
    {
        fprintf(stderr,  "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);    
        /* 
            En effet, le nombre qui signifie « erreur » par exemple peut être différent selon les ordinateurs ! Cela dépend là encore de l'OS.
            Pour pallier ce problème, stdlib.h nous fournit deux constantes (desdefine) :

                EXIT_FAILURE: valeur à renvoyer en cas d'échec du programme ;

                EXIT_SUCCESS: valeur à renvoyer en cas de réussite du programme.
        */
    }

    SDL_WM_SetCaption("Emile METRAL Apps", NULL);

    Uint32 bleuVert = SDL_MapRGB(ecran->format, 17, 206, 112);
    SDL_FillRect(ecran, NULL, bleuVert); // Colorisation de la surface de l'ecran 
    
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    zozor = SDL_LoadBMP("img/zozor.bmp");
    // transparence du fond unicouleur = bleu
    SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));
    // transparence de l'image 
    SDL_SetAlpha(zozor, SDL_SRCALPHA, 128);
    SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);

    /* Chargement d'un PNG avec IMG_Load
    Celui-ci est automatiquement rendu transparent car les informations de
    transparence sont codées à l'intérieur du fichier PNG */
    sapin = IMG_Load("img/sapin.png");
    SDL_BlitSurface(sapin, NULL, ecran, &positionSapin);

    SDL_Flip(ecran); // Mise a jour de l'ecran 
    pause();
    
    SDL_FreeSurface(sapin);
    SDL_FreeSurface(zozor);
    SDL_FreeSurface(imageDeFond);
    SDL_Quit(); // Arrêt de la SDL (libération de la mémoire).
 
    return EXIT_SUCCESS;
}
