/**
*\file Init_map.c
*\brief Création de la map
*\version 1.0
*\author Victor Morgant  Martin Lebourdais Corentin Petit
*\date 14/11/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "listes_ptr.h"

t_map creerMat(){
	/*Initialisation de la matrice map à 0*/
    t_map matrice;
    int i, j;
    matrice.nlignes = 10;
    matrice.ncolonnes = 10;

    matrice.cell = (int**) malloc( matrice.nlignes * sizeof(int*));
    for (i=0; i < matrice.nlignes; i++){
        matrice.cell[i] = (int*) malloc(matrice.ncolonnes * sizeof(int));
        for (j=0; j < matrice.ncolonnes; j++){    	
        	matrice.cell[i][j] = 0;
        }
            
    }
    return matrice;
}

t_map actumap(t_liste * ordre_action, t_map map){
   //Fontion qui actualise la map
   t_element * tampon = ordre_action->ec;
   int i, j;

   for (i=0; i < map.nlignes; i++){
        for (j=0; j < map.ncolonnes; j++)  	
        	map.cell[i][j] = 0;
   }

   en_tete(ordre_action);
   while(!hors_liste(ordre_action)){
	if( (ordre_action->ec->personnage.x != -1) && (ordre_action->ec->personnage.y != -1) ) {
	    if (ordre_action->ec->personnage.joueur == 1){     
				if (!strcmp(ordre_action->ec->personnage.classe.nom ,"Saber")) map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 1; // On place le personnage de la classe indiquée dans l'élément courant à ses coordonées dans la matrice.
				if (!strcmp(ordre_action->ec->personnage.classe.nom ,"Archer")) map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 3;
				if (!strcmp(ordre_action->ec->personnage.classe.nom ,"Caster")) map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 5;
				if (!strcmp(ordre_action->ec->personnage.classe.nom ,"Berserker")) map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 7;
				if (!strcmp(ordre_action->ec->personnage.classe.nom ,"Lancer")) map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 9;
				if (!strcmp(ordre_action->ec->personnage.classe.nom ,"Rider")) map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 11;
				if (!strcmp(ordre_action->ec->personnage.classe.nom ,"Assassin")) map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 13;
	    } else if (ordre_action->ec->personnage.joueur == 2){
				if (!strcmp(ordre_action->ec->personnage.classe.nom ,"Saber")) map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 2;
				if (!strcmp(ordre_action->ec->personnage.classe.nom ,"Archer")) map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 4;
				if (!strcmp(ordre_action->ec->personnage.classe.nom ,"Caster")) map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 6;
				if (!strcmp(ordre_action->ec->personnage.classe.nom ,"Berserker")) map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 8;
				if (!strcmp(ordre_action->ec->personnage.classe.nom ,"Lancer")) map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 10;
				if (!strcmp(ordre_action->ec->personnage.classe.nom ,"Rider")) map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 12;
				if (!strcmp(ordre_action->ec->personnage.classe.nom ,"Assassin")) map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 14;

	    }
	}

	    suivant(ordre_action);
    }

    ordre_action->ec = tampon;
   
    return map;
}





void afficherMat (t_map mat){
    int i, j;
	printf("x\\y");
    for (j=0;j<10;j++){
	 printf(" %i   ",j);
    }	
    printf("\n");			
    for (i=0; i < 10; i++){
	    printf("%i|",i);
	    
	    for (j=0; j < 10; j++){
		printf(" ");
	    	if(mat.cell[i][j] == 0) printf("---"); 
	    	if(mat.cell[i][j] == 1) {				 //Si la case contient une "Saber" Bleue
	    		couleur("34;1");					 //On écrit en bleu et en gras
	    		printf("SAB");					
	    		couleur("0");						 //On réinitialise le système de couleur
	    		
	    	}
	    	if(mat.cell[i][j] == 2) {				 //Si la case contient une "Saber" Rouge
	    		couleur("31;1");					 //On écrit en rouge et en gras
	    		printf("SAB");
	    		couleur("0");
	    	}
		if(mat.cell[i][j] == 4) {				 //Si la case contient une "Archer" Rouge
	    		couleur("31;1");					 //On écrit en rouge et en gras
	    		printf("ARC");
	    		couleur("0");
	    	}
		if(mat.cell[i][j] == 3) {				 //Si la case contient un "Archer" Bleu
	    		couleur("34;1");					 //On écrit en bleu et en gras
	    		printf("ARC");
	    		couleur("0");
	    	}
		if(mat.cell[i][j] == 5) {				 //Si la case contient un "Caster" Bleu
	    		couleur("34;1");					 //On écrit en bleu et en gras
	    		printf("CAS");
	    		couleur("0");
	    	}
		if(mat.cell[i][j] == 6) {				 //Si la case contient un "Caster" Rouge
	    		couleur("31;1");					 //On écrit en rouge et en gras
	    		printf("CAS");
	    		couleur("0");
	    	}
		if(mat.cell[i][j] == 7) {				 //Si la case contient un "Berzerker" Bleu
	    		couleur("34;1");					 //On écrit en bleu et en gras
	    		printf("BER");
	    		couleur("0");
	    	}
		if(mat.cell[i][j] == 8) {				 //Si la case contient un "Berzerker" Rouge
	    		couleur("31;1");					 //On écrit en Rouge et en gras
	    		printf("BER");
	    		couleur("0");
	    	}
		if(mat.cell[i][j] == 9) {				 //Si la case contient un "Lancer" Bleu
	    		couleur("34;1");					 //On écrit en bleu et en gras
	    		printf("LAN");
	    		couleur("0");
	    	}
		if(mat.cell[i][j] == 10) {				 //Si la case contient un "Lancer" Rouge
	    		couleur("31;1");					 //On écrit en Rouge et en gras
	    		printf("LAN");
	    		couleur("0");
	    	}
		if(mat.cell[i][j] == 11) {				 //Si la case contient un "Rider" Bleu
	    		couleur("34;1");					 //On écrit en bleu et en gras
	    		printf("RID");
	    		couleur("0");
	    	}
		if(mat.cell[i][j] == 12) {				 //Si la case contient un "Rider" Rouge
	    		couleur("31;1");					 //On écrit en Rouge et en gras
	    		printf("RID");
	    		couleur("0");
	    	}
		if(mat.cell[i][j] == 13) {				 //Si la case contient un "Assassin" Bleu
	    		couleur("34;1");					 //On écrit en bleu et en gras
	    		printf("ASS");
	    		couleur("0");
	    	}
		if(mat.cell[i][j] == 14) {				 //Si la case contient un "Assassin" Rouge
	    		couleur("31;1");					 //On écrit en Rouge et en gras
	    		printf("ASS");
	    		couleur("0");
	    	}
		printf(" ");	
	    }
	printf("|\n");
    }
        printf("\n");
}


