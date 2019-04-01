#pragma once
#include<SDL/SDL.h>

typedef struct Input
 {
    char key[SDLK_LAST];

} Input;

void UpdateEvent(Input *in);
