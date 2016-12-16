/**
*\file Init_map.c
*\brief Ce fichier contient les fonctions permettant la création de la map
*\version 1.0
*\author Victor Morgant  Martin Lebourdais Corentin Petit
*\date 14/11/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/global.h"
#include "../includes/listes_ptr.h"

t_map creerMat(){
/**
 * \fn creerMat()
 * \brief Fonction initialisant la matrice 10/10
 * \return une matrice d'entier remplie de 0
 */
    t_map matrice;
    int i, j;
    matrice.nlignes = 10;
    matrice.ncolonnes = 10;

    matrice.cell = (int**) malloc( matrice.nlignes * sizeof(int*));
    for (i=0; i < matrice.nlignes; i++){
        matrice.cell[i] = (int*) malloc(matrice.ncolonnes * sizeof(int));
        for (j=0; j < matrice.ncolonnes; j++){    	
        	matrice.cell[i][j] = 0;
		assert(matrice.cell[i][j] == 0); 
        }
            
    }
	
    return matrice;
}

t_map actumap(t_liste * ordre_action, t_map map){
/**
 * \fn actumap(t_liste * ordre_action, t_map map)
 * \brief  Fontion qui actualise la map en placant les indices des personnages aux bonnes coordonnées de la matrice
* \param t_liste * ordre_action la liste des personnages triée t_map map une matrice d'entier .
 * \return une matrice d'entier avec les indices des personnages à leurs coordonnées
 */
   t_element * tampon = ordre_action->ec;
   t_personnage persoc;
   int i, j;

   /* réinitialisation de la map */
   for (i=0; i < map.nlignes; i++){
        for (j=0; j < map.ncolonnes; j++)  	
        	map.cell[i][j] = 0;
   }

   /*placement des indices sur la map en fonction des positions des personnages */
   en_tete(ordre_action);
   while(!hors_liste(ordre_action)){
	valeur_elt(ordre_action, &persoc);
	if( (persoc.x != -1) && (persoc.y != -1) ) {
	    if (persoc.joueur == 1){     
				if (!strcmp(persoc.classe.nom ,"Saber")) map.cell[persoc.x][persoc.y] = 1;
				else if (!strcmp(persoc.classe.nom ,"Archer")) map.cell[persoc.x][persoc.y] = 3;
				else if (!strcmp(persoc.classe.nom ,"Caster")) map.cell[persoc.x][persoc.y] = 5;
				else if (!strcmp(persoc.classe.nom ,"Berserker")) map.cell[persoc.x][persoc.y] = 7;
				else if (!strcmp(persoc.classe.nom ,"Lancer")) map.cell[persoc.x][persoc.y] = 9;
				else if (!strcmp(persoc.classe.nom ,"Rider")) map.cell[persoc.x][persoc.y] = 11;
				else if (!strcmp(persoc.classe.nom ,"Assassin")) map.cell[persoc.x][persoc.y] = 13;
	    } else if (persoc.joueur == 2){
				if (!strcmp(persoc.classe.nom ,"Saber")) map.cell[persoc.x][persoc.y] = 2;
				else if (!strcmp(persoc.classe.nom ,"Archer")) map.cell[persoc.x][persoc.y] = 4;
				else if (!strcmp(persoc.classe.nom ,"Caster")) map.cell[persoc.x][persoc.y] = 6;
				else if (!strcmp(persoc.classe.nom ,"Berserker")) map.cell[persoc.x][persoc.y] = 8;
				else if (!strcmp(persoc.classe.nom ,"Lancer")) map.cell[persoc.x][persoc.y] = 10;
				else if (!strcmp(persoc.classe.nom ,"Rider")) map.cell[persoc.x][persoc.y] = 12;
				else if (!strcmp(persoc.classe.nom ,"Assassin")) map.cell[persoc.x][persoc.y] = 14;

	    }
	}

	    suivant(ordre_action);
    }

    ordre_action->ec = tampon;
   
    return map;
}





void afficherMat (t_map mat){
/**
 * \fn afficherMat (t_map mat)
 * \brief  Fontion qui affiche la carte dans le terminal en placant les trois premières lettre du nom de la classe à la case contenant l'indice correspondant
* \param t_liste * ordre_action la liste des personnages triée t_map map une matrice d'entier .
 */
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


void free_map(t_map map){
/**
 * \fn free_map(t_map map)
 * \brief  Fontion qui libère la mémoire utilisée par la carte.
* \param t_map map une matrice d'entier .
 */
	int i, j;
	for (i=0; i < map.nlignes; i++){
		free(map.cell[i]);
  	}
}
