/**
*\file liste_chemin.c
*\brief 
*\author Martin Lebourdais
*\version 1.0
*\date 14/11/2016
*/
#include<stdio.h>
#include<stdlib.h>
#include "global.h"
#include "deplacement.h"
#include "liste_chemin.h"

void init_liste_noeud(t_liste_noeud * p) {
/**
 * \fn init_liste_noeud(t_liste_noeud * p)
 * \brief initialisation de la liste de noeud.
 * \param t_liste_noeud * p pointeur sur la liste
 */
	p->drapeau_noeud =  malloc (sizeof(t_element_noeud));
	p->ec_noeud =  malloc (sizeof(t_element_noeud));
	p->drapeau_noeud -> pred_noeud = p->drapeau_noeud;
	p->drapeau_noeud -> succ_noeud = p->drapeau_noeud;
	p->ec_noeud = p->drapeau_noeud;
}

int liste_vide_noeud(t_liste_noeud * p) {
/**
 * \fn liste_vide_noeud(t_liste_noeud * p)
 * \brief vérifie si la liste de noeud est vide
 * \param t_liste_noeud * p pointeur sur  la liste
 * \return 1 si la liste est vide 
 */
	if(p->drapeau_noeud -> pred_noeud == p->drapeau_noeud)
		return 1;
	else return 0;
}

int hors_liste_noeud(t_liste_noeud * p) {
/**
 * \fn hors_liste_noeud(t_liste_noeud * p)
 * \brief vérifie si on se trouve en dehors de la liste
 * \param t_liste_noeud * p pointeur sur la liste
 * \return 1 si on se trouve en dehors de la liste
 */
	if(p->ec_noeud == p->drapeau_noeud)
		return 1;
	else return 0;
}

void en_tete_noeud(t_liste_noeud * p) {
/**
 * \fn en_tete_noeud(t_liste_noeud * p)
 * \brief vérifie si on se trouve en tete de la liste
 * \param t_liste_noeud * p pointeur sur la liste
 */
	p->ec_noeud = p->drapeau_noeud -> succ_noeud;
}

void en_queue_noeud(t_liste_noeud * p) {
	p->ec_noeud = p->drapeau_noeud -> pred_noeud;
}

void suivant_noeud(t_liste_noeud * p) {
	if (!hors_liste_noeud(p)){
		p->ec_noeud = p->ec_noeud -> succ_noeud;
	}
}

void precedent_noeud(t_liste_noeud * p) {
	if (!hors_liste_noeud(p)){
		p->ec_noeud = p->ec_noeud -> pred_noeud;
	}
}

void valeur_elt_noeud(t_liste_noeud * p, t_noeud * v) {
	if(!hors_liste_noeud(p))
		*v = p->ec_noeud -> noeud;
}

void modif_elt_noeud(t_liste_noeud * p, t_noeud v) {
	if(!hors_liste_noeud(p))
		p->ec_noeud -> noeud = v;
}

void oter_elt_noeud(t_liste_noeud * p) {
	if(!hors_liste_noeud(p)) {
		t_element_noeud * temp;
		temp = malloc (sizeof(t_element_noeud));
		temp = p->ec_noeud;
		suivant_noeud(p);
		p->ec_noeud -> pred_noeud = temp -> pred_noeud;
		precedent_noeud(p);
		p->ec_noeud -> succ_noeud = temp -> succ_noeud;
		free(temp);
	}
}

void ajout_droit_noeud(t_liste_noeud * p, t_noeud v) {
	if (liste_vide_noeud (p) || !hors_liste_noeud(p) ) {
		t_element_noeud * nouv;
		nouv = malloc (sizeof(t_element_noeud));
		nouv -> noeud = v;
		nouv -> succ_noeud = p->ec_noeud -> succ_noeud;
		nouv -> pred_noeud = p->ec_noeud;
		p->ec_noeud -> succ_noeud = nouv;
		p->ec_noeud -> succ_noeud -> pred_noeud = nouv;
	}
}

void ajout_gauche_noeud(t_liste_noeud * p, t_noeud v) {
	if (liste_vide_noeud (p) || !hors_liste_noeud (p) ) {
		t_element_noeud * nouv;
		nouv = malloc (sizeof(t_element_noeud));
		nouv -> noeud = v;
		nouv -> succ_noeud = p->ec_noeud;
		nouv -> pred_noeud = p->ec_noeud -> pred_noeud;
		p->ec_noeud -> pred_noeud = nouv;
		p->ec_noeud -> pred_noeud -> succ_noeud = nouv;
	}
}
