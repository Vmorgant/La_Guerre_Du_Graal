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

void permuter(t_noeud *actuel,t_noeud *suivant){
	t_noeud tampon;
	tampon = *actuel;
	*actuel = *suivant;
	*suivant = tampon;
}

int existinf(t_liste_noeud liste,t_noeud valeur){
/**Fonction qui teste si il existe le même noeud avec un cout inferieur à la valeur entrée en paramètre dans la liste en paramètre.*/
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
	/**Calcul de la distance entre le point et l'objectif*/
	int distance =sqrt((objx-x)*(objx-x)+(objy-y)*(objy-y));
	return distance;
}


void pathfinding(int x, int y,int objx,int objy){
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
				printf("[%i,%i]\n",openlist.ec->noeud.x,openlist.ec->noeud.y);			
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
		}

		if (existinf(openlist,v2)||existinf(closedlist,v2));
		else{
			v2.cout=q.cout+1;
			v2.heuristique = v2.cout + distance(v2.x,v2.y,objx,objy);
			ajout_droit_noeud(&openlist,v2);
		}

		if (existinf(openlist,v3)||existinf(closedlist,v3));
		else{
			v3.cout=q.cout+1;
			v3.heuristique = v3.cout + distance(v3.x,v3.y,objx,objy);
			ajout_droit_noeud(&openlist,v3);
		}
		if (existinf(openlist,v4)||existinf(closedlist,v4));
		else{
			v4.cout=q.cout+1;
			v4.heuristique = v4.cout + distance(v4.x,v4.y,objx,objy);
			ajout_droit_noeud(&openlist,v4);
		}
		
		ajout_droit_noeud(&closedlist,q); /*On ajoute la case que l'on vient de tester à la liste*/
	
	}	
	
	printf("Fin du programme\n");	
		
	
    
}
void deplacement(t_liste *ordre_action,t_map map){
        int xobj;
        int yobj;
	printf("Rentrez des coordonnées séparées par une vigule\n");
	scanf("%i,%i",xobj,yobj);
	printf("\n");
	
	t_liste_noeud openlist;
	t_liste_noeud closedlist;
	init_liste_noeud(&openlist);
	init_liste_noeud(&closedlist);
	pathfinding(ordre_action->ec->personnage.x,ordre_action->ec->personnage.y,xobj,yobj);     //On cherche le openlist le plus court
	en_tete_noeud(&openlist);
	while(openlist.ec->personnage.x != xobj || openlist.ec->personnage.y != yobj){
		
	permuter(openlist.ec,openlist.ec->succ->ec);        //On permute avec la case suivante dans le openlist défini
	ordre_action->ec->personnage.x = openlist.ec->personnage.x;   //On actualise les coordonnées dans les structures des persos
	ordre_action->ec->personnage.y = openlist.ec->personnage.y;
	actumap(ordre_action,map);					  //On actualise la map
	afficherMat(map);							  //On affiche la map
	}
}
