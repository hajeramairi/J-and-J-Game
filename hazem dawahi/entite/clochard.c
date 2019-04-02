#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"clochard.h"


void CLOCHARD_Init(Clochard *c, int x, int y){
	c->sprite = IMG_Load("clochard.png");
	c->sprite2 = IMG_Load("clochard2.png");
	c->x = x;
	c->y = y;
	c->dx = 0;
	c->cx = 0;
}

void CLOCHARD_Render(Clochard *c, SDL_Surface **screen){
	SDL_Rect r2 = {c->x, c->y};
	if(c->dx){
		c->x += 5;
		SDL_BlitSurface(c->sprite2,NULL,*screen, &r2);
	}else{
		SDL_BlitSurface(c->sprite,NULL,*screen, &r2);
		c->x -= 5;

	}

	c->cx++;
	if(c->cx % 30 == 0)
		c->dx = !c->dx;
}
