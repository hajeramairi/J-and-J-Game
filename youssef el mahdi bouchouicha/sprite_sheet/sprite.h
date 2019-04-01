#pragma once


typedef struct Player{

	int x,y,vx,vy;
	SDL_Surface **screen,*image, *image2;
	SDL_Rect position;
	SDL_Rect clips[9];
	SDL_Rect clips2[9];
	float frame;
} Player;

void init(Player *p, SDL_Surface **screen);
void render(Player *p);

