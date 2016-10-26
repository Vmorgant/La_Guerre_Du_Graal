/** Définition de différente structures utiles et fonctions associées

Booleen
Pile
File

*/
#include <stdio.h>
#include <stdlib.h>

/**Booléen*/

typedef enum{faux,vrai} t_bool;


/**Pile*/
int taille,sommet;
int tab[taille];

typedef struct {int taille;int tab[taille];int sommet} t_pile;

void initpile(t_pile pile){
    pile.sommet=-1;
}
void empiler(t_pile pile; int i){
    if (pile.sommet<pile.taille){
        (pile.sommet)++;
        pile.tab[pile.sommet] = i;
    }
    else
        printf("erreur la pile est pleine");
}

void depiler(t_pile pile; int *i){
    if (pile.sommet>-1){

        *i= tab[pile.sommet];
        (pile.sommet)--;
    }
     else
        printf("erreur la pile est vide")
}

int pilevide(t_pile pile){
    return(pile.sommet == -1);
}

/**File*/
int taille,nb_valeurs,tete,queue;
typedef struct {int taille;int tab[taille];int nb_valeurs;int tete;int queue} t_file;

void initfile(t_file file){
   file.nb_valeurs =0;
   tete=0;
   queue=taille-1;
}
void ajouter(t_file file; int i){
    if (file.nb_valeurs<file.taille){

        if (file.queue== taille-1)
                file.queue=0;
        else
            file.queue++;
        file.tab[file.sommet] = i;
        file.nb_valeurs++;
    }
    else
        printf("erreur la file est pleine")
}


void retirer(t_file file; int *i){
    if (file.nb_valeurs> 0){

        *i= file.tab[file.tete];
        file.nb_valeurs--;
        if(file.tete == file.taille-1)
            file.tete=0;
        else
            tete++;
    }
    else
        printf("erreur la file est vide")
}

int filevide(t_file file){
    return(file.nb_valeurs == file.taille);
}
