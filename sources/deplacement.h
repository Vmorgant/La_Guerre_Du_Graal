/**
*\file global.h
*\brief Ce fichier contient les définitions des primitives d'acces aux listes
*\author Corentin Petit
*\version 1.0
*\date 18/11/2016
*/

void permuter(t_noeud *actuel,t_noeud *suivant);
int existinf(t_liste_noeud liste,t_noeud valeur);
int distance(int x,int y,int objx,int objy);
void pathfinding(int x, int y,int objx,int objy);
void deplacement(t_liste *ordre_action,t_map map);