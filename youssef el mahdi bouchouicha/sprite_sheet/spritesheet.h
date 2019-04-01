#pragma once

SDL_Surface *screen, *image;
int running = 1;

SDL_Rect rect, rectt, rects[7];
float frame = 0;

void init ();
void initImage();
void gameLoop();
void setrects(SDL_Rect* clip);



