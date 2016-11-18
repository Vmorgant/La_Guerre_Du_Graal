all:LGDG
LGDG: main.o listes_ptr.o ges_equipes.o classes.o
	gcc -o LGDG main.o listes_ptr.o ges_equipes.o classes.o -lncurses

main.o: main.c global.h 
	gcc  -c main.c global.h -lncurses -g -W  

ges_equipes.o: ges_equipes.c global.h
	gcc -c ges_equipes.c global.h -g -W

listes_ptr.o: listes_ptr.c global.h
	gcc -c listes_ptr.c global.h -g -W 

classes.o: classes.c global.h
	gcc -c classes.c global.h -g -W

ges_partie.o: ges_partie.c global.h
	gcc -c ges_partie.c global.h -g -W

Init_map.o: Init_map.c global.h
	gcc -c Init_map.c global.h -g -W

liste_chemin.o: liste_chemin.c global.h
	gcc -c liste_chemin.c global.h -g -W
	
deplacement.o: deplacement.c global.h
	gcc -c deplacement.c global.h -g -W

clean: 
	rm -f *.~ *.o 

mrroper: clean