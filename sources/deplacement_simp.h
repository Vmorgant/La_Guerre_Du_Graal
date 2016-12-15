/**
*\file deplacement_simp.h
*\brief Ce fichier contient les en-tête de la version simplifiée des fonctions de déplacement sur la carte.
*\author Martin Lebourdais
*\version 1.0
*\date 22/11/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"
#include "file_chemin.h"
#include "Init_map.h"

float distance(int x,int y,int objx,int objy);
/**
 * \fn  distance(int x,int y,int objx,int objy)
 * \brief Calcule le carré de la distance entre le point de départ et l'objectif
 * \param int x : Abscisse de départ, int y : Ordonnée de départ, int xobj : Abscisse cible; int yobj : Ordonnée cible
 */
int pathfinding(int x, int y,int objx,int objy,t_noeud chemin[50],int * taille,t_map map);
/**
 * \fn  pathfinding(int x, int y,int objx,int objy)
 * \brief Trouve le chemin le plus court entre le point de départ et l'objectif et retourne ce chemin dans une file.
 * \param int x : Abscisse de départ, int y : Ordonnée de départ, int xobj : Abscisse cible; int yobj : Ordonnée cible
 */
void deplacement(t_liste *ordre_action,t_map map);
/**
 * \fn  deplacement_simp(t_liste *ordre_action,t_map map)
 * \brief Version simplifiée de la fonction déplacement.
 * \param t_liste *ordre_action : ordre de jeu des personnages (util pour connaître le personnage qui se déplace),t_map map : Plateau de jeu
 */

