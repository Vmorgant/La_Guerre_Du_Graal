/**
*\file file_chemin.c
*\brief Ce fichier contient les primitives d'acces aux files de noeuds
*\author Martin Lebourdais
*\version 2.0
*\date 01/12/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "file_chemin.h"


int tete,queue,nb_valeurs;
t_noeud tab[50];

void initfile(){
   nb_valeurs = 0;
   tete=0;
   queue=49;
}
void ajouter(t_noeud i){
    if (nb_valeurs<50){

        if (queue == 49)
                queue=0;
        else
            queue=queue +1;
        tab[queue] = i;
        nb_valeurs=nb_valeurs +1;
    }
    else
        printf("erreur la file est pleine");
}


void retirer(t_noeud *i){
    if (nb_valeurs> 0){

        *i= tab[tete];
        nb_valeurs = nb_valeurs -1;
        if(tete == 49)
            tete=0;
        else
            tete = tete +1;
    }
    else
        printf("erreur la file est vide");
}

int filevide(){
    return(nb_valeurs == 0);
}
