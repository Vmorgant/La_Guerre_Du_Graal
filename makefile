LIB = -L ~/SDL/lib
INCLUDE = -I ~/SDL/include

all:LGDG.out

LGDG.out: main.o listes_ptr.o ges_equipes.o classes.o ges_partie.o Init_map.o file_chemin.o deplacement_simp.o save.o
	export LD_LIBRARY_PATH=~/SDL 
	gcc $^ -o $@ ${LIB} ${INCLUDE} -lSDL2 -lSDL2_ttf -lm

main.o: ./sources/main.c ./includes/global.h
	gcc -c $< ${INCLUDE} -g -W

ges_equipes.o: ./sources/ges_equipes.c ./includes/global.h
	gcc -c $< ${INCLUDE} -g -W

listes_ptr.o: ./sources/listes_ptr.c ./includes/global.h
	gcc -c $< ${INCLUDE} -g -W

classes.o: ./sources/classes.c ./includes/global.h
	gcc -c $< ${INCLUDE} -g -W

ges_partie.o: ./sources/ges_partie.c ./includes/global.h
	gcc -c $< ${INCLUDE} -g -W
 
Init_map.o: ./sources/Init_map.c ./includes/global.h
	gcc -c $< ${INCLUDE} -g -W

file_chemin.o: ./sources/file_chemin.c ./includes/global.h
	gcc -c $< ${INCLUDE} -g -W
	
deplacement_simp.o: ./sources/deplacement_simp.c ./includes/global.h 
	gcc -c $< ${INCLUDE} -g -W

save.o: ./sources/save.c ./includes/global.h 
	gcc -c $< ${INCLUDE} -g -W

clean: 
	rm -rf *.~ *.o 

mrroper: clean
