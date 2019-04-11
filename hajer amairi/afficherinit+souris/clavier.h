#pragma once
#include<SDL/SDL.h>

typedef struct Input
 {
    char key[SDLK_LAST]; // initialiser un tableau de characters avec un taille de toutes les
	// touches (SDLK_LAST est la valeur de la derniere touche

} Input;

void UpdateEvent(Input *in);
