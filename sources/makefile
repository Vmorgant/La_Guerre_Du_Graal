all:LGDG.out
LGDG.out: main.o listes_ptr.o ges_equipes.o classes.o ges_partie.o Init_map.o file_chemin.o deplacement_simp.o
	gcc -o LGDG.out main.o listes_ptr.o ges_equipes.o classes.o ges_partie.o Init_map.o file_chemin.o deplacement_simp.o -lncurses -lm

main.o: main.c global.h 
	gcc  -c main.c global.h -lncurses -g -W  

ges_equipes.o: ges_equipes.c global.h
	gcc -c ges_equipes.c global.h  -g -W

listes_ptr.o: listes_ptr.c global.h
	gcc -c listes_ptr.c global.h  -g -W 

classes.o: classes.c global.h
	gcc -c classes.c global.h  -g -W

ges_partie.o: ges_partie.c global.h
	gcc -c ges_partie.c global.h  -g -W

Init_map.o: Init_map.c global.h
	gcc -c Init_map.c global.h  -W

file_chemin.o: liste_chemin.c global.h
	gcc -c file_chemin.c global.h  -g -W
	
deplacement_simp.o: deplacement_simp.c global.h 
	gcc -c deplacement_simp.c global.h  -g -W -lm

clean: 
	rm -rf *.~ *.o 

mrroper: clean
