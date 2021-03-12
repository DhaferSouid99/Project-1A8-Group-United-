#include "background.h"
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

void Initimage(SDL_Surface *image,char nomfichier[])
{

image=IMG_Load(nomfichier);
    if(!image)
    {
        printf("Erreur lors de chargement de l image: %s", SDL_GetError());
    }

}
