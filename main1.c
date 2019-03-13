#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include"SDL/SDL.h"

int main(void)
{
char pause;
SDL_Surface *screen = NULL;
SDL_Surface *detc = NULL;
SDL_Rect positionecran;
SDL_Rect positiondetc;
SDL_Event event;
int done=0;
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
	printf("unable to initializeSDL:%s \n",SDL_GetError());
	return 1;
}

screen = SDL_SetVideoMode(800,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


if (screen==NULL)
{	
	printf("unable to load bitmap %s\n",SDL_GetError());
	return 1;
}
SDL_WM_SetCaption("Gestion du temps en SDL", NULL);
detc=IMG_Load("detective.png");
if (detc==NULL)
{	
	printf("unable to load detective image %s\n",SDL_GetError());
	return 1;
}
SDL_SetColorKey(detc, SDL_SRCCOLORKEY, SDL_MapRGB(detc->format, 34, 177, 76));
SDL_EnableKeyRepeat(10, 10);
positionecran.x=0;
positionecran.y=0;
positiondetc.x=screen->w/2-detc->w/2;
positiondetc.y=250;


while(done!=1)
{

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT;
		break ;

        case SDL_MOUSEBUTTONLEFT:
             if(event.button.button==SDL_BUTTON_LEFT)
              {
              	positiondetc.x = event.button.x;
             	positiondetc.y = event.button.y;
SDL_BlitSurface(detc,NULL,screen,&positiondetc);
SDL_Flip(screen);
SDL_Freesurface(detc);		
		break ;
              }
 	case SDL_MOUSEBUTTONRIGHT:
               if(event.button.button==SDL_BUTTON_RIGHT)
		{
			positiondetc.x = event.button.x;
             		positiondetc.y = event.button.y;
SDL_BlitSurface(detc,NULL,screen,&positiondetc);
SDL_Flip(screen);
SDL_Feesurface(detc);			
			break ;
		}
	}
	}
SDL_FillRect(screen, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
SDL_BlitSurface(detc,NULL,screen,&positiondetc);
SDL_Flip(screen);
}
SDL_Feesurface(detc);
return 0;
}


