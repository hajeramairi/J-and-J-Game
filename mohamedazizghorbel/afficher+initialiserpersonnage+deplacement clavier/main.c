#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include<string.h>
typedef struct Input Input;
void UpdateEvent(Input *in);
struct Input
 {
    char key[SDLK_LAST];

}
;
int main (int argc, char** argv)
{
    SDL_Surface *ecran = NULL, *detec = NULL,*message=NULL;
    SDL_Rect positiondetec;
    int continuer = 1;
    Input in;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Essais detec", NULL);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran -> format, 255, 255, 255));
    detec = IMG_Load("detective.png");
    positiondetec.x = (ecran -> w / 2) - (detec -> w / 2);
    positiondetec.y = (ecran -> h / 2) - (detec -> h / 2);
    SDL_BlitSurface(detec, NULL, ecran, &positiondetec);
    SDL_Flip(ecran);
    memset(&in, 0, sizeof(in));
    do {
        UpdateEvent(&in);
        if (in.key[SDLK_UP]){
            detec = IMG_Load("detective.png");
            positiondetec.y -= 1;
        }
        if (in.key[SDLK_DOWN]){
            detec = IMG_Load("detective.png");
            positiondetec.y += 1;
        }
        if (in.key[SDLK_RIGHT]){
            detec = IMG_Load("detective.png");
            positiondetec.x += 1;        }
        if (in.key[SDLK_LEFT]){
            detec = IMG_Load("detective.png");
            positiondetec.x -= 1;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran -> format, 255, 255, 255));
        SDL_BlitSurface(detec, NULL, ecran, &positiondetec);
        SDL_Flip(ecran);
    } while (!in.key[SDLK_ESCAPE]);
    SDL_FreeSurface(detec);
    SDL_Quit();
    return EXIT_SUCCESS;
}
void UpdateEvent(Input *in){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_KEYDOWN :
                in -> key[event.key.keysym.sym] = 1;
                break;
            case SDL_KEYUP :
                in -> key[event.key.keysym.sym] = 0;
                break;
            default :
                break;
        }
    }
}

