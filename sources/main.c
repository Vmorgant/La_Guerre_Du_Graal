/**
*\file main.c
*\brief Menu principal et lancement de la partie
*\version 1.0
*\auteur Victor Morgant, Corentin Petit
*\date 11/11/2016
*/
#include<stdio.h>
#include<stdlib.h>
#include "global.h"
#include"listes_ptr.h"

	
void creer_perso(t_liste * equipe, t_personnage * perso, t_classe classe, int joueur, int * PE) {
	if(* PE >= classe.coutPE) {
		perso->classe = classe;
		perso->joueur = joueur;
		perso->pa = 5;
		perso->pv = classe.PVmax;
		perso->x = -1;//permettra de savoir si le perso a été placé lors de l'initialisation de la partie
		perso->y = -1;//permettra de savoir si le perso a été placé lors de l'initialisation de la partie
		perso->etat = vie;
		* PE -= classe.coutPE;
		ajout_droit(equipe, *perso); 
		
	} else printf("Vous n'avez pas les PE requis pour ajouter ce personnage !\n");
}

void ajout_equipe(t_liste * equipe, int joueur, int * PE) {
	int choix;
	t_personnage p_nouv;
	
	/* Affichage du menu et saisie d'une classe */
	printf("\nMenu :\n");
	printf(" 1 - Saber\n");
	printf("Choisissez une classe : ");
	scanf("%d",&choix);
	/* Traitement du choix de l'utilisateur */
	switch(choix) {
		case 1: creer_perso(equipe, &p_nouv, sab, joueur, PE); break;
		default: printf("Erreur: votre choix doit �tre compris entre 1 et 1\n");
	}
}

void init_partie(){}

void oter_equipe(){}

void init_equipe(t_liste * equipe, int joueur) {	
	int choix;
	int PE = 9;

	do {
		/* Affichage du menu et saisie du choix */
		printf("\nMenu :\n");
		printf(" 1 - Ajouter un personnage dans l'equipe %i\n", joueur);
		printf(" 2 - Supprimer un personnage de l'equipe %i\n", joueur);
		printf(" 3 - Valider l'équipe %i\n", joueur);
		printf("Votre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1: ajout_equipe(equipe, joueur, &PE);  afficher(equipe); break;
			case 2: oter_equipe(); afficher(equipe); break;
			case 3: init_partie();
			case 4: break;
			default: printf("Erreur: votre choix doit �tre compris entre 1 et 3\n");
		}
	}
	while(choix!=3);
	printf(" !\n");
}









































int main(void) {
	int choix;
	t_liste equipe1;
	t_liste equipe2;

	/* Initialisation des listes de personnages */
	init_liste(&equipe1);
	init_liste(&equipe2);
	
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
	return EXIT_SUCCESS;
}
