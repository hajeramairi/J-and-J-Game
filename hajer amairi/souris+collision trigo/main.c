#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include"coll.h"
float lerp(float a,float b, float t)
{
	return a + t * (b - a);// interpolation lineaire (lisser le deplacement)
}

int collision(SDL_Rect a,float ra, SDL_Rect b, float rb){
	float ax = a.x + a.w / 2.0f;//calcule abcisse et largeur de c1
	float ay = a.y + a.h / 2.0f;//calcule ordonne et longueur de c1	
	float bx = b.x + b.w / 2.0f;//calcule abcisse et largeur de c2	
	float by = b.y + b.h / 2.0f;//calcule ordonne et longueur de c2	

	if(sqrt(abs(ax-bx)*abs(ax-bx) + abs(ay-by)*abs(ay-by)) < rb + ra)//comparaison des rayon par rapport a la distance 
{
		return 1;
	}

	return 0;
}
int main(int argc,char *argv[])
{
SDL_Surface *screen, *player, *enemy;
SDL_Init(SDL_INIT_EVERYTHING);//init tout 
     
screen=SDL_SetVideoMode(600,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);//init fenetre
SDL_Event event;

player = SDL_CreateRGBSurface(0,32,32,32,0,0,0,0);// creation de la surface du player
SDL_FillRect(player, NULL, 0xffffff);//remplir une surface avec une couleur
SDL_Rect playerRect = {50,50};// position du player

enemy = SDL_CreateRGBSurface(0,32,32,32,0,0,0,0);//creation de la srface du de l ennemie
SDL_FillRect(enemy, NULL, 0xff64ff);//remplir une surface avec une couleur
SDL_Rect enemyRect = {200,200};//position de l ennemie 

int mouseX = playerRect.x;//int position de la souris prend la position du player sur l axe x 
int mouseY = playerRect.y;//init position de la souris prend la position de player sur l axe y

int running = 1;


while(running){
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running = 0;
		}//tant que il ya un event de fermeture le programme se ferme

		if(event.type == SDL_MOUSEBUTTONDOWN){
			SDL_GetMouseState(&mouseX,&mouseY);
		}//tant que il y a un clic la position x et y de la souris se change
	}
	SDL_FillRect(screen,NULL,0x000000);//redessine l ecran en noir 
	SDL_BlitSurface(player,NULL,screen,&playerRect);//dessine le player dans sa nouvelle position
	SDL_BlitSurface(enemy,NULL,screen,&enemyRect);//dessine l ennemie dans sa nouvelle position

	playerRect.x = (int) lerp(playerRect.x,mouseX,0.2);//le joueur prend la nouvelle position de la souris sur l axe x
	playerRect.y = (int) lerp(playerRect.y,mouseY,0.2);//le joueur prend la nouvelle position de la souris sur l axe y
	// on fait appelle a la fonction lerp qui calcule la nouvelle position du joueur 
	if(collision(playerRect,20,enemyRect,20)){
		running = 0;
	}// si il y a une collision le programme se ferme

	SDL_Flip(screen);//refraichir l ecran
	SDL_Delay(16);//mettre le jeu en pause qui prend 16 ms 
}
return 0;
}
