#include "background.h"
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
void init_affiche(char nomFichier[],SDL_Surface *image)
{ 

image=IMG_Load(nomFichier);

}
void affiche(int posx,int posy,SDL_Surface *screen,SDL_Surface *image)
{
SDL_Rect positionecran;
positionecran.x=posx;
positionecran.y=posy;
SDL_BlitSurface(image, NULL, screen, &positionecran);




}
