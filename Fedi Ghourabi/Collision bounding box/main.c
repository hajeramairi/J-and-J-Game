#include <stdio.h>
#include <stdlib.h>
#include "boundigbox.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#define LARGEURECRAN 640
#define HAUTEURECRAN 480
#define TITREECRAN "Collision bounding box SDL"
#define ICONE "pomme.png"
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;
    SDL_Rect positionImg1={150,240},positionImg2={320,240};
    int typeCollision;
    int continuer = 1;
    int vitX=2, vitY=2;
    SDL_Event event;
    ecran = initEcran(TITREECRAN, ICONE,LARGEURECRAN , HAUTEURECRAN);
    while(continuer)
    {
        SDL_PollEvent(&event);
        backgroundColorSurface(ecran, 0, 0, 0);

        blitImageSurSurface(ecran, "pomme.png", &positionImg2);
        blitImageSurSurface(ecran, "pomme.png", &positionImg1);
        if(testCollision(positionImg1, positionImg2, &typeCollision))
        {
            deplacement(&positionImg1, event, vitX, vitY);
        }
        else
        {
            deplacementAutorise(typeCollision, &positionImg1, event, vitX, vitY);
        }

        attendreTemps(5);

        SDL_Flip(ecran);
    }
    SDL_Quit();
    return 0;
}
