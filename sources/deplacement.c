/**
*\file deplacement.c
*\brief Ce fichier contient les définitions des fonctions de déplacement sur la carte.
*\author Victor Morgant, Martin Lebourdais
*\version 1.0
*\date 09/11/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"
#include "liste_chemin.h"
#include "Init_map.h"

void permuter(t_element_noeud *actuel,t_element_noeud *suivant){
/**
 * \fn  permuter(t_element_noeud *actuel,t_element_noeud *suivant)
 * \brief Intervertit les structures des deux cases.
 * \param t_element_noeud *actuel : La case sur laquelle le personnage se trouve, t_element_noeud *suivant : La case ou l'on souhaite placer le personnage.
 */
	t_element_noeud tampon;
	tampon = *actuel;
	*actuel = *suivant;
	*suivant = tampon;
}

int existinf(t_liste_noeud liste,t_noeud valeur){
/**
 * \fn  existinf(t_liste_noeud liste,t_noeud valeur)
 * \brief Recherche s'il existe une structure noeud avec un cout inférieur au noeud en paramètre dans la liste en paramètre.
 * \param t_liste_noeud liste : La liste dans laquelle on souhaite chercher, t_noeud valeur : Le noeud que l'on souhaite tester 
 */
	en_tete_noeud(&liste);
	t_noeud vcour;
	while(!hors_liste_noeud(&liste)){
		valeur_elt_noeud(&liste,&vcour);
		if ((vcour.x==valeur.x) && (vcour.y==valeur.y) && (vcour.cout<valeur.cout)) return 1;/*On compare les coordonnées pour savoir si le noeud est le même*/
		suivant_noeud(&liste);
	}
	return 0;
}

int distance(int x,int y,int objx,int objy){
/**
 * \fn  distance(int x,int y,int objx,int objy)
 * \brief Calcule le carré de la distance entre le point de départ et l'objectif
 * \param int x : Abscisse de départ, int y : Ordonnée de départ, int xobj : Abscisse cible; int yobj : Ordonnée cible
 */
	int distance =(objx-x)*(objx-x)+(objy-y)*(objy-y);
	return distance;
}


void pathfinding(int x, int y,int objx,int objy){
/**
 * \fn  pathfinding(int x, int y,int objx,int objy)
 * \brief Trouve le chemin le plus court entre le point de départ et l'objectif et retourne ce chemin dans une liste.
 * \param int x : Abscisse de départ, int y : Ordonnée de départ, int xobj : Abscisse cible; int yobj : Ordonnée cible
 */
    t_noeud depart={x,y,0,0};
    t_liste_noeud openlist;				/*Liste des noeuds à tester*/
    t_liste_noeud closedlist;				/*Liste des noeuds testés*/
    init_liste_noeud(&openlist);
    init_liste_noeud(&closedlist);
    ajout_droit_noeud(&openlist,depart);
	en_tete_noeud(&openlist);
	en_tete_noeud(&closedlist);
	t_noeud q;	
	while(!liste_vide_noeud(&openlist)){  
			
		valeur_elt_noeud(&openlist,&q);
		oter_elt_noeud(&openlist);
		if (q.x == objx && q.y == objy){			/*On teste si on est arrivé*/
			en_tete_noeud(&openlist);
			while(!hors_liste_noeud(&openlist)){
				printf("[%i,%i]\n",openlist.ec_noeud->noeud.x,openlist.ec_noeud->noeud.y);			
			}
			
			break ;
		}
		t_noeud v1 = {q.x+1,q.y,0,0};
		t_noeud v2 = {q.x,q.y+1,0,0};
		t_noeud v3 = {q.x-1,q.y,0,0};
		t_noeud v4 = {q.x,q.y-1,0,0};
		
		if (existinf(openlist,v1)||existinf(closedlist,v1));				/*On cherche pour chaque voisin de la case si on l'a déjà testée.*/
		else{
			v1.cout=q.cout+1;
			v1.heuristique = v1.cout + distance(v1.x,v1.y,objx,objy);
			ajout_droit_noeud(&openlist,v1);
			suivant_noeud(&openlist);
		}

		if (existinf(openlist,v2)||existinf(closedlist,v2));
		else{
			v2.cout=q.cout+1;
			v2.heuristique = v2.cout + distance(v2.x,v2.y,objx,objy);
			ajout_droit_noeud(&openlist,v2);
			suivant_noeud(&openlist);
		}

		if (existinf(openlist,v3)||existinf(closedlist,v3));
		else{
			v3.cout=q.cout+1;
			v3.heuristique = v3.cout + distance(v3.x,v3.y,objx,objy);
			ajout_droit_noeud(&openlist,v3);
			suivant_noeud(&openlist);
		}
		if (existinf(openlist,v4)||existinf(closedlist,v4));
		else{
			v4.cout=q.cout+1;
			v4.heuristique = v4.cout + distance(v4.x,v4.y,objx,objy);
			ajout_droit_noeud(&openlist,v4);
			suivant_noeud(&openlist);
		}
		
		ajout_droit_noeud(&closedlist,q); /*On ajoute la case que l'on vient de tester à la liste*/
		suivant_noeud(&closedlist);
	}	
	
	printf("Fin du programme\n");	
		
	
    
}
void deplacement(t_liste *ordre_action,t_map map){
/**
 * \fn  deplacement(t_liste *ordre_action,t_map map)
 * \brief Déplace le personnage courant par permutation successives du point de départ à la cible.
 * \param t_liste *ordre_action : ordre de jeu des personnages (util pour connaître le personnage qui se déplace),t_map map : Plateau de jeu
 */
        int xobj;
        int yobj;
	t_element_noeud *tampon;
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
	
	
	t_liste_noeud *openlist=NULL;
	t_liste_noeud *closedlist=NULL;
	init_liste_noeud(openlist);
	init_liste_noeud(closedlist);
	pathfinding(ordre_action->ec->personnage.x,ordre_action->ec->personnage.y,xobj,yobj);
	//On cherche le openlist le plus court
	en_tete_noeud(openlist);
	while(openlist->ec_noeud->noeud.x != xobj || openlist->ec_noeud->noeud.y != yobj){
	
		if (map.cell[openlist->ec_noeud->succ_noeud->noeud.x][openlist->ec_noeud->succ_noeud->noeud.y] != 0){			//Si la case n'est pas vide
			
		
			tampon = openlist->ec_noeud->succ_noeud;//On mémorise le perso sur la case
     
			

			openlist->ec_noeud->succ_noeud = openlist->ec_noeud;
			ordre_action->ec->personnage.x = openlist->ec_noeud->noeud.x;   
			
			//On actualise les coordonnées dans les structures des persos
			ordre_action->ec->personnage.y = openlist->ec_noeud->noeud.y;
			actumap(ordre_action, map);
			afficherMat(map);
			suivant_noeud(openlist);
			permuter(openlist->ec_noeud, openlist->ec_noeud->succ_noeud);

			//On permute avec la case suivante dans le openlist défini
			openlist->ec_noeud->pred_noeud = tampon;
			ordre_action->ec->personnage.x = openlist->ec_noeud->noeud.x;

			//On actualise les coordonnées dans les structures des persos
			ordre_action->ec->personnage.y = openlist->ec_noeud->noeud.y;
			suivant_noeud(openlist);
			actumap(ordre_action, map);
			afficherMat(map);
		}
		else{
			permuter(openlist->ec_noeud,openlist->ec_noeud->succ_noeud);        
			//On permute avec la case suivante dans le openlist défini
			ordre_action->ec->personnage.x = openlist->ec_noeud->noeud.x;  
			//On actualise les coordonnées dans les structures des persos
			ordre_action->ec->personnage.y = openlist->ec_noeud->noeud.y;
			suivant_noeud(openlist);
			actumap(ordre_action,map);					  
			//On actualise la map
			afficherMat(map);							  
			//On affiche la map
		}
	}
}
