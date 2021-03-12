#include "background.h"
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
void Initback( background * b )
{

b->image[0]=IMG_Load("menu.jpg") ;
b->image[1]=IMG_Load("background.png") ;
b->image[2]=IMG_Load("castle.png") ;
b->position.x=0;
b->position.y=0;

}
void afficherback ( background * b , SDL_Surface * ecran)
{
 
SDL_BlitSurface(b->image[b->etat], NULL, ecran,&b->position);
}


void freeback( background * b )
{
SDL_FreeSurface(b->image[b->etat]) ;

}
