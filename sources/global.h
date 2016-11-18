#ifndef GLOBAL_H

#define GLOBAL_H

#include<stdio.h>

/**
*\file global.h
*\brief Ce fichier contient les définitions de chaque structure globales utilisées dans le projet
*\author Corentin Petit, Martin Lebourdais, Victor Morgant
*\version 1.0
*\date 09/11/2016
*/
typedef enum{mort,vie}t_etat; /*possibilité d'ajouts futurs*/
/**
*\enum t_etat
*\brief facilite l'identification de l'état d'un personnage
*/

typedef struct{int coutPA;float mul_ATQ;int portee;int type;}t_spe;
/**
*\struct t_spe
*\brief boisson alcoolisée saveur tequila
*/

typedef struct{char nom[20];int coutPA;float mul_ATQ;int portee;int type;}t_attaque;
/**
*\struct t_attaque
*\brief contient les caractéristiques d'une attaque
*/

typedef struct{char nom[20]; int coutPE;int PVmax;int gainPA;int ATQ;int DEF;int INI;float poids;t_attaque atq1;t_attaque atq2;/*t_spe spe;*/}t_classe;
/**
*\struct t_classe
*\brief contient les caractéristiques d'une classe de personnage
*/

typedef struct{t_classe classe ; int joueur; int pa; int pv; int x; int y; t_etat etat;}t_personnage;
/**
*\struct t_personnage
*\brief contient les caractéristiques d'un personnage ainsi que son équipe
*/








typedef struct element{t_personnage personnage; struct element* pred; struct element* succ;}t_element;
/**
*\struct t_element
*\brief definition d'une liste de personnage
*/

typedef struct{t_element * drapeau; t_element * ec;}t_liste;
/**
*\struct t_liste
*\brief création du type liste (pour gérer simultanément plusieures listes de type t_personnage
*/






typedef struct{int x; int y; int cout; int heuristique;}t_noeud;
/**
*\struct t_noeud 
*\brief contient les coordonnées d'un noeud et son poids
*/

typedef struct element_noeud{t_noeud noeud; struct element_noeud* pred; struct element_noeud* succ;}t_element_noeud;
/**
*\struct t_element_noeud
*\brief definition d'une liste de noeud
*/

typedef struct{t_element_noeud * drapeau; t_element_noeud * ec;}t_liste_noeud;
/**
*\struct t_liste_noeud
*\brief création du type liste (pour gérer simultanément plusieures listes de type t_noeud)
*/







#define nb_classes 3
extern t_classe tab_classes[nb_classes];


#endif
