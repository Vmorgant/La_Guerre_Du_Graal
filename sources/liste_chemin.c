/**
*\file gliste_chemin.c
*\brief 
*\author Martin Lebourdais
*\version 1.0
*\date 14/11/2016
*/
#include<stdio.h>
#include<stdlib.h>
#include "global.h"
#include "deplacement.h"


void init_liste_noeud(t_liste_noeud * p) {
	p->drapeau =  malloc (sizeof(t_element_noeud));
	p->ec =  malloc (sizeof(t_element_noeud));
	p->drapeau -> pred = p->drapeau;
	p->drapeau -> succ = p->drapeau;
	p->ec = p->drapeau;
}

int liste_vide_noeud(t_liste_noeud * p) {
	if(p->drapeau -> pred == p->drapeau)
		return 1;
	else return 0;
}

int hors_liste_noeud(t_liste_noeud * p) {
	if(p->ec == p->drapeau)
		return 1;
	else return 0;
}

void en_tete_noeud(t_liste_noeud * p) {
	p->ec = p->drapeau -> succ;
}

void en_queue_noeud(t_liste_noeud * p) {
	p->ec = p->drapeau -> pred;
}

void suivant_noeud(t_liste_noeud * p) {
	if (!hors_liste_noeud(p)){
		p->ec = p->ec -> succ;
	}
}

void precedent_noeud(t_liste_noeud * p) {
	if (!hors_liste_noeud(p)){
		p->ec = p->ec -> pred;
	}
}

void valeur_elt_noeud(t_liste_noeud * p, t_noeud * v) {
	if(!hors_liste_noeud(p))
		*v = p->ec -> valeur;
}

void modif_elt_noeud(t_liste_noeud * p, t_noeud v) {
	if(!hors_liste_noeud(p))
		p->ec -> valeur = v;
}

void oter_elt_noeud(t_liste_noeud * p) {
	if(!hors_liste_noeud(p)) {
		t_element_noeud * temp;
		temp = malloc (sizeof(t_element_noeud));
		temp = p->ec;
		suivant(p);
		p->ec -> pred = temp -> pred;
		precedent(p);
		p->ec -> succ = temp -> succ;
		free(temp);
	}
}

void ajout_droit_noeud(t_liste_noeud * p, t_noeud v) {
	if (liste_vide_noeud (p) || !hors_liste_noeud(p) ) {
		t_element_noeud * nouv;
		nouv = malloc (sizeof(t_element_noeud));
		nouv -> valeur = v;
		nouv -> succ = p->ec -> succ;
		nouv -> pred = p->ec;
		p->ec -> succ = nouv;
		p->(ec -> succ) -> pred = nouv;
	}
}

void ajout_gauche_noeud(t_liste_noeud * p, t_noeud v) {
	if (liste_vide_noeud (p) || !hors_liste_noeud (p) ) {
		t_element_noeud * nouv;
		nouv = malloc (sizeof(t_element_noeud));
		nouv -> valeur = v;
		nouv -> succ = p->ec;
		nouv -> pred = p->ec -> pred;
		p->ec -> pred = nouv;
		p->(ec -> pred) -> succ = nouv;
	}
}