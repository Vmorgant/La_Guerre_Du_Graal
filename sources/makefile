all:LGDG.out
LGDG.out: main.o listes_ptr.o ges_equipes.o classes.o ges_partie.o Init_map.o liste_chemin.o deplacement_simp.o
	gcc -o LGDG.out main.o listes_ptr.o ges_equipes.o classes.o ges_partie.o Init_map.o liste_chemin.o deplacement_simp.o -lncurses

main.o: main.c global.h 
	gcc  -c main.c global.h -lncurses -g -W  

ges_equipes.o: ges_equipes.c global.h
	gcc -c ges_equipes.c global.h -lm  -g -W

listes_ptr.o: listes_ptr.c global.h
	gcc -c listes_ptr.c global.h -lm  -g -W 

classes.o: classes.c global.h
	gcc -c classes.c global.h -lm  -g -W

ges_partie.o: ges_partie.c global.h
	gcc -c ges_partie.c global.h -lm  -g -W

Init_map.o: Init_map.c global.h
	gcc -c Init_map.c global.h -lm -g -W

liste_chemin.o: liste_chemin.c global.h
	gcc -c liste_chemin.c global.h -lm  -g -W
	
deplacement_simp.o: deplacement_simp.c global.h
	gcc -c deplacement_simp.c global.h -lm  -g -W

clean: 
	rm -rf *.~ *.o 

mrroper: clean
