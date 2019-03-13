#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void afficher_enigme(char image[20])
{
SDL_Surface *fenetreenigme=NULL,*enigme=NULL;
SDL_Rect positionenigme;
    positionenigme.x = 0;
    positionenigme.y = 0;
fenetreenigme = SDL_SetVideoMode(800, 700, 32, SDL_HWSURFACE);
enigme = IMG_Load(image);
SDL_BlitSurface(enigme, NULL, fenetreenigme, &positionenigme);
SDL_Flip(fenetreenigme);
}

