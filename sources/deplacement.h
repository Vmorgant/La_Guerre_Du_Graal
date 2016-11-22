/**
*\file deplacement.h
*\brief Ce fichier contient les en-tête des fonctions pour le déplacement
*\author Lebourdais Martin
*\version 1.0
*\date 22/11/2016
*/

void permuter(t_noeud *actuel,t_noeud *suivant);
int existinf(t_liste_noeud liste,t_noeud valeur);
int distance(int x,int y,int objx,int objy);
int cout_dep(t_liste * ordre_action);
int nb_case(t_liste_noeud *liste);
void pathfinding(int x, int y,int objx,int objy);
void deplacement(t_liste *ordre_action,t_map map);