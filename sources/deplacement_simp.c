/**
*\file deplacement_simp.c
*\brief Ce fichier contient une version simplifiée des fonctions de déplacement sur la carte.
*\author Martin Lebourdais
*\version 1.0
*\date 22/11/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"
#include "liste_chemin.h"
#include "Init_map.h"

void deplacement_simp(t_liste *ordre_action,t_map map){
/**
 * \fn  deplacement_simp(t_liste *ordre_action,t_map map)
 * \brief Version simplifiée de la fonction déplacement.
 * \param t_liste *ordre_action : ordre de jeu des personnages (util pour connaître le personnage qui se déplace),t_map map : Plateau de jeu
 */
        int xobj;
        int yobj;
	printf("Rentrez des coordonnées séparées par une vigule :\n");
	scanf("%i,%i",&xobj,&yobj);
	printf("\n");
	
	while (xobj > 9 || yobj > 9 || xobj < 0 || yobj < 0 || map.cell[xobj][yobj]!=0){
	if (map.cell[xobj][yobj] != 0){															//On teste si la case est vide
			printf("La case est déjà occupée\n");
			printf("Rentrez des coordonnées séparées par une vigule :\n");
			scanf("%i,%i", &xobj, &yobj);
			printf("\n");
		}
		else {
			printf("Les coordonnées doivent-être des entiers compris entre 0 et 9\n");
			printf("Rentrez des coordonnées séparées par une vigule :\n");
			scanf("%i,%i", &xobj, &yobj);
			printf("\n");
		}
	}
	
	ordre_action->ec->personnage.x = xobj;
	ordre_action->ec->personnage.y = yobj;
	map=actumap(ordre_action, map);
	printf("Perso n°1 [%i,%i]=%i \n",xobj,yobj,map.cell[xobj][yobj]) ;
	afficherMat(map);
}
