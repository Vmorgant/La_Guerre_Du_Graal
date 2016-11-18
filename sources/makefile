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

clean: 
	rm -f *.~ *.o 

mrroper: clean