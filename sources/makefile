/**
*\file makefile
*\brief Compilation séparée des fichiers
*
*\author Lebourdais Martin
*\date 14/11/2016
*/

all:LGDG
LGDG: main.o list_ptr.o actions.o classes.o global.h
	gcc -o LGDG main.o list_ptr.o actions.o classes.o global.h 
main.o:main.c global.h 
	gcc -c maxi.c global.h -g -W  
list_ptr.o:list_ptr.c global.h
	gcc -c list_ptr.c global.h -g -W 
actions.o:actions.c global.h
  gcc -c actions.c global.h -g -W
classes.o:classes.c global.h
  gcc -c classes.c global.h -g -W

clean: 
	rm -f *.~ *.o 
