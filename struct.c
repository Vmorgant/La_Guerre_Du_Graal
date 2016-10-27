#include "Outil.h"
#define TMAX 30
/** Définition de différente structures utiles et fonctions associées

Booleen
Pile
File

*/


/**Booléen*/

typedef enum{faux,vrai} t_bool;


/**Pile*/

typedef struct {int tab[TMAX];int sommet;} t_pile;

void initpile(t_pile pile){
    pile.sommet=-1;
}
void empiler(t_pile pile, int i){
    if (pile.sommet<TMAX-1){
        (pile.sommet)++;
        pile.tab[pile.sommet] = i;
    }
    else
        printf("erreur la pile est pleine");
}

void depiler(t_pile pile, int *i){
    if (pile.sommet>-1){

        *i= pile.tab[pile.sommet];
        (pile.sommet)--;
    }
     else
        printf("erreur la pile est vide");
}

int pilevide(t_pile pile){
    return(pile.sommet == -1);
}

/**File*/

typedef struct {int tab[TMAX];int tete; int queue;int nb_valeurs;} t_file;

void initfile(t_file file){
   file.nb_valeurs =0;
   file.tete=0;
   file.queue=TMAX-1;
}
void ajouter(t_file file, int i){
    if (file.nb_valeurs<TMAX){

        if (file.queue== TMAX-1)
                file.queue=0;
        else
            file.queue++;
        file.tab[file.queue] = i;
        file.nb_valeurs++;
    }
    else
        printf("erreur la file est pleine");
}


void retirer(t_file file, int *i){
    if (file.nb_valeurs> 0){

        *i= file.tab[file.tete];
        file.nb_valeurs--;
        if(file.tete == TMAX-1)
            file.tete=0;
        else
            file.tete++;
    }
    else
        printf("erreur la file est vide");
}

int filevide(t_file file){
    return(file.nb_valeurs == 0);
}
