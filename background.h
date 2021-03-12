#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

typedef struct {

SDL_Surface* image[3];
SDL_Rect position ;
SDL_Surface * text ;
SDL_Rect  postext ;
Mix_Music *music;

int etat ;


}background;

void Initback( background * b );
void afficherback ( background * b , SDL_Surface * ecran);
void freeback( background * b );


#endif // BACKGROUND_H_INCLUDED

