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
	{"Saber",3,50,3,9,4,10,10, {"Coup d'epee",3,1,1,1},{"Coup puissant",5,2,1,1}/*,ulti*/},
	{"Archer",5,30,3,10,3,15,7, {"Tir",3,1,2,1},{"Tir puissant",7,2,5,1}/*,ulti*/},
	{"Caster",3,20,3,10,2,12,8, {"Gandr",3,1,2,1},{"Brasier",5,2,2,1}/*,ulti*/},
        {"Berserker",9,100,3,7,5,7,15, {"Frapper",3,1,1,1},{"Destruction",5,3,1,1}/*,ulti*/},
        {"Lancer",3,50,3,10,4,10,7, {"Tranpercer",3,1,2,1},{"Empaler",5,2,2,1}/*,ulti*/},
        {"Rider",3,20,3,10,2,17,5, {"Eclair",3,1,2,1},{"Brasier",5,2,2,1}/*,ulti*/},
        {"Assassin",3,20,3,10,2,12,5, {"Trancher",3,1,2,1},{"Brasier",5,2,2,1}/*,ulti*/},
};

/**
*\struct t_classe tab_classes
*\brief Définition des différentes classes de personnages
*/

