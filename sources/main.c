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
	system("clear");
}
void lancer1v1() {

	t_liste equipe1;
	t_liste equipe2;
	t_liste ordre_action;
	t_map carte=creerMat();

	int choix, erreur = faux;
	int NbTour=1;
	int gagnant=0; 
	int PE1 = 10;
	int PE2 = 10;

	/* Initialisation des listes de personnages */
	init_liste(&equipe1);
	init_liste(&equipe2);
	init_liste(&ordre_action);
	
	/* Affichage du menu et saisie du choix */
	do  {
		clearScreen();
		if(erreur) printf("Erreur: votre choix doit être compris entre 1 et 4\n");
		erreur = faux;
		printf(" 1- Editer equipe 1.\t\t");
		if(!liste_vide(&equipe1)) {
			printf("L'equipe 1 est constituée de : ");
			afficher(&equipe1);
			printf("(%iPE restant)\n", PE1);
		}else {
			printf("L'equipe 1 est vide.");		
			printf("(%iPE restant)\n", PE1);
		}

		printf(" 2- Editer equipe 2.\t\t");
		if(!liste_vide(&equipe2)) {
			printf("L'equipe 2 est constituée de : ");
			afficher(&equipe2);
			printf("(%iPE restant)\n", PE2);
		}else {
			printf("L'equipe 2 est vide.");		
			printf("(%iPE restant)\n", PE2);
		}

		printf(" 3- Lancer Partie.\n");
		printf("\n 4- /!\\Retour /!\\.\n");
		printf("\nVotre choix : ");
		scanf("%d", &choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1: init_equipe(&equipe1, 1, &PE1); break;
			case 2: init_equipe(&equipe2, 2, &PE2);  break;
			case 3: if(liste_vide(&equipe1) || liste_vide(&equipe2) ){
					printf("Erreur les deux equipes ne doivent pas etre vides\n");
					sleep(1);
					break;
				}
				else{
					afficherMat(carte);
					init_partie(&equipe1,&equipe2,&ordre_action);
					placer(&ordre_action,carte);
					while (gagnant == 0){
						gestion_tour(&ordre_action,&NbTour, &carte,&gagnant);
					}
					printf("Le joueur %i a gagné en %i tours\n",gagnant,NbTour);
                                        sleep(1);
					choix = 4;
					break;
				}
			default: erreur = vrai;
		}
	
	}while(choix!=4);
}


int main(void) {
	int choix, erreur = faux;
	//initscr();
	
	do {		
		clearScreen();	
	
		printf("Menu :\n");
		if(erreur) printf("Erreur: votre choix doit etre compris entre 1 et 5\n");
		erreur = faux;
		/* Affichage du menu et saisie du choix */
		
		printf(" 1 - Mode Duel\n");
		printf(" 2 - Mode Arcade\n");
		printf(" 3 - Mode Histoire\n");
		printf(" 4 - Credits\n");
		printf(" 5 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1: lancer1v1(); break;
			case 2: printf("Ce mode n'est pas encore jouable "); break;
			case 3: printf("Ce mode n'est pas encore jouable "); break;
			case 4: printf("Jeux realise par Corentin Petit Martin Lebourdais et Victor Morgant \n retrouvez nous sur github https://github.com/Vmorgant/Projet_Algo ou sur gitter https://gitter.im/La-Guerre-du-Graal-L2-SPI"); break;
			case 5: break;
			default: erreur = vrai;
		}
	
	}
	while(choix!=5);

	printf("Au revoir !\n");
	//endwin();
	return EXIT_SUCCESS;
}
