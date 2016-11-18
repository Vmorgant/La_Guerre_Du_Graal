/**
*\file Init_map.c
*\brief Création de la map
*\version 1.0
*\author Martin Lebourdais
*\date 18/11/2016
*/

typedef struct{int nlignes,ncolonnes;int ** cell;}t_map;

#define couleur(param) printf("\033[%sm",param)

t_map creerMat();
void afficherMat (t_map mat);
t_map actumap(t_personnage * ordreaction, t_map map);

