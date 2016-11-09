#include<stdio.h>
#include<stdlib.h>

void init_liste(liste * p) {
	p->drapeau =  malloc (sizeof(t_element));
	p->ec =  malloc (sizeof(t_element));
	p->drapeau -> pred = p->drapeau;
	p->drapeau -> succ = p->drapeau;
	p->ec = p->drapeau;
}

int liste_vide (liste * p) {
	if(p->drapeau -> pred == p->drapeau)
		return 1;
	else return 0;
}

int hors_liste (liste * p) {
	if(p->ec == p->drapeau)
		return 1;
	else return 0;
}

void en_tete (liste * p) {
	p->ec = p->drapeau -> succ;
}

void en_queue (liste * p) {
	p->ec = p->drapeau -> pred;
}

void suivant(liste * p) {
	if (!hors_liste(p)){
		p->ec = p->ec -> succ;
	}
}

void precedent(liste * p) {
	if (!hors_liste(p)){
		p->ec = p->ec -> pred;
	}
}

void valeur_elt(liste * p, int * v) {
	if(!hors_liste)
		*v = p->ec -> valeur;
}

void modif_elt(liste * p, int v) {
	if(!hors_liste(p))
		p->ec -> valeur = v;
}

void oter_elt(liste * p) {
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

void ajout_droit(liste * p, int v) {
	if (liste_vide(p) || !hors_liste(p) ) {
		t_element * nouv;
		nouv = malloc (sizeof(t_element));
		nouv -> valeur = v;
		nouv -> succ = p->ec -> succ;
		nouv -> pred = p->ec;
		p->ec -> succ = nouv;
		p->(ec -> succ) -> pred = nouv;
	}
}

void ajout_gauche(liste * p, int v) {
	if (liste_vide(p) || !hors_liste(p) ) {
		t_element * nouv;
		nouv = malloc (sizeof(t_element));
		nouv -> valeur = v;
		nouv -> succ = p->ec;
		nouv -> pred = p->ec -> pred;
		p->ec -> pred = nouv;
		p->(ec -> pred) -> succ = nouv;
	}
}