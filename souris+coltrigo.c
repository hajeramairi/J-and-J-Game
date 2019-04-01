#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"

float lerp(float a,float b, float t)
{
	return a + t * (b - a);
}

int collision(SDL_Rect a,float ra, SDL_Rect b, float rb){
	float ax = a.x + a.w / 2.0f;	
	float ay = a.y + a.h / 2.0f;	
	float bx = b.x + b.w / 2.0f;	
	float by = b.y + b.h / 2.0f;	

	if(sqrt(abs(ax-bx)*abs(ax-bx) + abs(ay-by)*abs(ay-by)) < rb + ra){
		return 1;
	}

	return 0;
}

int main(int argc,char *argv[])
{
SDL_Surface *screen, *player, *enemy;
SDL_Init(SDL_INIT_EVERYTHING);
     
screen=SDL_SetVideoMode(600,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);// init de la fenetre d execution
SDL_Event event;// declaration de l event 

player = SDL_CreateRGBSurface(0,32,32,32,0,0,0,0);//creation d un carrau
SDL_FillRect(player, NULL, 0xffffff);//couleur du carrau
SDL_Rect playerRect = {50,50};// position du carrau

enemy = SDL_CreateRGBSurface(0,32,32,32,0,0,0,0);//creation d un carrau
SDL_FillRect(enemy, NULL, 0xff0000);//couleur du carrau
SDL_Rect enemyRect = {200,200};// position du carrau

int mouseX = playerRect.x;//deplacement avc souris du l axe x
int mouseY = playerRect.y;//deplacement avc souris du l axe y

int running = 1;// variable qui boucle tant que le prog est en marche 


while(running)
{
	while(SDL_PollEvent(&event))
{
		if(event.type == SDL_QUIT){
			running = 0;
		}// tant que il y a un event de fermeture la fenetre se ferme

		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			SDL_GetMouseState(&mouseX,&mouseY);// si clic = pos x pos y
		}
	}
	SDL_FillRect(screen,NULL,0x000000);//couleur de l ecran
	SDL_BlitSurface(player,NULL,screen,&playerRect);//affiche plqyer dans sa position
	SDL_BlitSurface(enemy,NULL,screen,&enemyRect);//affiche ennemie dans sa position

	playerRect.x = (int) lerp(playerRect.x,mouseX,0.2);//changement de position du personnage
	playerRect.y = (int) lerp(playerRect.y,mouseY,0.2);

	if(collision(playerRect,20,enemyRect,20))
	{
		running = 0;
	}// tant que il y a une collision la fenetre se ferme

	SDL_Flip(screen);//redecine ecran ; mise a jour de l ecran
	SDL_Delay(16);// ecart de temps , 9adeh to93ed wa9et bech temchi men position li position

}
return 0;
}
