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




float distance(int x,int y,int objx,int objy){
/**
 * \fn  distance(int x,int y,int objx,int objy)
 * \brief Calcule le carré de la distance entre le point de départ et l'objectif
 * \param int x : Abscisse de départ, int y : Ordonnée de départ, int xobj : Abscisse cible; int yobj : Ordonnée cible
 */
float distance = sqrt(((float)objx-(float)x)*((float)objx-(float)x)+((float)objy-(float)y)*((float)objy-(float)y));
	
	return distance;
}


void pathfinding(int x, int y,int objx,int objy,t_noeud chemin[50],int * taille,t_map map){
/**
 * \fn  pathfinding(int x, int y,int objx,int objy)
 * \brief Trouve le chemin le plus court entre le point de départ et l'objectif et retourne ce chemin dans une file.
 * \param int x : Abscisse de départ, int y : Ordonnée de départ, int xobj : Abscisse cible; int yobj : Ordonnée cible
 */

	t_noeud depart = {x,y,0,0};
	t_noeud tampon;
	t_noeud v1 = {x+1,y,0,0};
	t_noeud v2 = {x,y+1,0,0};
	t_noeud v3 = {x-1,y,0,0};
	t_noeud v4 = {x,y-1,0,0};
	int tete,queue,nb_valeurs;
	
	
	while (depart.x != objx){
		
		if (map.cell[v1.x][v1.y] == 0 && (distance(v1.x,v1.y,objx,objy) < distance(depart.x,depart.y,objx,objy))){	
				
				tampon = v1;
				if (v1.x != 9) {
					v1.x = tampon.x+1;
					v1.y = tampon.y;
				}
				if (v1.y != 9) {
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
				printf("%i,%i\n",depart.x,depart.y);
				ajouter(depart);
				*taille = (*taille) + 1;
				
			
		}
		else if (map.cell[v2.x][v2.y] == 0 && (distance(v2.x,v2.y,objx,objy) < distance(depart.x,depart.y,objx,objy))){	
				
				tampon = v2;
				if (v2.x != 9) {
					v1.x = tampon.x+1;
					v1.y = tampon.y;
				}
				if (v2.y != 9) {
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
				printf("%i,%i\n",depart.x,depart.y);
				ajouter(depart);
				*taille = (*taille) + 1;
			
		}
		else if (map.cell[v3.x][v3.y] == 0 && (distance(v3.x,v3.y,objx,objy) < distance(depart.x,depart.y,objx,objy))){	
				
				tampon = v3;
				if (v3.x != 9) {
					v1.x = tampon.x+1;
					v1.y = tampon.y;
				}
				if (v3.y != 9) {
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
				printf("%i,%i\n",depart.x,depart.y);
				ajouter(depart);
				*taille = (*taille) + 1;
			
		}
		else if (map.cell[v4.x][v4.y] == 0 && (distance(v4.x,v4.y,objx,objy) < distance(depart.x,depart.y,objx,objy))){	
				
				tampon = v4;
				if (v4.x != 9) {
					v1.x = tampon.x+1;
					v1.y = tampon.y;
				}
				if (v4.y != 9) {
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
				printf("%i,%i\n",depart.x,depart.y);
				ajouter(depart);
				*taille = (*taille) + 1;
			
		}
		else{
			if (map.cell[v1.x][v1.y] != 0){
				if(map.cell[v2.x][v2.y] == 0 && depart.y != 9){
					tampon = v2;
					if (v2.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v2.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				
				}
				
				else if(map.cell[v4.x][v4.y] == 0 && depart.y != 0){
					tampon = v4;
					if (v4.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v4.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				
				else if(map.cell[v3.x][v3.y] == 0 && depart.x != 0){
					
					tampon = v3;
					if (v3.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v3.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				else printf("Déplacement impossible \n");
			}
			
			if (map.cell[v2.x][v2.y] != 0){

				if(map.cell[v1.x][v1.y] == 0 && depart.x != 9){
					tampon = v1;
					if (v1.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v1.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				
				else if(map.cell[v3.x][v3.y] == 0 && depart.x != 0){
					tampon = v3;
					if (v3.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v3.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				
				else if(map.cell[v4.x][v4.y] == 0 && depart.y != 0){
					tampon = v4;
					if (v4.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v4.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				else printf("Déplacement impossible \n");
			}

			if (map.cell[v3.x][v3.y] != 0){
				if(map.cell[v2.x][v2.y] == 0 && depart.y != 9){
					tampon = v2;
					if (v2.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v2.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				
				else if(map.cell[v4.x][v4.y] == 0 && depart.y != 0){
					tampon = v4;
					if (v4.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v4.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				
				else if(map.cell[v1.x][v1.y] == 0 && depart.x != 9){
					tampon = v1;
					if (v1.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v1.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				else printf("Déplacement impossible \n");
			}

			if (map.cell[v4.x][v4.y] != 0){
				if(map.cell[v1.x][v1.y] == 0 && depart.x != 9){
					tampon = v1;
					if (v1.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v1.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				
				else if(map.cell[v3.x][v3.y] == 0 && depart.x != 0){
					tampon = v3;
					if (v3.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v3.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				
				else if(map.cell[v2.x][v2.y] == 0 && depart.y != 9){
					tampon = v2;
					if (v2.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v2.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				else printf("Déplacement impossible \n");

			}

		}
	
	}
	while (depart.y != objy){
		
		
		if (map.cell[v1.x][v1.y] == 0 && (distance(v1.x,v1.y,objx,objy) < distance(depart.x,depart.y,objx,objy))){	
				
				tampon = v1;
				if (v1.x != 9) {
					v1.x = tampon.x+1;
					v1.y = tampon.y;
				}
				if (v1.y != 9) {
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
				printf("%i,%i\n",depart.x,depart.y);
				ajouter(depart);
				*taille = (*taille) + 1;
			
			
			
		}
		else if (map.cell[v2.x][v2.y] == 0 && (distance(v2.x,v2.y,objx,objy)< distance(depart.x,depart.y,objx,objy))){	
				
				
				
				tampon = v2;
				if (v2.x != 9) {
					v1.x = tampon.x+1;
					v1.y = tampon.y;
				}
				if (v2.y != 9) {
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
				printf("%i,%i\n",depart.x,depart.y);
				ajouter(depart);
				*taille = (*taille) + 1;
			
		}
		else if (map.cell[v3.x][v3.y] == 0 && (distance(v3.x,v3.y,objx,objy) < distance(depart.x,depart.y,objx,objy))){	
				
				
				
				tampon = v3;
				if (v3.x != 9) {
					v1.x = tampon.x+1;
					v1.y = tampon.y;
				}
				if (v3.y != 9) {
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
				printf("%i,%i\n",depart.x,depart.y);
				ajouter(depart);
				*taille = (*taille) + 1;
			
		}
		else if (map.cell[v4.x][v4.y] == 0 && (distance(v4.x,v4.y,objx,objy)< distance(depart.x,depart.y,objx,objy))){	
				
				tampon = v4;
				if (v4.x != 9) {
					v1.x = tampon.x+1;
					v1.y = tampon.y;
				}
				if (v4.y != 9) {
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
				printf("%i,%i\n",depart.x,depart.y);
				ajouter(depart);
				*taille = (*taille) + 1;
			
		}
		else{
			if (map.cell[v1.x][v1.y] != 0){
				if(map.cell[v2.x][v2.y] == 0 && depart.y != 9){
					tampon = v2;
					if (v2.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v2.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				
				}
				
				else if(map.cell[v4.x][v4.y] == 0 && depart.y != 0){
					tampon = v4;
					if (v4.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v4.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				
				else if(map.cell[v3.x][v3.y] == 0 && depart.x != 0){
					
					tampon = v3;
					if (v3.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v3.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				else printf("Déplacement impossible \n");
			}
			
			if (map.cell[v2.x][v2.y] != 0){

				if(map.cell[v1.x][v1.y] == 0 && depart.x != 9){
					tampon = v1;
					if (v1.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v1.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				
				else if(map.cell[v3.x][v3.y] == 0 && depart.x != 0){
					tampon = v3;
					if (v3.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v3.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				
				else if(map.cell[v4.x][v4.y] == 0 && depart.y != 0){
					tampon = v4;
					if (v4.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v4.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				else printf("Déplacement impossible \n");
			}

			if (map.cell[v3.x][v3.y] != 0){
				if(map.cell[v2.x][v2.y] == 0 && depart.y != 9){
					tampon = v2;
					if (v2.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v2.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				
				else if(map.cell[v4.x][v4.y] == 0 && depart.y != 0){
					tampon = v4;
					if (v4.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v4.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				
				else if(map.cell[v1.x][v1.y] == 0 && depart.x != 9){
					tampon = v1;
					if (v1.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v1.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				else printf("Déplacement impossible \n");
			}

			if (map.cell[v4.x][v4.y] != 0){
				if(map.cell[v3.x][v3.y] == 0 && depart.x != 0){
					tampon = v3;
					if (v3.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v3.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				
				else if(map.cell[v1.x][v1.y] == 0 && depart.x != 9){
					
					
					tampon = v1;
					if (v1.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v1.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				
				else if(map.cell[v2.x][v2.y] == 0 && depart.y != 9){
					tampon = v2;
					if (v2.x != 9) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v2.y != 9) {
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
					printf("%i,%i\n",depart.x,depart.y);
					ajouter(depart);
					*taille = (*taille) + 1;
				}
				else printf("Déplacement impossible \n");

			}

		}
		
	}
	
	
	

}

int cout_dep(t_liste * ordre_action){
	int cout;
	cout = 0.1 * ordre_action->ec->personnage.classe.poids + 1;
	return cout;
}

void deplacement_simp(t_liste *ordre_action,t_map map){
/**
 * \fn  deplacement_simp(t_liste *ordre_action,t_map map)
 * \brief Version simplifiée de la fonction déplacement.
 * \param t_liste *ordre_action : ordre de jeu des personnages (util pour connaître le personnage qui se déplace),t_map map : Plateau de jeu
 */
    int xobj;
    int yobj;
    int sortie;
    char choix;
    int taille = 0;
    t_noeud chemin[50];
    t_noeud cell;	
    int tete,queue,nb_valeurs;		
    initfile();
    	printf("%i",taille);
	printf("Rentrez un x pour le déplacement :\n");
	scanf("%i",&xobj);
	printf("Rentrez un y pour le déplacement :\n");
	scanf("%i",&yobj);
	printf("\n");
	printf("%i,%i\n",xobj,yobj);
	map=actumap(ordre_action, map);
	pathfinding(ordre_action->ec->personnage.x,ordre_action->ec->personnage.y,xobj,yobj,chemin,&taille,map);
		
	int cout = taille;
	printf("%i PA\n", taille);
	
	
			while (xobj > 9 || yobj > 9 || xobj < 0 || yobj < 0 || map.cell[xobj][yobj]!=0 || cout > ordre_action->ec->personnage.pa || sortie == 1){
				if (map.cell[xobj][yobj] != 0){															//On teste si la case est vide
						printf("La case est déjà occupée\n");
						printf("Rentrez un x pour le déplacement :\n");
						scanf("%i",&xobj);
						printf("Rentrez un y pour le déplacement :\n");
						scanf("%i",&yobj);
						printf("\n");
						map=actumap(ordre_action, map);
						pathfinding(ordre_action->ec->personnage.x,ordre_action->ec->personnage.y,xobj,yobj,chemin,&taille,map);
						cout = taille;
					}
				if (xobj > 9 || yobj > 9 || xobj < 0 || yobj < 0){
						printf("Les coordonnées doivent-être des entiers compris entre 0 et 9\n");
						printf("Rentrez un x pour le déplacement :\n");
						scanf("%i",&xobj);
						printf("Rentrez un y pour le déplacement :\n");
						scanf("%i",&yobj);
						printf("\n");
						map=actumap(ordre_action, map);
						pathfinding(ordre_action->ec->personnage.x,ordre_action->ec->personnage.y,xobj,yobj,chemin,&taille,map);
						cout = taille;
					}
				else{
						printf("Vous n'avez pas assez de PA\n");
						printf("Voulez vous toujours vous déplacer\n");
						printf("o/n : ");
						scanf("%c",&choix);
						printf("\n");
						switch (choix){
							case 'o':
								printf("Rentrez un x pour le déplacement :\n");
								scanf("%i",&xobj);
								printf("Rentrez un y pour le déplacement :\n");
								scanf("%i",&yobj);
								printf("\n");
								map=actumap(ordre_action, map);
								pathfinding(ordre_action->ec->personnage.x,ordre_action->ec->personnage.y,xobj,yobj,chemin,&taille,map);	
								cout = taille;
								printf("%i PA\n", cout);
								break ;
							case 'n' : sortie = 1 ;break;
						}
						
				}
			}
			while (!filevide()){
				retirer(&cell);
				map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 0;
				ordre_action->ec->personnage.x = cell.x;
				ordre_action->ec->personnage.y = cell.y;
				map=actumap(ordre_action, map);
				ordre_action->ec->personnage.pa = ordre_action->ec->personnage.pa - cout;
				clearScreen();
				afficherMat(map);
				sleep(1);
			}
		

}
