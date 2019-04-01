#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"main.h"

void Initializer() {
    continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Essais detec", NULL);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran -> format, 255, 255, 255));
    detec = IMG_Load("detective.png");
    positiondetec.x = (ecran -> w / 2) - (detec -> w / 2);
    positiondetec.y = (ecran -> h / 2) - (detec -> h / 2);
    memset(&in, 0, sizeof(in));

}
void Afficher(){

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran -> format, 255, 255, 255));
        SDL_BlitSurface(detec, NULL, ecran, &positiondetec);
        SDL_Flip(ecran);

}

int main (int argc, char** argv)
{
	Initializer();
    do {
        UpdateEvent(&in);
        if (in.key[SDLK_UP]){
            positiondetec.y -= 1;
        }
        if (in.key[SDLK_DOWN]){
            positiondetec.y += 1;
        }
        if (in.key[SDLK_RIGHT]){
            positiondetec.x += 1;        }
        if (in.key[SDLK_LEFT]){
            positiondetec.x -= 1;
        }

		Afficher();

    } while (!in.key[SDLK_ESCAPE]);
    SDL_FreeSurface(detec);
    SDL_Quit();
    return EXIT_SUCCESS;
}
