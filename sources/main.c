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
#include "../includes/global.h"
#include"../includes/ges_equipes.h"
#include"../includes/listes_ptr.h"
#include"../includes/file_chemin.h"
#include"../includes/Init_map.h"
#include"../includes/deplacement_simp.h"
#include"../includes/ges_partie.h"
#include "../includes/save.h"


void scanclav(char chaine[200], int i){
/**
 * \fn clearScreen
 * \brief Fonction pour recupérer une saisie clavier
 * \param char chaine[200] : chiane dans laqulle ont stocke la saisie, int i : taille maximum de la chaine à lire
 */
	char *p, c;

	if(c = fgets(chaine, i+1, stdin) != NULL){}; /* recupère la chaine */
	if(strchr(chaine, '\n') == NULL){ /* revide le buffer au cas ou il y ai plus de 30 caractères */
		while ((c = getchar()) != '\n' &&  c != EOF){} 
	}
	p = strchr(chaine, '\n'); /* cherche le '\n' à la fin */
	if (p) *p = 0; /* enleve le '\n' à la fin */
}

void clearScreen(){
/**
 * \fn clearScreen
 * \brief Fonction permettant d'effacer l'écran
 */
	system("clear");
}


int main(void) {
	int choix, erreur = faux;
	
	char mretour[100]="\n";
	char chaine[30];
	char* fin = NULL;
	char temp[50];
clearScreen();
couleur("33;1");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t __          ___           _______  __    __   _______ .______      .______       _______     _______   __    __       _______ .______          ___           ___       __      \n");
printf("\t\t\t|  |        /   \\         /  _____||  |  |  | |   ____||   _  \\     |   _  \\     |   ____|   |       \\ |  |  |  |     /  _____||   _  \\        /   \\         /   \\     |  |     \n");
printf("\t\t\t|  |       /  ^  \\       |  |  __  |  |  |  | |  |__   |  |_)  |    |  |_)  |    |  |__      |  .--.  ||  |  |  |    |  |  __  |  |_)  |      /  ^  \\       /  ^  \\    |  |     \n");
printf("\t\t\t|  |      /  /_\\  \\      |  | |_ | |  |  |  | |   __|  |      /     |      /     |   __|     |  |  |  ||  |  |  |    |  | |_ | |      /      /  /_\\  \\     /  /_\\  \\   |  |     \n");
printf("\t\t\t|  `----./  _____  \\     |  |__| | |  `--'  | |  |____ |  |\\  \\----.|  |\\  \\----.|  |____    |  '--'  ||  `--'  |    |  |__| | |  |\\  \\----./  _____  \\   /  _____  \\  |  `----.\n");
printf("\t\t\t|_______/__/     \\__\\     \\______|  \\______/  |_______|| _| `._____|| _| `._____||_______|   |_______/  \\______/      \\______| | _| `._____/__/     \\__\\ /__/     \\__\\ |_______|\n");

printf("\n\n");
couleur("0");
printf("\t\t\t\t\t\t\t\t\t\t\t Appuyez sur Entrée pour continuer ");
scanclav(mretour, 0);


	
	do {		
		clearScreen();	
	
		printf("Menu :\n");
		if(erreur) {
			couleur("31");
			printf("%s", mretour);
			couleur("0");
		} else {
			couleur("32");
			printf("%s", mretour);
			couleur("0");
		}
		strcpy(mretour, "\n");
		erreur = faux;
		/* Affichage du menu et saisie du choix */
		
		printf(" 1 - Nouvelle Partie\n");
		printf(" 2 - Charger une partie\n");
		printf(" 3 - Gestion des sauvegardes\n");
		printf(" 4 - Credits\n");
		printf(" 5 - Quitter\n");
		printf("\nVotre choix : ");
		scanclav(chaine, 30);
		choix = strtol(chaine, &fin, 10);

		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1: nouvelle_partie(mretour); break;
			case 2: charger_partie(mretour); break;
			case 3: gerer_save(mretour); break;
			case 4: strcpy(mretour, "\tJeux realise par Corentin Petit Martin Lebourdais et Victor Morgant \n retrouvez nous sur github https://github.com/Vmorgant/Projet_Algo ou sur gitter https://gitter.im/La-Guerre-du-Graal-L2-SPI"); break;
			case 5: break;
			default: strcpy(mretour, "\tErreur: votre choix doit etre compris entre 1 et 3\n"); erreur = vrai;
		}
	
	}
	while(choix!=5);

	printf("Au revoir !\n");
	sleep(2);
	clearScreen();
	return EXIT_SUCCESS;
}
