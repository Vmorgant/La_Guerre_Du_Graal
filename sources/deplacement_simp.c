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
#include "file_chemin.h"
#include "Init_map.h"
#include <time.h>
#include <assert.h>
#include <string.h>




float distance(int x,int y,int objx,int objy){
/**
 * \fn  distance(int x,int y,int objx,int objy)
 * \brief Calcule le carré de la distance entre le point de départ et l'objectif
 * \param int x : Abscisse de départ, int y : Ordonnée de départ, int xobj : Abscisse cible; int yobj : Ordonnée cible
 */
float distance = sqrt(((float)objx-(float)x)*((float)objx-(float)x)+((float)objy-(float)y)*((float)objy-(float)y));
	
	return distance;
}


int pathfinding(int x, int y,int objx,int objy,t_noeud chemin[50],int * taille,t_map map){
/**
 * \fn  pathfinding(int x, int y,int objx,int objy)
 * \brief Trouve le chemin le plus court entre le point de départ et l'objectif et retourne ce chemin dans une file.
 * \param int x : Abscisse de départ, int y : Ordonnée de départ, int xobj : Abscisse cible; int yobj : Ordonnée cible
 */

	t_noeud depart = {x,y,0,0};
	t_noeud v3 = {x,y,0,0};
	t_noeud v1 = {x,y,0,0};
	t_noeud v2 = {x,y,0,0};
	t_noeud v4 = {x,y,0,0};
	int dep = 0;
	t_noeud tampon;
	if (depart.x != 0)
		v3.x = x-1;
	if (depart.x != map.nlignes-1)	
		v1.x = x+1;
	if (depart.y != map.ncolonnes-1)
		v2.y = y+1;
	if (depart.y != 0)
		v4.y = y-1;
	
	
	int tete,queue,nb_valeurs;
	
	
	while ((depart.x != objx || depart.y != objy) && dep < 50){
		
		
			if (map.cell[v1.x][v1.y] == 0 && (distance(v1.x,v1.y,objx,objy) < distance(depart.x,depart.y,objx,objy))){	
				
					tampon = v1;
					if (v1.x != map.nlignes-1) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v1.y != map.ncolonnes-1) {
						v2.x = tampon.x;
						v2.y = tampon.y+1;
					}
					if (v1.x != 0) {
						v3.x = tampon.x-1;
						v3.y = tampon.y;
					}
					if (v1.y != 0) {
						v4.x = tampon.x;
						v4.y = tampon.y-1;
					}
					depart = tampon;
					dep++;
					ajouter(depart);
					*taille = (*taille) + 1;
				
			
			}
			else if (map.cell[v2.x][v2.y] == 0 && (distance(v2.x,v2.y,objx,objy) < distance(depart.x,depart.y,objx,objy))){	
				
					tampon = v2;
					if (v2.x != map.nlignes-1) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v2.y != map.ncolonnes-1) {
						v2.x = tampon.x;
						v2.y = tampon.y+1;
					}
					if (v2.x != 0) {
						v3.x = tampon.x-1;
						v3.y = tampon.y;
					}
					if (v2.y != 0) {
						v4.x = tampon.x;
						v4.y = tampon.y-1;
					}
					depart = tampon;
					dep++;
					ajouter(depart);
					*taille = (*taille) + 1;
			
			}
			else if (map.cell[v3.x][v3.y] == 0 && (distance(v3.x,v3.y,objx,objy) < distance(depart.x,depart.y,objx,objy))){	
				
					tampon = v3;
					if (v3.x != map.nlignes-1) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v3.y != map.ncolonnes-1) {
						v2.x = tampon.x;
						v2.y = tampon.y+1;
					}
					if (v3.x != 0) {
						v3.x = tampon.x-1;
						v3.y = tampon.y;
					}
					if (v3.y != 0) {
						v4.x = tampon.x;
						v4.y = tampon.y-1;
					}
					depart = tampon;
					dep++;
					ajouter(depart);
					*taille = (*taille) + 1;
			
			}
			else if (map.cell[v4.x][v4.y] == 0 && (distance(v4.x,v4.y,objx,objy) < distance(depart.x,depart.y,objx,objy))){	
				
					tampon = v4;
					if (v4.x != map.nlignes-1) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v4.y != map.ncolonnes-1) {
						v2.x = tampon.x;
						v2.y = tampon.y+1;
					}
					if (v4.x != 0) {
						v3.x = tampon.x-1;
						v3.y = tampon.y;
					}
					if (v4.y != 0){
						v4.x = tampon.x;
						v4.y = tampon.y-1;
					}
					depart = tampon;
					dep++;
					ajouter(depart);
					*taille = (*taille) + 1;
			
			}
			else{
				if (map.cell[v1.x][v1.y] != 0){
					if(map.cell[v2.x][v2.y] == 0 && depart.y != map.ncolonnes-1){
						tampon = v2;
						if (v2.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v2.y != map.ncolonnes-1) {
							v2.x = tampon.x;
							v2.y = tampon.y+1;
						}
						if (v2.x != 0) {
							v3.x = tampon.x-1;
							v3.y = tampon.y;
						}
						if (v2.y != 0) {
							v4.x = tampon.x;
							v4.y = tampon.y-1;
						}
						depart = tampon;
					
						ajouter(depart);
						*taille = (*taille) + 1;
				
					}
				
					else if(map.cell[v4.x][v4.y] == 0 && depart.y != 0){
						tampon = v4;
						if (v4.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v4.y != map.ncolonnes-1) {
							v2.x = tampon.x;
							v2.y = tampon.y+1;
						}
						if (v4.x != 0) {
							v3.x = tampon.x-1;
							v3.y = tampon.y;
						}
						if (v4.y != 0){
							v4.x = tampon.x;
							v4.y = tampon.y-1;
						}
						depart = tampon;
						dep++;
						ajouter(depart);
						*taille = (*taille) + 1;
					}
				
					else if(map.cell[v3.x][v3.y] == 0 && depart.x != 0){
					
						tampon = v3;
						if (v3.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v3.y != map.ncolonnes-1) {
							v2.x = tampon.x;
							v2.y = tampon.y+1;
						}
						if (v3.x != 0) {
							v3.x = tampon.x-1;
							v3.y = tampon.y;
						}
						if (v3.y != 0) {
							v4.x = tampon.x;
							v4.y = tampon.y-1;
						}
						depart = tampon;
						dep++;
						ajouter(depart);
						*taille = (*taille) + 1;
					}
					else{
						return 1;
					}
				}
			
				if (map.cell[v2.x][v2.y] != 0){

					if(map.cell[v1.x][v1.y] == 0 && depart.x != map.nlignes-1){
						tampon = v1;
						if (v1.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v1.y != map.ncolonnes-1) {
							v2.x = tampon.x;
							v2.y = tampon.y+1;
						}
						if (v1.x != 0) {
							v3.x = tampon.x-1;
							v3.y = tampon.y;
						}
						if (v1.y != 0) {
							v4.x = tampon.x;
							v4.y = tampon.y-1;
						}
						depart = tampon;
						dep++;
						ajouter(depart);
						*taille = (*taille) + 1;
					}
				
					else if(map.cell[v3.x][v3.y] == 0 && depart.x != 0){
						tampon = v3;
						if (v3.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v3.y != map.ncolonnes-1) {
							v2.x = tampon.x;
							v2.y = tampon.y+1;
						}
						if (v3.x != 0) {
							v3.x = tampon.x-1;
							v3.y = tampon.y;
						}
						if (v3.y != 0) {
							v4.x = tampon.x;
							v4.y = tampon.y-1;
						}
						depart = tampon;
						dep++;
						ajouter(depart);
						*taille = (*taille) + 1;
					}
				
					else if(map.cell[v4.x][v4.y] == 0 && depart.y != 0){
						tampon = v4;
						if (v4.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v4.y != map.ncolonnes-1) {
							v2.x = tampon.x;
							v2.y = tampon.y+1;
						}
						if (v4.x != 0) {
							v3.x = tampon.x-1;
							v3.y = tampon.y;
						}
						if (v4.y != 0){
							v4.x = tampon.x;
							v4.y = tampon.y-1;
						}
						depart = tampon;
						dep++;
						ajouter(depart);
						*taille = (*taille) + 1;
					}
					else{
						return 1;
					}
				}

				if (map.cell[v3.x][v3.y] != 0){
					if(map.cell[v2.x][v2.y] == 0 && depart.y != map.ncolonnes-1){
						tampon = v2;
						if (v2.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v2.y != map.ncolonnes-1) {
							v2.x = tampon.x;
							v2.y = tampon.y+1;
						}
						if (v2.x != 0) {
							v3.x = tampon.x-1;
							v3.y = tampon.y;
						}
						if (v2.y != 0) {
							v4.x = tampon.x;
							v4.y = tampon.y-1;
						}
						depart = tampon;
						dep++;
						ajouter(depart);
						*taille = (*taille) + 1;
					}
				
					else if(map.cell[v4.x][v4.y] == 0 && depart.y != 0){
						tampon = v4;
						if (v4.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v4.y != map.ncolonnes-1) {
							v2.x = tampon.x;
							v2.y = tampon.y+1;
						}
						if (v4.x != 0) {
							v3.x = tampon.x-1;
							v3.y = tampon.y;
						}
						if (v4.y != 0){
							v4.x = tampon.x;
							v4.y = tampon.y-1;
						}
						depart = tampon;
						dep++;
						ajouter(depart);
						*taille = (*taille) + 1;
					}
				
					else if(map.cell[v1.x][v1.y] == 0 && depart.x != map.ncolonnes-1){
						tampon = v1;
						if (v1.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v1.y != map.ncolonnes-1) {
							v2.x = tampon.x;
							v2.y = tampon.y+1;
						}
						if (v1.x != 0) {
							v3.x = tampon.x-1;
							v3.y = tampon.y;
						}
						if (v1.y != 0) {
							v4.x = tampon.x;
							v4.y = tampon.y-1;
						}
						depart = tampon;
						dep++;
						ajouter(depart);
						*taille = (*taille) + 1;
					}
					else{						
						return 1;
						
					}
				}

				if (map.cell[v4.x][v4.y] != 0){
					if(map.cell[v1.x][v1.y] == 0 && depart.x != map.nlignes-1){
						tampon = v1;
						if (v1.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v1.y != map.ncolonnes-1) {
							v2.x = tampon.x;
							v2.y = tampon.y+1;
						}
						if (v1.x != 0) {
							v3.x = tampon.x-1;
							v3.y = tampon.y;
						}
						if (v1.y != 0) {
							v4.x = tampon.x;
							v4.y = tampon.y-1;
						}
						depart = tampon;
						dep++;
						ajouter(depart);
						*taille = (*taille) + 1;
					}
				
					else if(map.cell[v3.x][v3.y] == 0 && depart.x != 0){
						tampon = v3;
						if (v3.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v3.y != map.ncolonnes-1) {
							v2.x = tampon.x;
							v2.y = tampon.y+1;
						}
						if (v3.x != 0) {
							v3.x = tampon.x-1;
							v3.y = tampon.y;
						}
						if (v3.y != 0) {
							v4.x = tampon.x;
							v4.y = tampon.y-1;
						}
						depart = tampon;
						dep++;
						ajouter(depart);
						*taille = (*taille) + 1;
					}
				
					else if(map.cell[v2.x][v2.y] == 0 && depart.y != map.nlignes-1){
						tampon = v2;
						if (v2.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v2.y != map.ncolonnes-1) {
							v2.x = tampon.x;
							v2.y = tampon.y+1;
						}
						if (v2.x != 0) {
							v3.x = tampon.x-1;
							v3.y = tampon.y;
						}
						if (v2.y != 0) {
							v4.x = tampon.x;
							v4.y = tampon.y-1;
						}
						depart = tampon;
						dep++;
						ajouter(depart);
						*taille = (*taille) + 1;
					}
					else{
						return 1;
					}

				}
				
			}
		
		/*else{ depart.x = objx;
		  depart.y = objy;
		  ajouter(depart);
		  *taille = (*taille) + 5;
		}*/
			
	
	}
	if (dep >= 50){		
		return -1;
	}

	return 2;
}	
   



int cout_dep(t_liste * ordre_action){
	int cout;
	cout = 0.1 * ordre_action->ec->personnage.classe.poids + 1;
	return cout;
}

int deplacement_simp(t_liste *ordre_action,t_map map, char** mretour){
/**
 * \fn  deplacement_simp(t_liste *ordre_action,t_map map)
 * \brief Version simplifiée de la fonction déplacement.
 * \param t_liste *ordre_action : ordre de jeu des personnages (util pour connaître le personnage qui se déplace),t_map map : Plateau de jeu
 */
    int xobj;
    int yobj;
    int sortie=0;
    char choix;
    int taille = 0;
    t_noeud chemin[50];
    t_noeud cell;
    int erreur = 0;	
    int tete,queue,nb_valeurs;		
    initfile();
	printf("Rentrez un x pour le déplacement :\n");
	scanf("%i",&xobj);
	printf("Rentrez un y pour le déplacement :\n");
	scanf("%i",&yobj);
	printf("\n");
	
	if (xobj<map.nlignes-1 && yobj< map.nlignes-1 && xobj>0 && yobj>0){
		erreur = pathfinding(ordre_action->ec->personnage.x,ordre_action->ec->personnage.y,xobj,yobj,chemin,&taille,map);
		
	}
	int cout = taille /* * cout_dep(ordre_action)*/;

			
			if(xobj > map.nlignes-1 || yobj > map.ncolonnes-1 || xobj < 0 || yobj < 0){
				strcpy(*mretour,"Coordonnées hors map\n");
				return 0;
			}
			if (map.cell[xobj][yobj] != 0){		//On teste si la case est vide
				strcpy(*mretour,"La case est déjà occupée\n");
				return 0;
			}
		
			if (cout > ordre_action->ec->personnage.pa && erreur == 2){
				strcpy(*mretour,"Vous n'avez pas assez de PA\n");
				return 0;
			}
						
				
			
			map=actumap(ordre_action, map);
			
	
		
	


			switch (erreur){
				case -1 :
					map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 0;
					ordre_action->ec->personnage.x = xobj;
					ordre_action->ec->personnage.y = yobj;
					
					ordre_action->ec->personnage.pa = ordre_action->ec->personnage.pa - 5;
					map=actumap(ordre_action, map);
					clearScreen();
					afficherMat(map);
					usleep(300000);
					strcpy(*mretour,"Déplacement réussi\n");
					return 1;
					break ;
				case 1 : 
					map=actumap(ordre_action, map);
					clearScreen();
					afficherMat(map);				
					strcpy(*mretour,"Déplacement impossible, vous êtes encerclés\n");
					usleep(300000);
					return 0;
					break ;
				case 2 : 
					while (!filevide()){
						retirer(&cell);
						map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 0;
						ordre_action->ec->personnage.x = cell.x;
						ordre_action->ec->personnage.y = cell.y;
						map=actumap(ordre_action, map);
						clearScreen();
						afficherMat(map);
						usleep(300000);
					}			
					ordre_action->ec->personnage.pa = ordre_action->ec->personnage.pa - cout;
					assert(ordre_action->ec->personnage.x == xobj);
					assert(ordre_action->ec->personnage.y == yobj);
					strcpy(*mretour,"Déplacement réussi\n");
					return 1;
					break;

	
			}
		

}
