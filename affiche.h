#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#ifndef AFFICHE_H_INCLUDED
#define AFFICHE_H_INCLUDED


void init_affiche(char nomFichier[],SDL_Surface *image);
void affiche(int posx,int posy,SDL_Surface *screen,SDL_Surface *image);

#endif // BACKGROUND_H_INCLUDED

