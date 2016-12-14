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
	char mretour[100] = "\n";

	/* Initialisation des listes de personnages */
	init_liste(&equipe1);
	init_liste(&equipe2);
	init_liste(&ordre_action);
	
	/* Affichage du menu et saisie du choix */
	do  {
		clearScreen();
		printf("Menu :\n");
		if(erreur) {
			couleur("31");
			printf("%s", mretour);
			couleur("0");
		}else printf("\n");
		erreur = faux;
		printf(" 1- Editer equipe 1.\t\t");
		if(!liste_vide(&equipe1)) {
			printf("L'equipe 1 est constituée de : ");
			couleur("34;1");
			afficher(&equipe1);
			couleur("0");
			printf("(%iPE restant)\n", PE1);
		}else {
			printf("L'equipe 1 est vide.");		
			printf("(%iPE restant)\n", PE1);
		}

		printf(" 2- Editer equipe 2.\t\t");
		if(!liste_vide(&equipe2)) {
			printf("L'equipe 2 est constituée de : ");
			couleur("31;1");
			afficher(&equipe2);
			couleur("0");
			printf("(%iPE restant)\n", PE2);
		}else {
			printf("L'equipe 2 est vide.");		
			printf("(%iPE restant)\n", PE2);
		}

		printf(" 3- Charger une sauvegarde.\n");
		printf(" 4- Lancer Partie.\n");
		printf("\n 5- Retour.\n");
		printf("\nVotre choix : ");
		scanf("%d", &choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1: init_equipe(&equipe1, 1, &PE1); break;
			case 2: init_equipe(&equipe2, 2, &PE2);  break;
			case 3: if(choix_save(&ordre_action, &NbTour)) {
					carte = actumap(&ordre_action,carte);
					afficherMat(carte);
					while (gagnant == 0){
						gestion_tour(&ordre_action,&NbTour, &carte,&gagnant);
					}
					printf("Le joueur %i a gagné en %i tours\n",gagnant,NbTour);
		                               sleep(1);
					choix = 5;
				} else { 
					printf("Cette sauvegarde est vide\n"); 
					sleep(1); 
				}
				break;
			case 4: if(liste_vide(&equipe1) || liste_vide(&equipe2) ){
					strcpy(mretour, "\tLes deux equipes ne doivent pas etre vides\n");
					erreur = vrai;
					break;
				}
				else{			
					init_partie(&equipe1,&equipe2,&ordre_action);
					placer(&ordre_action, &carte);
					carte=actumap(&ordre_action, carte);
					afficherMat(carte);
					while (gagnant == 0){
						gestion_tour(&ordre_action,&NbTour, &carte,&gagnant);
					}
					printf("Le joueur %i a gagné en %i tours\n",gagnant,NbTour);
                                        sleep(1);
					choix = 5;
					break;
				}
			default: strcpy(mretour, "\tVotre choix doit être compris entre 1 et 4\n"); erreur = vrai;
		}
	
	}while(choix!=5);
	
	/*supprimer(&equipe1);
	supprimer(&equipe2);
	supprimer(&ordre_action);*/
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
		
		printf(" 1 - Mode Duel\n");
		printf(" 2 - Credits\n");
		printf(" 3 - Quitter\n");
		printf("\nVotre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1: lancer1v1(); choix = 3; break;
			case 2: printf("\nJeux realise par Corentin Petit Martin Lebourdais et Victor Morgant \n retrouvez nous sur github https://github.com/Vmorgant/Projet_Algo ou sur gitter https://gitter.im/La-Guerre-du-Graal-L2-SPI"); break;
			case 3: break;
			default: erreur = vrai;
		}
	
	}
	while(choix!=3);

	printf("Au revoir !\n");
	sleep(2);
	clearScreen();
	return EXIT_SUCCESS;
}
