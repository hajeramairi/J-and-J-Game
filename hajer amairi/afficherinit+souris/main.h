#pragma once
#include"clavier.h"


SDL_Surface *ecran, *detec,*message;
SDL_Rect positiondetec;
int continuer;
Input in;

void Initializer();
void Afficher();
