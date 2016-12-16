CC = gcc -c
all: run

run: LGDG.out clean
	printf '\e[8;100;300t'
	./LGDG.out
	printf '\e[8;30;100t'
	clear

LGDG.out: main.o listes_ptr.o ges_equipes.o classes.o ges_partie.o Init_map.o file_chemin.o deplacement_simp.o save.o
	gcc -o $@ $^ -lm

main.o: ./sources/main.c ./includes/global.h 
	${CC} $^ -g -W  

ges_equipes.o: ./sources/ges_equipes.c ./includes/global.h
	${CC} $^ -g -W

listes_ptr.o: ./sources/listes_ptr.c ./includes/global.h
	${CC} $^ -g -W 

classes.o: ./sources/classes.c ./includes/global.h
	${CC} $^ -g -W

ges_partie.o: ./sources/ges_partie.c ./includes/global.h
	${CC} $^ -g -W

Init_map.o: ./sources/Init_map.c ./includes/global.h
	${CC} $^ -W

file_chemin.o: ./sources/file_chemin.c ./includes/global.h
	${CC} $^ -g -W
	
deplacement_simp.o: ./sources/deplacement_simp.c ./includes/global.h 
	${CC} $^ -g -W -lm

save.o: ./sources/save.c ./includes/global.h 
	${CC} $^ -g -W

clean: 
	rm -rf *.~ *.o 


