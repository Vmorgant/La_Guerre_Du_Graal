/**
*\file Pathfinding.c
*\brief Gestion de la planification du déplacement
*\version 1.0
*\author Martin Lebourdais
*\date 17/11/2016
*/

typedef struct {int x, y, cout, heuristique;}t_noeud;
typedef struct{t_noeud noeud; struct element* pred; struct element* succ;}t_element;
typedef struct{t_element * drapeau; t_element * ec;}t_liste;


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void init_liste(t_liste_noeud * p) {
	p->drapeau =  malloc (sizeof(t_element_noeud));
	p->ec =  malloc (sizeof(t_element_noeud));
	p->drapeau -> pred = p->drapeau;
	p->drapeau -> succ = p->drapeau;
	p->ec = p->drapeau;
}
/*Primitives de liste*/
int liste_vide (t_liste_noeud * p) {
	if(p->drapeau -> pred == p->drapeau)
		return 1;
	else return 0;
}

int hors_liste (t_liste_noeud * p) {
	if(p->ec == p->drapeau)
		return 1;
	else return 0;
}

void en_tete (t_liste_noeud * p) {
	p->ec = p->drapeau -> succ;
}

void en_queue (t_liste_noeud * p) {
	p->ec = p->drapeau -> pred;
}

void suivant(t_liste_noeud * p) {
	if (!hors_liste(p)){
		p->ec = p->ec -> succ;
	}
}

void precedent(t_liste_noeud * p) {
	if (!hors_liste(p)){
		p->ec = p->ec -> pred;
	}
}

void valeur_elt(t_liste_noeud * p, t_noeud * v) {
	if(!hors_liste(&p))
		*v = p->ec -> noeud;
}

void modif_elt(t_liste_noeud * p, t_noeud v) {
	if(!hors_liste(&p))
		p->ec -> noeud = v;
}

void oter_elt(t_liste_noeud * p) {
	if(!hors_liste(p)) {
		t_element * temp;
		temp = malloc (sizeof(t_element));
		temp = p->ec;
		suivant(p);
		p->ec -> pred = temp -> pred;
		precedent(p);
		p->ec -> succ = temp -> succ;
		free(temp);
	}
}

void ajout_droit(t_liste_noeud * p, t_noeud v) {
	if (liste_vide(p) || !hors_liste(p) ) {
		t_element * nouv;
		nouv = malloc (sizeof(t_element));
		nouv -> noeud = v;
		nouv -> succ = p->ec -> succ;
		nouv -> pred = p->ec;
		p->ec -> succ = nouv;
		p->(ec -> succ) -> pred = nouv;
	}
}

void ajout_gauche(t_liste_noeud * p, t_noeud v) {
	if (liste_vide(p) || !hors_liste(p) ) {
		t_element * nouv;
		nouv = malloc (sizeof(t_element));
		nouv -> noeud = v;
		nouv -> succ = p->ec;
		nouv -> pred = p->ec -> pred;
		p->ec -> pred = nouv;
		p->(ec -> pred) -> succ = nouv;
	}
}
/*Fin des primitives de liste*/

int existinf(t_liste_noeud liste,t_noeud valeur){
/**Fonction qui teste si il existe le même noeud avec un cout inferieur à la valeur entrée en paramètre dans la liste en paramètre.*/
	en_tete(&liste);
	t_noeud vcour;
	while(!hors_liste(&liste)){
		valeur_elt(&liste,&vcour);
		if ((vcour.x==valeur.x) && (vcour.y==valeur.y) && (vcour.cout<valeur.cout)) return 1;/*On compare les coordonnées pour savoir si le noeud est le même*/
		suivant(&liste);
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
    t_liste openlist;				/*Liste des noeuds à tester*/
    t_liste closedlist;				/*Liste des noeuds testés*/
    init_liste(&openlist);
    init_liste(&closedlist);
    ajout_droit(&openlist,depart);
	en_tete(&openlist);
	en_tete(&closedlist);
	t_noeud q;	
	while(!liste_vide(&openlist)){  
			
		valeur_elt(&openlist,&q);
		oter_elt(&openlist);
		if (q.x == objx && q.y == objy){			/*On teste si on est arrivé*/
			en_tete(&openlist);
			while(!hors_liste(&openlist)){
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
			ajout_droit(&openlist,v1);
		}

		if (existinf(openlist,v2)||existinf(closedlist,v2));
		else{
			v2.cout=q.cout+1;
			v2.heuristique = v2.cout + distance(v2.x,v2.y,objx,objy);
			ajout_droit(&openlist,v2);
		}

		if (existinf(openlist,v3)||existinf(closedlist,v3));
		else{
			v3.cout=q.cout+1;
			v3.heuristique = v3.cout + distance(v3.x,v3.y,objx,objy);
			ajout_droit(&openlist,v3);
		}
		if (existinf(openlist,v4)||existinf(closedlist,v4));
		else{
			v4.cout=q.cout+1;
			v4.heuristique = v4.cout + distance(v4.x,v4.y,objx,objy);
			ajout_droit(&openlist,v4);
		}
		
		ajout_droit(&closedlist,q); /*On ajoute la case que l'on vient de tester à la liste*/
	
	}	
	
	printf("Fin du programme\n");	
		
	
    
}
















