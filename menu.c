#include "initimage.h"
#include "background.h"
#include "affiche.h"
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>



int main ()
{   background b ;
   int etat=1 ,erreur;
    Uint32 start;
    Mix_Music *music;
    Mix_Chunk *son1;
    SDL_Surface *texte=NULL;
    SDL_Surface *screen=NULL;
    SDL_Surface *image1=NULL;
    SDL_Surface *play=NULL;
    SDL_Surface *settings=NULL;
    SDL_Surface *exit=NULL;
    SDL_Surface *play1=NULL;
    SDL_Surface *settings1=NULL;
    SDL_Surface* exit1=NULL ;
SDL_Surface* display=NULL;
SDL_Surface* backtomain=NULL;
SDL_Surface* controller=NULL;
SDL_Surface* minus=NULL;
SDL_Surface* plus=NULL;
SDL_Surface* sound_setting=NULL;
    SDL_Surface * play_motion=NULL;
SDL_Surface* option_motion=NULL;
SDL_Surface* exit_motion=NULL;
SDL_Surface* fullscreen=NULL;
SDL_Surface* bar=NULL;
SDL_Surface* bar1=NULL;
SDL_Surface* scrollbutton=NULL ;
SDL_Surface* scrollbutton1=NULL ;
SDL_Surface* soundicon=NULL ;
SDL_Surface* soundicon1=NULL ;
    SDL_Event event;
    SDL_Rect positionecran;
    TTF_Font *police=NULL;
    SDL_Color couleur= {240,0, 0};
    int continuer=1,x,y;
    Initback(&b)   ;
    positionecran.x=0;
    positionecran.y=0;
int i=MIX_MAX_VOLUME/2 ;
    Mix_VolumeMusic(i);
int done=1 ;
int posscrollbutton ;
int copied=0;
int x1=0;
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Erreur lors de l'initialisation de la SDL : %s",SDL_GetError());
        return (1);
    }
    TTF_Init();
    screen = SDL_SetVideoMode(1600,1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    if (screen == NULL)
    {
        printf("Erreur lors du placement du mode video : %s",SDL_GetError());
        return (1);
    }
    SDL_WM_SetCaption("jeu", NULL);
  play=IMG_Load("play.png");
 settings=IMG_Load("option.png");
 exit=IMG_Load("exit.png");
 play1=IMG_Load("play1.png");
 settings1=IMG_Load("option1.png");
 exit1=IMG_Load("exit1.png");
 play_motion=IMG_Load("play motion.png") ;
option_motion=IMG_Load("option motion.png") ;
exit_motion=IMG_Load("exit motion.png") ;


display=IMG_Load("display.png") ; 
backtomain=IMG_Load("backtomain.png") ;
controller=IMG_Load("controller.png") ;

bar=IMG_Load("bar.png") ;
bar1=IMG_Load("bar.png");
scrollbutton=IMG_Load("scrollbutton.png") ;
scrollbutton1=IMG_Load("scrollbutton.png") ;

sound_setting=IMG_Load("sound setting.png") ;
fullscreen=IMG_Load("fullscreen.png") ;
soundicon=IMG_Load("soundicon.png");
soundicon1=IMG_Load("soundicon1.png") ;

/*init_affiche("menu.jpg",image1);
init_affiche("option.png",play);
init_affiche("option1.png",settings);
init_affiche("exit.png",exit);
init_affiche("exit1.png",exit1);
init_affiche("play motion.png",play_motion);*/

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",Mix_GetError());
    }
    music=Mix_LoadMUS("son.mp3");
    Mix_PlayMusic(music, -1);
    son1 = Mix_LoadWAV("son1.wav");
    police = TTF_OpenFont("samurai.ttf", 30);
    texte = TTF_RenderText_Blended(police, "The Rising Of the Ancient Heroes ", couleur);

                if(Mix_PlayChannel(-1,son1,0)==-1)
                {
                    return 1;
                }
b.etat=0;

    while (continuer)
    {//gameloop start
if(done==1){
      switch(b.etat)
 { case 0:
  afficherback (&b ,screen);
  affiche(0,200,screen,play);
  affiche(0,350,screen,settings);
  affiche(0,500,screen,exit);
  affiche(30,170,screen,texte);
  done=0;
   break;
  case 1:
  afficherback (&b ,screen);
  affiche(75,100,screen,sound_setting);
  //affiche(75,200,screen,minus);
  //affiche(820,200,screen,plus);
  affiche(50,500,screen,display);
  
  affiche(0,800,screen,backtomain);
  affiche(220,220,screen,bar);//width 608 height 38
 //affiche(180,220,screen,soundicon);
  //affiche(220,300,screen,bar1);
 //affiche(180,300,screen,soundicon1);
 affiche(x,200,screen,scrollbutton);  
// affiche(x,300,screen,scrollbutton1);
 affiche(50,600,screen,fullscreen);
  //affiche(300,200,screen,scrollbutton);
 done=0;
  break;
 case 2:
   afficherback(&b,screen);
   done=0;
   break;
   }//switch
}
      /*SDL_WaitEvent(&event);*/
while(SDL_PollEvent(&event)!=0) {
      switch (event.type)  {
        case SDL_MOUSEMOTION:
                   x=event.motion.x;
                   y=event.motion.y;

                   switch(b.etat)
                     { case 0:      
                    if(x>0 && x<300 && y>200 && y<317 ){
                        
                        affiche(1000,1000,screen,play);
                        affiche(0,200,screen,play_motion);
                          SDL_Flip(screen);           
                     }
else {
affiche(1000,1000,screen,play_motion);
affiche(0,200,screen,play);
SDL_Flip(screen);
}
                    
if(x>0 && x<300 && y>350 && y<467 ){
                         affiche(1000,1000,screen,settings);       
                        affiche(0,350,screen,option_motion);
                      SDL_Flip(screen);
                     }
else {
affiche(1000,1000,screen,option_motion);       
affiche(0,350,screen,settings);
SDL_Flip(screen);
}
if(x>0 && x<300 && y>500 && y<617 ){
                     affiche(1000,1000,screen,exit);   
                     affiche(0,500,screen,exit_motion);
                                          
                     }//if
else {
affiche(1000,1000,screen,exit_motion);       
affiche(0,500,screen,exit);
SDL_Flip(screen);
}
case 1 :
if(x>220 && x<250 && y>220 && y<220+38 && event.button.button==SDL_BUTTON_LEFT){

affiche(x,200,screen,scrollbutton);  
done=1;                                
                       }
if(x>220 && x<250 && y>300 && y<300+38 && event.button.button==SDL_BUTTON_LEFT){

affiche(x,300,screen,scrollbutton1);  
done=1;   
                            
                       }
break;
                   }//switch
                    
                case SDL_MOUSEBUTTONDOWN:
                    x = event.button.x;
                    y = event.button.y;
                    
                    switch(b.etat)
                 { case 0:
if(x>0 && x<300 && y>200 && y<317 && event.button.button==SDL_BUTTON_LEFT){
                        affiche(0,200,screen,play1);
                       
                    }//if rect
if(x>0 && x<300 && y>350 && y<467 ){
                        affiche(0,350,screen,settings1);
                         
                       }
                      break;
                      case 1:
if(x>220 && x<220+608 && y>220 && y<220+38 && event.button.button==SDL_BUTTON_LEFT){

affiche(x,200,screen,scrollbutton);
Mix_VolumeMusic(x-300);  
done=1;                                
                       }
break;
}//switch
                    break;
                case SDL_MOUSEBUTTONUP:
                    x = event.button.x;
                    y = event.button.y;
                    switch(b.etat)
                 { case 0:
                    if(x>0 && x<300 && y>200 && y<317 && event.button.button==SDL_BUTTON_LEFT){
                        
                        affiche(0,200,screen,play_motion);
if(x>0 && x<300 && y>200 && y<317 && event.button.button==SDL_BUTTON_LEFT){
                        b.etat=2;
                       done=1;
                    }
                    case 1:
                     if(x>0 && x<589 && y>800 && y<890 )
                   {
                      b.etat=0;
                      done=1;
                   }
                     if(x>50 && x<300+589 && y>600 && y<600+90 )
                     {
                     
SDL_WM_ToggleFullScreen(screen);
done=1;
                     }
                    }//switch
                       if(x>0 && x<300 && y>350 && y<467 )
                     {
                     b.etat=1;
                     done=1;
                     }
                  }//switch
                    continue;
        case SDL_QUIT:        
           continuer=0;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_e:
                switch(b.etat)
                 {
                case 0 : affiche(1000,1000,screen,exit);
                  affiche(0,500,screen,exit1);
                  
                   if(Mix_PlayChannel(-1,son1,0)==-1)
                {
                    return 1;
                }//
                  }
                continue;
            case SDLK_p:
              
                 switch(b.etat)
                 {
                case 0 : affiche(1000,1000,screen,play);
                          affiche(0,200,screen,play1);
                      
                       if(Mix_PlayChannel(-1,son1,0)==-1)
                {
                    return 1;
                }//
                  }//switch
                     
                continue;
            case SDLK_o:
                  switch(b.etat)
                 {
                    case 0: affiche(1000,1000,screen,settings);
                     affiche(0,350,screen,settings1);           
                      if(Mix_PlayChannel(-1,son1,0)==-1)
                      {
                      return 1;
                      }//
                   
                }//switch
                continue;
             
        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
            case SDLK_e:
                continuer=0;
                break;
            case SDLK_o:
                

 switch(b.etat)
                 { case 0:
             affiche(1000,1000,screen,settings1);
             affiche(0,350,screen,settings);
                
               b.etat=1;
               done=1;
              }//switch
           
           
           
                continue;
            case SDLK_p:
               
   switch(b.etat)
                 { case 0:affiche(1000,1000,screen,play1);
                affiche(0,200,screen,play);               
                
                 }//switch
            case SDLK_KP_MINUS :
  switch(b.etat)
                 { case 1:
             // i le volume 
i=i-10;
Mix_VolumeChunk(son1,i);
 Mix_PlayChannel(-1,son1, i);
         done=1;
           }//switch
             break;
            
            case SDLK_KP_PLUS :
switch(b.etat)
                 { case 1:
            i=i+10;
Mix_VolumeChunk(son1,i);
 Mix_PlayChannel(-1,son1, i);
                   }//switch
             break;

            default:
                continue;
            }
                continue;
            default:
                continue;
            }

        
        }
     }
       

  

    SDL_Flip(screen);   

    }//gameloop
freeback(&b) ;
    Mix_FreeMusic(music);
    Mix_FreeChunk(son1);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}
