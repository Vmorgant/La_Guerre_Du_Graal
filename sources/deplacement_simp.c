/**
*\file deplacement_simp.c
*\brief Ce fichier contient les fonctions de déplacement sur la carte.
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

	t_noeud depart = {x,y};
	t_noeud v3 = {x,y};
	t_noeud v1 = {x,y};
	t_noeud v2 = {x,y};
	t_noeud v4 = {x,y};
	
	t_noeud tampon;
	if (depart.x != 0)
		v3.x = x-1;//Initialisation des noeud en faisant attention aux bords
	if (depart.x != map.nlignes-1)	
		v1.x = x+1;
	if (depart.y != map.ncolonnes-1)
		v2.y = y+1;
	if (depart.y != 0)
		v4.y = y-1;
	
	int dep = 0; // Nombre d'itération dans le pathfinding (Sécurité pour la boucle infini)
	int tete,queue,nb_valeurs;
	
	
	while ((depart.x != objx || depart.y != objy) && dep < 50){ // Tant qu'on est pas arrivé ou qu'on est pas en boucle infini
		
			// Test sur la case vide et la distance la plus courte à l'objectif
			if (map.cell[v1.x][v1.y] == 0 && (distance(v1.x,v1.y,objx,objy) < distance(depart.x,depart.y,objx,objy))){
				
					tampon = v1;
					if (v1.x != map.nlignes-1) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v1.y != map.ncolonnes-1) { //Sécurités pour éviter la sortie de matrice
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
			// Test sur la case vide et la distance la plus courte à l'objectif
			else if (map.cell[v2.x][v2.y] == 0 && (distance(v2.x,v2.y,objx,objy) < distance(depart.x,depart.y,objx,objy))){	
				
					tampon = v2;
					if (v2.x != map.nlignes-1) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v2.y != map.ncolonnes-1) { //Sécurités pour éviter la sortie de matrice
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
			// Test sur la case vide et la distance la plus courte à l'objectif
			else if (map.cell[v3.x][v3.y] == 0 && (distance(v3.x,v3.y,objx,objy) < distance(depart.x,depart.y,objx,objy))){	
				
					tampon = v3;
					if (v3.x != map.nlignes-1) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v3.y != map.ncolonnes-1) { //Sécurités pour éviter la sortie de matrice
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
			// Test sur la case vide et la distance la plus courte à l'objectif
			else if (map.cell[v4.x][v4.y] == 0 && (distance(v4.x,v4.y,objx,objy) < distance(depart.x,depart.y,objx,objy))){	
				
					tampon = v4;
					if (v4.x != map.nlignes-1) {
						v1.x = tampon.x+1;
						v1.y = tampon.y;
					}
					if (v4.y != map.ncolonnes-1) {//Sécurités pour éviter la sortie de matrice
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
			else{ // On considère qu'il y a un obstacle sur le chemin
				if (map.cell[v1.x][v1.y] != 0){ //Avec ce niveau de if on cherche quel chemin est occupé
					if(map.cell[v2.x][v2.y] == 0 && depart.y != map.ncolonnes-1){
						tampon = v2;
						if (v2.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v2.y != map.ncolonnes-1) {//Sécurités pour éviter la sortie de matrice
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
						if (v4.y != map.ncolonnes-1) {//Sécurités pour éviter la sortie de matrice
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
						if (v3.y != map.ncolonnes-1) {//Sécurités pour éviter la sortie de matrice
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
						return 1;// Retour d'erreur 'Encerclé'
					}
				}
			
				if (map.cell[v2.x][v2.y] != 0){

					if(map.cell[v1.x][v1.y] == 0 && depart.x != map.nlignes-1){
						tampon = v1;
						if (v1.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v1.y != map.ncolonnes-1) {//Sécurités pour éviter la sortie de matrice
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
						if (v3.y != map.ncolonnes-1) {//Sécurités pour éviter la sortie de matrice
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
						if (v4.y != map.ncolonnes-1) {//Sécurités pour éviter la sortie de matrice
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
						return 1;// Retour d'erreur 'Encerclé'
					}
				}

				if (map.cell[v3.x][v3.y] != 0){
					if(map.cell[v2.x][v2.y] == 0 && depart.y != map.ncolonnes-1){
						tampon = v2;
						if (v2.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v2.y != map.ncolonnes-1) {//Sécurités pour éviter la sortie de matrice
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
						if (v4.y != map.ncolonnes-1) {//Sécurités pour éviter la sortie de matrice
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
						if (v1.y != map.ncolonnes-1) {//Sécurités pour éviter la sortie de matrice
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
						return 1;//Retour d'erreur 'Encerclé'
						
					}
				}

				if (map.cell[v4.x][v4.y] != 0){
					if(map.cell[v1.x][v1.y] == 0 && depart.x != map.nlignes-1){
						tampon = v1;
						if (v1.x != map.nlignes-1) {
							v1.x = tampon.x+1;
							v1.y = tampon.y;
						}
						if (v1.y != map.ncolonnes-1) {//Sécurités pour éviter la sortie de matrice
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
						if (v3.y != map.ncolonnes-1) {//Sécurités pour éviter la sortie de matrice
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
						if (v2.y != map.ncolonnes-1) {//Sécurités pour éviter la sortie de matrice
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
						return 1;// Retour d'erreur 'Encerclé
					}

				}
				
			}
			
	
	}
	if (dep >= 50){	//Boucle infini	
		return -1;//passage à la téléportation pour aller à l'objectif.
	}

	return 2;// Le déplacement s'est bien déroulé.
}	
   



/*float cout_dep(t_liste * ordre_action){
	float cout;
	cout = 0.1 * ordre_action->ec->personnage.classe.poids + 1;
	return cout;
}*/

void deplacement(t_liste *ordre_action,t_map map){
/**
 * \fn  deplacement(t_liste *ordre_action,t_map map)
 * \brief Fonction permettant de déplacer le personnage.
 * \param t_liste *ordre_action : ordre de jeu des personnages (util pour connaître le personnage qui se déplace),t_map map : Plateau de jeu
 */
    int xobj;
    int yobj;
    int sortie=0;
    char choix;
    int taille = 0;
    t_noeud chemin[50];//file dans laquelle est contenue le chemin
    t_noeud cell;
    int dep_erreur = 0;	// Variables pour l'affichage des erreurs 
    int erreur = 0;
    char mretour[100] = "\n";
    int tete,queue,nb_valeurs;
    int cout = taille; /* cout_dep(ordre_action);*/	//cout du déplacement	
    initfile();

	do{
		clearScreen();
		afficherMat(map);
		if (ordre_action->ec->personnage.joueur == 1) couleur("34;1"); //Ecriture en bleu
		else couleur("31;1");//En rouge
		

		printf("%s Equipe :%i %i/%i PV (%iPA) coordonnee %i %i\n",ordre_action->ec->personnage.classe.nom,ordre_action->ec->personnage.joueur, ordre_action->ec->personnage.pv, ordre_action->ec->personnage.classe.PVmax,ordre_action->ec->personnage.pa, ordre_action->ec->personnage.x,ordre_action->ec->personnage.y);	
		couleur("0");	
		printf("\nChoix des coordonnées :\n");

		if(erreur) {					// Affichage de l'erreur
				couleur("31");
				printf("\t%s",mretour);
				couleur("0");
			} else {
				couleur("32");
				printf("\t%s",mretour);
				couleur("0");
			}
		erreur = faux;
		strcpy(mretour,"\n");

		printf("Rentrez un x pour le déplacement (-1 pour annuler) : ");	// Entrée des coordonnées objectifs
		scanf("%i",&xobj);

		if(xobj != -1) {
			printf("Rentrez un y pour le déplacement (-1 pour annuler) : ");
				scanf("%i",&yobj);
				printf("\n");
			if(yobj != -1){
			
				if(xobj > map.nlignes-1 || yobj > map.ncolonnes-1 || xobj < 0 || yobj < 0){ //Test du Hors map
					dep_erreur = 4;
				} else if (map.cell[xobj][yobj] != 0){		//On teste si la case est vide
					dep_erreur = 3;
				} else if (xobj < map.nlignes && yobj < map.nlignes && xobj >= 0 && yobj >= 0){ // Déroulement normal
					dep_erreur = pathfinding(ordre_action->ec->personnage.x,ordre_action->ec->personnage.y,xobj,yobj,chemin,&taille,map);
					cout = taille;
					
					if (cout > ordre_action->ec->personnage.pa && dep_erreur == 2){ // Test du cout en PA
						dep_erreur = 0;
						
					}
					
				}
				
				

				map=actumap(ordre_action, map);
			
	
				switch (dep_erreur){
					case -1 : // Cas d'erreur boucle infini
						map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 0;
						ordre_action->ec->personnage.x = xobj;
						ordre_action->ec->personnage.y = yobj;
					
						ordre_action->ec->personnage.pa = ordre_action->ec->personnage.pa - 5;
						map=actumap(ordre_action, map);
						clearScreen();
						afficherMat(map);
						usleep(300000);
						strcpy(mretour,"\tDéplacement réussi\n");
						
						break ;
					case 0 : // Cas d'erreur manque de PA
						map=actumap(ordre_action, map);
						clearScreen();
						afficherMat(map);				
						strcpy(mretour,"\tVous manquez de PA\n");
						erreur = 1;
						usleep(300000);
						break ;
					case 1 : // Cas d'erreur encerclement
						map=actumap(ordre_action, map);
						clearScreen();
						afficherMat(map);				
						strcpy(mretour,"\tDéplacement impossible, vous êtes encerclés\n");
						usleep(300000);
						erreur = 1;
						break ;
					case 2 : // Aucune erreur
						while (!filevide()){
							retirer(&cell);
							map.cell[ordre_action->ec->personnage.x][ordre_action->ec->personnage.y] = 0;
							ordre_action->ec->personnage.x = cell.x;
							ordre_action->ec->personnage.y = cell.y;
							map=actumap(ordre_action, map);
							clearScreen();
							afficherMat(map);
							usleep(300000);
							erreur = 1;
						}			
						ordre_action->ec->personnage.pa = ordre_action->ec->personnage.pa - cout;
						assert(ordre_action->ec->personnage.x == xobj); 
						assert(ordre_action->ec->personnage.y == yobj);
						strcpy(mretour,"\tDéplacement réussi\n");
						erreur = 0;
						break;
					case 3 :
						map=actumap(ordre_action, map);
						clearScreen();
						afficherMat(map);				
						strcpy(mretour,"\tLa case est déjà occupée\n");
						erreur = 1;
						usleep(300000);
						break ;
					case 4:
						map=actumap(ordre_action, map);
						clearScreen();
						afficherMat(map);				
						strcpy(mretour,"\tLes coordonnées sont hors map\n");
						erreur = 1;
						usleep(300000);
						break ;
				}
			}
		}
	} while(erreur == 1);
}
