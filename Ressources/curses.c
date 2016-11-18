// Se compile par exemple avec gcc cursef.c -lcurses && ./a.out

#include <curses.h> 
#include <string.h>

int l, c;              // ligne, colonne ((0,0) en haut à gauche)
int count[128], total; // à 0; comptage des mots de chaque longueur

int main()
{ 
  WINDOW* win;
  FILE* infile;
  char d, xxx[128], out[128];
  infile = fopen("/usr/share/dict/french", "r"); // Dictionnaire
  
  win = initscr(); // Initialisation
  cbreak();        // Ne pas exiger ENTER
  noecho();        // Pas d'écho demandé
  clear();         // Fenêtre à blanc
  refresh();       // Exécution de ce qui a été préparé dans la fenêtre

  int octets, glyphes; // En unicode, quelques glyphes sont multi-octets
  while (!feof(infile))
  { 
    fgets(xxx, 100,infile);
    octets=0; glyphes=0; // Bidouillage pour unicode

    while (xxx[octets])
    { 
      if ((xxx[octets] & 0xC0) != 0x80 ) ++glyphes;
      ++octets;
    }
  
    --glyphes; ++count[glyphes]; // négliger retour ligne
    sprintf(out, "%7d %s", count[glyphes], xxx);
    move(glyphes-1,0);
    addstr(out); // préparer la ligne dans la fenêtre
    refresh();   // afficher la fenêtre

    ++total;
  }

  sprintf(out, "%7d mots au total", total);
  move (26,0); addstr(out); refresh();
  d=getch();   // Attente d'un caractère pour effacer fenêtre et sortir

  endwin();    // curses call to restore the original window and leave
}
