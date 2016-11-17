/**
*\file global.h
*\brief Ce fichier contient les définitions des primitives d'acces aux listes
*\author Corentin Petit
*\version 1.0
*\date 16/11/2016
*/

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "global.h"
#include "ges_equipes.h"
#include"listes_ptr.h"
	
void creer_perso(t_liste * equipe, t_classe classe, int joueur, int * PE) {
	t_personnage perso;
	if(* PE >= classe.coutPE) {
		perso.classe = classe;
		perso.joueur = joueur;
		perso.pa = 5;
		perso.pv = classe.PVmax;
		perso.x = -1;//permettra de savoir si le perso a été placé lors de l'initialisation de la partie
		perso.y = -1;//permettra de savoir si le perso a été placé lors de l'initialisation de la partie
		perso.etat = vie;
		* PE -= classe.coutPE;
		en_queue(equipe);
		ajout_droit(equipe, perso);
		
	} else printf("Vous n'avez pas les PE requis pour ajouter ce personnage !\n");
}

void ajout_equipe(t_liste * equipe, int joueur, int * PE) {
	int choix, i;
	/* Affichage du menu et saisie d'une classe */
	printf("Choisissez une classe : \n");
	for(i =1; i <= nb_classes; i++){
		printf(" %i - %s (%iPE)\n", i, tab_classes[i-1].nom, tab_classes[i-1].coutPE);
	}
	
	scanf("%d",&choix);
	/* Traitement du choix de l'utilisateur */
	if(choix >= 1 && choix <= nb_classes){
		for (i = 1; i <= nb_classes; i++){
			if(choix == i){
				creer_perso(equipe, tab_classes[i-1], joueur, PE);
			}
		}
	}else printf("Classe non existante.\n");
}

void init_partie(){}

void oter_equipe(t_liste * equipe, int joueur, int *PE){
	int nb_persos = 0, i, choix;
	t_personnage perso;

	compter_elts(equipe, &nb_persos);
	
	if(!liste_vide(equipe)){
		en_tete(equipe);
		/* Affichage du menu et saisie du choix */
		for (i =1; i <= nb_persos; i++){
			valeur_elt(equipe, &perso);
			printf(" %i - Enlever %s de l'equipe %i\n", i, perso.classe.nom, joueur);
			suivant(equipe);
		}
		scanf("%d", &choix);
		/* Traitement du choix de l'utilisateur */
		if(choix >= 1 && choix <= nb_persos){
			en_tete(equipe);
			for (i = 1; i < choix; i++){
					suivant(equipe);
			}printf("YO => La valeur de choix est %i, de i es %i\nPersonnage courrent : %s, %i\n", choix, i, equipe->ec->personnage.classe.nom, joueur);
			* PE += equipe->ec->personnage.classe.coutPE;
			oter_elt(equipe);
		}else printf("Personnage non existant.\n");
	}else printf("L'equipe %i est déjà vide.\n", joueur);
}

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
			case 2: oter_equipe(equipe, joueur, &PE); afficher(equipe); break;
			case 3: init_partie();
			case 4: break;
			default: printf("Erreur: votre choix doit être compris entre 1 et 3\n");
		}
	}
	while(choix!=3);
	printf(" !\n");
}