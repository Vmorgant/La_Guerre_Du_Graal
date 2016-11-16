all:LGDG
LGDG: main.o listes_ptr.o actions.o classes.o
	gcc -o LGDG main.o listes_ptr.o classes.o

main.o: main.c global.h 
	gcc -c main.c global.h -g -W  

listes_ptr.o: listes_ptr.c global.h
	gcc -c listes_ptr.c global.h -g -W 

classes.o: classes.c global.h
	gcc -c classes.c global.h -g -W

clean: 
	rm -f *.~ *.o 
