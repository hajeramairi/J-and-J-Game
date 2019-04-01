#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
int main(void)
{
SDL_Surface*screen;
SDL_Surface*image;
SDL_Surface*obj;
SDL_Rect posecran;
SDL_Rect posobj;
SDL_Event event;
int running=1;

while(running)
{
		while(SDL_PollEvent(&event))
		{

			if(event.type==SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
		{
				running = 0;
		}

}
if (SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialise sdl %s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(600,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (screen==NULL)
{
printf("Unable to set screen %s\n",SDL_GetError());
return 1;
}
image=IMG_Load("backx.png");
if (image==NULL)
{
printf("Unable to set bmp image %s\n",SDL_GetError());
return 1;
}
obj=IMG_Load("pomme.png");
if (obj==NULL)
{
printf("unable to load object image %s \n",SDL_GetError());
return 1;
}
posecran.x=0;
posecran.y=0;
posecran.w=image->w;
posecran.h=image->h;
posobj.x=275;
posobj.y=150;
SDL_BlitSurface(image,NULL,screen,&posecran);
SDL_BlitSurface(obj,NULL,screen,&posobj);
SDL_Flip(screen);
SDL_FreeSurface(image);
SDL_FreeSurface(obj);
}
SDL_Quit();
return 0;

}
