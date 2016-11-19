/**
*\file Init_map.c
*\brief Création de la map
*\version 1.0
*\author Victor Morgant  Martin Lebourdais
*\date 14/11/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"

#define couleur(param) printf("\033[%sm",param)
/*   param devant être un const char *, vide (identique à "0") ou formé
     d'une où plusieurs valeurs séparées par des ; parmi
         0  réinitialisation         1  haute intensité (des caractères)
         5  clignotement             7  video inversé
         30, 31, 32, 33, 34, 35, 36, 37 couleur des caractères
         40, 41, 42, 43, 44, 45, 46, 47 couleur du fond
         les couleurs, suivant la logique RGB, étant respectivement
         noir, rouge, vert, jaune, bleu, magenta, cyan et blanc */

t_map creerMat(){
	/*Initialisation de la matrice map à 0*/
    t_map matrice;
    int i, j;
    matrice.cell = (int**) malloc(10 * sizeof(int*));
    for (i=0; i < 10; i++){
        matrice.cell[i] = (int*) malloc(10 * sizeof(int));
        for (j=0; j < 10; j++){    	
        	matrice.cell[i][j] = 0;
        }
            
    }
    return matrice;
}

t_map actumap(t_liste * ordre_action, t_map map){
   //Fontion qui actualise la map en place le perso de l'élement courant
       	 
    
    if (ordre_action->ec->personnage.joueur == 1){     
        		if (ordre_action->ec->personnage.classe.nom == "Saber") map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 1; // On place le personnage de la classe indiquée dans l'élément courant à ses coordonées dans la matrice.
        	}
    if (ordre_action->ec->personnage.joueur == 2){
        		if (ordre_action->ec->personnage.classe.nom == "Saber") map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 2;
        	}
    
    return map;
}





void afficherMat (t_map mat){
    int i, j;
    clearScreen();					 //Effacer le terminal
    mat.cell[1][1]=2;
    mat.cell[1][1]=1;
    for (i=0; i < 10; i++){
	    printf("|");
	    for (j=0; j < 10; j++){
	    	if(mat.cell[i][j] == 0) printf(" --- "); 
	    	if(mat.cell[i][j] == 1) {				 //Si la case contient une "Saber" Bleue
	    		couleur("34;1");					 //On écrit en bleu et en gras
	    		printf(" SAB ");					
	    		couleur("0");						 //On réinitialise le système de couleur
	    		
	    	}
	    	if(mat.cell[i][j] == 2) {				 //Si la case contient une "Saber" Rouge
	    		couleur("31;1");					 //On écrit en rouge et en gras
	    		printf(" SAB ");
	    		couleur("0");
	    	}
			
	    }
	printf("|\n");
    }
        printf("\n");
}