LIB = -L ~/SDL/lib
INCLUDE = -I ~/SDL/include

all:LGDG.out

LGDG.out: main.o listes_ptr.o ges_equipes.o classes.o ges_partie.o Init_map.o file_chemin.o deplacement_simp.o save.o
	export LD_LIBRARY_PATH=~/SDL 
	gcc $^ -o $@ ${LIB} ${INCLUDE} -lSDL2 -lSDL2_ttf -lm

main.o: main.c global.h
	gcc -c $< ${INCLUDE} -g -W

ges_equipes.o: ges_equipes.c global.h
	gcc -c $< ${INCLUDE} -g -W

listes_ptr.o: listes_ptr.c global.h
	gcc -c $< ${INCLUDE} -g -W

classes.o: classes.c global.h
	gcc -c $< ${INCLUDE} -g -W

ges_partie.o: ges_partie.c global.h
	gcc -c $< ${INCLUDE} -g -W
 
Init_map.o: Init_map.c global.h
	gcc -c $< ${INCLUDE} -g -W

file_chemin.o: file_chemin.c global.h
	gcc -c $< ${INCLUDE} -g -W
	
deplacement_simp.o: deplacement_simp.c global.h 
	gcc -c $< ${INCLUDE} -g -W

save.o: save.c global.h 
	gcc -c $< ${INCLUDE} -g -W

clean: 
	rm -rf *.~ *.o 

mrroper: clean
