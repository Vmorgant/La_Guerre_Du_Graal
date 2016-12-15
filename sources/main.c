/**
*\file main.c
*\brief Menu principal et lancement de la partie
*\version 1.0
*\auteur Corentin Petit
*\date 11/11/2016
*/
#include<stdio.h>
#include<stdlib.h> 
#include <unistd.h>
#include <string.h>
#include "global.h"
#include"ges_equipes.h"
#include"listes_ptr.h"
#include"file_chemin.h"
#include"Init_map.h"
#include"deplacement_simp.h"
#include"ges_partie.h"
#include "save.h"

void clearScreen(){
	system("clear");
}

int main(void) {
	int choix, erreur = faux;
	
	do {		
		clearScreen();	
	
		printf("Menu :\n");
		if(erreur) {
			couleur("31");
			printf("\tErreur: votre choix doit etre compris entre 1 et 3\n");
			couleur("0");
		} else printf("\n");
		erreur = faux;
		/* Affichage du menu et saisie du choix */
		
		printf(" 1 - Nouvelle Partie\n");
		printf(" 2 - Charger une partie\n");
		printf(" 3 - Credits\n");
		printf(" 4 - Quitter\n");
		printf("\nVotre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1: nouvelle_partie(); break;
			case 2: charger_partie(); break;
			case 3: printf("\nJeux realise par Corentin Petit Martin Lebourdais et Victor Morgant \n retrouvez nous sur github https://github.com/Vmorgant/Projet_Algo ou sur gitter https://gitter.im/La-Guerre-du-Graal-L2-SPI"); break;
			case 4: break;
			default: erreur = vrai;
		}
	
	}
	while(choix!=4);

	printf("Au revoir !\n");
	sleep(2);
	clearScreen();
	return EXIT_SUCCESS;
}
