/**
*\file global.h
*\brief Ce fichier contient les définitions des primitives d'acces aux listes
*\author Corentin Petit
*\version 1.0
*\date 09/11/2016
*/

void init_liste(t_liste*);
int liste_vide(t_liste*);
int hors_liste(t_liste*);
void en_tete(t_liste*);
void en_queue(t_liste*);
void precedent(t_liste*);
void suivant(t_liste*);
void valeur_elt(t_liste*,t_personnage*);
void modif_elt(t_liste*,t_personnage);
void oter_elt(t_liste*);
void ajout_droit(t_liste*,t_personnage);
void ajout_gauche(t_liste*,t_personnage);
void afficher(t_liste*);
void compter_elts(t_liste*,int*);
void vider(t_liste* p);
void supprimer(t_liste* p);