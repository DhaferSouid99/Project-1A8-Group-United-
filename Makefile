prog:menu.o background.o affiche.o initimage.o
	gcc  menu.o background.o affiche.o initimage.o -o prog -g -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
menu.o:menu.c
	gcc -c menu.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
affiche.o:affiche.c
	gcc -c affiche.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
background.o:background.c
	gcc -c background.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
initimage.o:initimage.c
	gcc -c initimage.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf

