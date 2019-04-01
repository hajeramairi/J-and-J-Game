#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "sprite.h"

SDL_Surface *screen,*back;
int running = 1;

Player p;


void gameLoop() {
while(running)
{

                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        running = 0;
                                        break;
				case SDL_KEYDOWN:
					if(event.key.keysym.sym==SDLK_RIGHT)
						p.vx = 5;
					if(event.key.keysym.sym==SDLK_LEFT)
						p.vx = -5;
					if(event.key.keysym.sym==SDLK_UP)
						p.vy = -20;
				break;
				case SDL_KEYUP:
					if(event.key.keysym.sym==SDLK_RIGHT)
						p.vx = 0;
					if(event.key.keysym.sym==SDLK_LEFT)
						p.vx = 0;
				break;
						}
					}

//image et position du background

SDL_BlitSurface(back,NULL,screen,NULL);


// dessine l'image couper selon le rectangle clip a la position du rectangle position
render(&p);

// redessine l'ecran
SDL_Flip(screen);

SDL_Delay(16);
}
}

int main(int argc,char** argv)
{

SDL_Init(SDL_INIT_EVERYTHING);
screen=SDL_SetVideoMode(1200,550,32,SDL_SWSURFACE);
back=IMG_Load("back.png");
init(&p,&screen);
gameLoop();
SDL_Quit();

return 0;
}
