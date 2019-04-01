#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "sprite.h"

void init(Player *p, SDL_Surface **screen){
	p->image = IMG_Load("ss.png");
	p->image2 = IMG_Load("ss2.png");
	p->position.x = 200;
	p->position.y = 100;
	
	for (int i = 0; i < 9; i++ ){
		p->clips[i].x = i*226;
		p->clips[i].y = 0;
		p->clips[i].w = 220;
		p->clips[i].h = 420;
	}
	for (int i = 0; i < 9; i++ ){
		p->clips2[i].x = 2046-30 -i*220;
		p->clips2[i].y = 0;
		p->clips2[i].w = 220;
		p->clips2[i].h = 420;
	}
	
	p->screen = screen;
	
	p->frame = 0;
}

void render(Player *p){
	if(p->vx >=0){
		SDL_BlitSurface(p->image,&p->clips[(int) p->frame],*p->screen,&p->position);
	}else{
		SDL_BlitSurface(p->image2,&p->clips2[(int) p->frame],*p->screen,&p->position);

	}

	if(p->vx != 0){
		p->frame += 0.2f;
		if(p->frame >9) p->frame = 1;
		p->position.x += p->vx;
	}else{
		p->frame = 0;
	}
	p->vy += 1;
	p->position.y += p->vy;
		
	if(p->position.y + 420 > 540){
		p->position.y =540-420;
		p->vy = 0;
	}
		
}
