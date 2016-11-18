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
#include <curses.h>
#include <string.h>
#include "global.h"
#include"ges_equipes.h"
#include"listes_ptr.h"
#include"liste_chemin.h"
#include"Init_map.h"
#include"deplacement.h"
#include"ges_partie.h"

void clearScreen(){
	const char* CLEAR_SCREE_ANSI = "\e[1;1H\e[2J";
	write(STDOUT_FILENO,CLEAR_SCREE_ANSI,12);
}





int main(void) {
	int choix;
	t_liste equipe1;
	t_liste equipe2;

	/* Initialisation des listes de personnages */
	init_liste(&equipe1);
	init_liste(&equipe2);

	//initscr();
	
	do {		
	
		/* Affichage du menu et saisie du choix */
		printf("\nMenu :\n");
		printf(" 1 - Mode Duel\n");
		printf(" 2 - Mode Arcade\n");
		printf(" 3 - Mode Histoire\n");
		printf(" 4 - Credits\n");
		printf(" 5 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1: init_equipe(&equipe1, 1); init_equipe(&equipe2, 2);break;
			case 2: printf("Ce mode n'est pas encore jouable "); break;
			case 3: printf("Ce mode n'est pas encore jouable "); break;
			case 4: printf("Jeux realise par Corentin Petit Martin Lebourdais et Victor Morgant \n retrouvez nous sur github https://github.com/Vmorgant/Projet_Algo ou sur gitter https://gitter.im/La-Guerre-du-Graal-L2-SPI"); break;
			case 5: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 5\n");
		}
	}
	while(choix!=5);

	printf("Au revoir !\n");
	//endwin();
	return EXIT_SUCCESS;
}
