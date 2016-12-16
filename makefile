all: run

run: LGDG.out clean
	printf '\e[8;100;300t'
	./LGDG.out
	printf '\e[8;30;100t'
	clear

LGDG.out: main.o listes_ptr.o ges_equipes.o classes.o ges_partie.o Init_map.o file_chemin.o deplacement_simp.o save.o
	gcc -o LGDG.out main.o listes_ptr.o ges_equipes.o classes.o ges_partie.o Init_map.o file_chemin.o deplacement_simp.o save.o -lm

main.o: sources/main.c includes/global.h 
	gcc  -c ./sources/main.c ./includes/global.h -lncurses -g -W  

ges_equipes.o: sources/ges_equipes.c includes/global.h
	gcc -c ./sources/ges_equipes.c ./includes/global.h  -g -W

listes_ptr.o: sources/listes_ptr.c includes/global.h
	gcc -c ./sources/listes_ptr.c ./includes/global.h  -g -W 

classes.o: sources/classes.c includes/global.h
	gcc -c ./sources/classes.c ./includes/global.h  -g -W

ges_partie.o: sources/ges_partie.c includes/global.h
	gcc -c ./sources/ges_partie.c ./includes/global.h  -g -W

Init_map.o: sources/Init_map.c includes/global.h
	gcc -c ./sources/Init_map.c ./includes/global.h  -W

file_chemin.o: sources/file_chemin.c includes/global.h
	gcc -c ./sources/file_chemin.c ./includes/global.h  -g -W
	
deplacement_simp.o: sources/deplacement_simp.c includes/global.h 
	gcc -c ./sources/deplacement_simp.c ./includes/global.h  -g -W -lm

save.o: sources/save.c includes/global.h 
	gcc -c ./sources/save.c ./includes/global.h  -g -W

clean: 
	rm -rf *.~ *.o 

mrroper: clean
