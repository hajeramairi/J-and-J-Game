#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"

#define BOTTOM 1
#define TOP 2
#define LEFT 3
#define RIGHT 4

SDL_Surface * initEcran(char * titre, char * icone, int largeur, int hauteur);
void afficheMessage( SDL_Color textColor, SDL_Rect position);
void blitImageSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect *position);
void attendreTemps(int millisecondes);
void deplacement(SDL_Rect * pos, SDL_Event event, int vitesse_x, int vitesse_y);
int testCollision(SDL_Rect obj1, SDL_Rect obj2, int * typeCollision);
#endif // BOUNDINGBOX_H
