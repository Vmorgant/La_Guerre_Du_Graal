/**
*\file global.h
*\brief Ce fichier contient les définitions des primitives d'acces aux listes
*\author Corentin Petit
*\version 1.0
*\date 16/11/2016
*/

void creer_perso(t_liste * equipe, t_classe classe, int joueur, int * PE);
void ajout_equipe(t_liste * equipe, int joueur, int * PE);
void init_partie();
void oter_equipe(t_liste * equipe, int joueur, int* PE);
void init_equipe(t_liste * equipe, int joueur);