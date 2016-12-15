/**
*\file global.h
*\brief Ce fichier contient les définitions des primitives d'acces aux listes
*\author Corentin Petit
*\version 1.0
*\date 18/11/2016
*/


int charger_save( char  nomsave[34], t_liste * ordre_action, int Nb_tours);
int enregistrer_save( char  nomsave[34], t_liste * ordre_action, int * Nb_tours);
void charger_partie();
void nouvelle_partie();
void quitter_partie(t_liste * ordre_action, int Nb_tours, int *gagnant);