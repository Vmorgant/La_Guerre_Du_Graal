#include "global.h"

/**
*\file classes.c
*\brief Ce fichier contient les définitions de chaque classes
*\author Victor Morgant, Corentin Petit
*\version 1.0
*\date 09/11/2016
*/

t_classe tab_classes[nb_classes]= {
	//int coutPE int PVmax,int gainPA,int ATQ,int DEF,int INI, float poids, atq 1, atq 2;
	{"Saber",3,50,3,10,5,10,10, {3,1,1,1},{5,2,1,1}/*,ulti*/},
	{"Archer",5,50,3,10,5,10,10, {3,1,1,1},{5,2,1,1}/*,ulti*/},
	{"Caster",2,50,3,10,5,10,10, {3,1,1,1},{5,2,1,1}/*,ulti*/},
};

/**
*\struct t_classe Sab
*\brief Définition de la classe Saber correspondant à un attaquant corps à corps
*/

