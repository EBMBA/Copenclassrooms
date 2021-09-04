#include "SDL/SDL.h" // gcc -o executable main.c `sdl-config --cflags --libs`
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    SDL_Surface *ecran = NULL, *zozor = NULL;
    SDL_Rect positionZozor;
    SDL_Event event; // Cette variable servira plus tard à gérer les événements
    int continuer = 1 ;


    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);    
    SDL_WM_SetCaption("Gestion des événements en SDL", NULL);


    zozor = SDL_LoadBMP("../AfficherImage/img/zozor.bmp");
    SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));

    /* On centre Zozor à l'écran */
    positionZozor.x = ecran->w / 2 - zozor->w / 2;
    positionZozor.y = ecran->h / 2 - zozor->h / 2;

    SDL_EnableKeyRepeat(10, 10);
    
    // Placer la souris 
    SDL_WarpMouse(ecran->w / 2, ecran->h / 2);
    // Montrer ou pas le curseur 
    SDL_ShowCursor(SDL_ENABLE);

    SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
    SDL_Flip(ecran);

    while (continuer)
    {
        SDL_WaitEvent(&event) ;

        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;
                break;
            
            case SDLK_UP:
                if (positionZozor.y > 0)
                {
                    positionZozor.y --;
                }
                break;
            
            case SDLK_DOWN:
                if (positionZozor.y < ecran->h)
                {
                    positionZozor.y ++;
                } 
                break;
            

            case SDLK_LEFT:
                if (positionZozor.x > 0)
                {
                    positionZozor.x --;
                }
                break;
            
            case SDLK_RIGHT:
                if (positionZozor.x < ecran->w)
                {
                    positionZozor.x ++;
                }                
                break;
            
            break;
            }
        // Clique de la souris 
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_RIGHT){ /* On arrête le programme si on a fait un clic droit */
                continuer = 0;}
            positionZozor.x = event.button.x;
            positionZozor.y = event.button.y;
            break;
        // Deplacement de la souris
        case SDL_MOUSEMOTION:
            positionZozor.x = event.motion.x;
            positionZozor.y = event.motion.y;
            break;

        // Dimension de la fenetre 
        case SDL_VIDEORESIZE:
            positionZozor.x = event.resize.w / 2 - zozor->w / 2;
            positionZozor.y = event.resize.h / 2 - zozor->h / 2;
        break;
        }
    
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
        SDL_Flip(ecran);
        
    }

    
    SDL_FreeSurface(zozor);
    SDL_Quit();

    return EXIT_SUCCESS;
}
