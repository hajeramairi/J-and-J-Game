#include <stdio.h>
#include "SDL/SDL_image.h"
#include"SDL/SDL.h"
int main(int argc, char *argv[])
 {
	SDL_Surface *ecran = NULL;
	SDL_Surface *sprite = NULL;
	SDL_Rect positionSprite;
	SDL_Rect positionecran;
	SDL_Event event;
	 int continuer = 1;
	 int tempsPrecedent = 0;
	int tempsActuel = 0;
	char pause;
	SDL_Init(SDL_INIT_VIDEO);
	if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
		printf("unable to initializeSDL:%s \n",SDL_GetError());
		return 1;
	}
	ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (ecran==NULL)
	{	
		printf("unable to load bitmap %s\n",SDL_GetError());
		return 1;
	}
 	SDL_WM_SetCaption("Gestion du temps en SDL", NULL);
	sprite = IMG_Load("detective.png");
	if (sprite==NULL)
	{	
	printf("unable to load detective image %s\n",SDL_GetError());
	return 1;
	}
	 SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format, 34, 177, 76));
	SDL_EnableKeyRepeat(10, 10);
	positionSprite.x = ecran->w / 2 - sprite->w / 2;
	positionSprite.y = ecran->h / 2 - sprite->h / 2;
while ( continuer )
 {
 // On utilise PollEvent et non WaitEvent pour ne pas bloquer le programme SDL_PollEvent(&event);
	switch ( event.type )
	 {
		 case SDL_QUIT:
 	continuer = 0;
 	break;
 	default: break;
 	}
	tempsActuel = SDL_GetTicks(); /* Si 30 ms se sont écoulées depuis le dernier tour de boucle */
	 if (tempsActuel - tempsPrecedent > 30)
 	{
	 positionSprite.x++; /* On bouge le sprite */ // Le temps "actuel" devient le temps "precedent" tempsPrecedent = tempsActuel ;
 	}
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
	SDL_BlitSurface(sprite, NULL, ecran, &positionSprite);
	SDL_Flip(ecran);
 	}
	SDL_FreeSurface(sprite);
	SDL_Quit();
	pause=getchar();
return 0;
} 
