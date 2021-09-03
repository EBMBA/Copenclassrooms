#include "SDL/SDL.h"
#include <stdlib.h>
#include <stdio.h>

/* Voici donc les deux premières fonctions de la SDL à connaître :

    SDL_Init: charge la SDL en mémoire (desmallocy sont faits) ;

    SDL_Quit: libère la SDL de la mémoire (desfreey sont faits). 
*/

void pause();

int main(int argc, char const *argv[])
{
    SDL_Surface *ecran = NULL;
    SDL_Surface *rectangle[256] = {NULL};
    SDL_Rect positionRectangle;


    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE| SDL_RESIZABLE | SDL_DOUBLEBUF);
    
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

    for (size_t i = 0; i < 256; i++)
    {
        rectangle[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, ecran->w, 1, 32, 0, 0, 0, 0);
    }
    

    for (size_t i = 0; i < 256; i++)
    {
        positionRectangle.x = 0;
        positionRectangle.y = i;
        Uint32 couleur = SDL_MapRGB(ecran->format, i, i, i);
        SDL_FillRect(rectangle[i], NULL, couleur);
        SDL_BlitSurface(rectangle[i], NULL, ecran, &positionRectangle);
    }

    SDL_Flip(ecran); // Mise a jour de l'ecran 

    pause();
    
    for (size_t i = 0; i < 256; i++)
    {
        SDL_FreeSurface(rectangle[i]);
    }
    
    SDL_Quit(); // Arrêt de la SDL (libération de la mémoire).
 
    return EXIT_SUCCESS;
}

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