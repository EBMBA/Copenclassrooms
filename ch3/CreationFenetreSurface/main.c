#include "SDL/SDL.h"
#include <stdlib.h>
#include <stdio.h>

/* Voici donc les deux premières fonctions de la SDL à connaître :

    SDL_Init: charge la SDL en mémoire (desmallocy sont faits) ;

    SDL_Quit: libère la SDL de la mémoire (desfreey sont faits). 
*/

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
    SDL_Surface *ecran = NULL;
    SDL_Surface *rectangle = NULL;
    SDL_Rect positionRectangle;


    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(640,480,32, SDL_HWSURFACE| SDL_RESIZABLE | SDL_DOUBLEBUF);
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
    
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

    // Centre en fonction des dimension de l'ecran et du rectangle 
    positionRectangle.x = ecran->w/2 - rectangle->w/2;
    positionRectangle.y = ecran->h/2 - rectangle->h/2;

    SDL_WM_SetCaption("Emile METRAL Apps", NULL);
    Uint32 bleuVert = SDL_MapRGB(ecran->format, 17, 206, 112);
    Uint32 blanc = SDL_MapRGB(ecran->format, 255, 255, 255);
    SDL_FillRect(ecran, NULL, bleuVert); // Colorisation de la surface de l'ecran 
    SDL_FillRect(rectangle, NULL, blanc);
    SDL_BlitSurface(rectangle, NULL, ecran, &positionRectangle);

    SDL_Flip(ecran); // Mise a jour de l'ecran 

    pause();
    
    SDL_FreeSurface(rectangle);
    SDL_Quit(); // Arrêt de la SDL (libération de la mémoire).
 
    return EXIT_SUCCESS;
}
