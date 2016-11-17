#include<stdio.h>

/**
*\file global.h
*\brief Ce fichier contient les définitions de chaque structure globales utilisées dans le projet
*\auteur Corentin Petit Martin Lebourdais Victor Morgant
*\version 1.0
*\date 09/11/2016
*/
typedef enum{mort,enVie}t_etat; /*possibilité d'ajouts futurs*/
/**
*\enum t_etat
*\brief facilite l'identification de l'état d'un personnage
*/

typedef struct{;}t_spe;
/**
*\struct t_spe
*\brief boisson alcoolisée saveur tequila
*/

typedef struct{int coutPA;float mul_ATQ;int portee;int type;}t_attaque;
/**
*\struct t_attaque
*\brief contient les caractéristiques d'une attaque
*/

typedef struct{int coutPE;int PVmax;int gainPA;int ATQ;int DEF;int INI;float poids;t_attaque atq1;t_attaque atq2;t_spe spe;}t_classe;
/**
*\struct t_classe
*\brief contient les caractéristiques d'une classe de personnage
*/

typedef struct{t_classe classe ;t_classe statscour; int joueur; int pa; int pv; int x; int y; t_etat etat;}t_personnage;
/**
*\struct t_personnage
*\brief contient les caractéristiques d'un personnage ainsi que son équipe
*/

typedef struct{t_personnage personnage; struct element* pred; struct element* succ;}t_element;
/**
*\struct t_element
*\brief definition d'une liste de personnage
*/

typedef struct{t_element * drapeau; t_element * ec;}t_liste;
/**
*\struct t_liste
*\brief création du type liste (pour gérer simultanément plusieures listes de type t_personnage
*/


