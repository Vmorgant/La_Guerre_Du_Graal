/**
*\file Init_map.h
*\brief Création de la map
*\version 1.0
*\author Martin Lebourdais
*\date 18/11/2016
*/


#define couleur(param) printf("\033[%sm",param)

t_map creerMat();
void afficherMat (t_map mat);
t_map actumap(t_liste * ordreaction, t_map map);
void free_map(t_map map);