/**
*\file global.h
*\brief Ce fichier contient les définitions des primitives d'acces aux listes
*\author Corentin Petit
*\version 1.0
*\date 18/11/2016
*/


int charger_partie( char  nomsave[10], t_liste * ordre_action, int * Nb_tours);
int sauver_partie( char  nomsave[10], t_liste * ordre_action, int Nb_tours);
int choix_save(t_liste * ordre_action, int * Nb_tours);
void quitter_partie(t_liste * ordre_action, int Nb_tours);