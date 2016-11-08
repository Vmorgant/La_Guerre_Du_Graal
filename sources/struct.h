#include <stdio.h>
#include <stdlib.h>

typedef struct t_pile;
typedef enum t_bool;
typedef struct t_file;

void initpile(t_pile pile);
void depiler(t_pile pile; int *i);
int pilevide(t_pile pile);

void initfile(t_file file);
void ajouter(t_file file; int i);
void retirer(t_file file; int *i);
int filevide(t_file file);


