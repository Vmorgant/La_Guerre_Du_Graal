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
	{"Saber",4,50,4,8,4,10,10, {"Coup d'epee",3,1,1,1},{"Coup puissant",5,1.5,1,1}/*,ulti*/},
	{"Archer",6,30,2,7,3,15,6, {"Tir",2,1,2,1},{"Tir puissant",7,1.8,5,2}/*,ulti*/},
	{"Caster",2,20,3,10,1,5,6, {"Gandr",3,0.8,2,1},{"Brasier",7,1.1,3,2}/*,ulti*/},
        {"Berserker",10,150,1,12,4,2,18, {"Frapper",3,1,1,1},{"Destruction",9,2.6,3,2}/*,ulti*/},
        {"Lancer",4,60,2,10,3,12,8, {"Transpercer",3,1,1,1},{"Empaler",5,1.5,2,2}/*,ulti*/},
        {"Rider",3,20,3,5,3,7,1, {"Fauchage",3,1,1,1},{"TUA",4,1.3,1,1}/*,ulti*/},
        {"Assassin",3,20,5,10,2,20,4, {"Evisceration",4,1.1,1,1},{"Coupe Gorge",8,2,1,1}/*,ulti*/},
};

/**
*\struct t_classe tab_classes
*\brief Définition des différentes classes de personnages
*/

