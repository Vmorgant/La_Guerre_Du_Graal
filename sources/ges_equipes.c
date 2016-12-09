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
/**
 * \fn creer_perso(t_liste * equipe, t_classe classe, int joueur, int * PE)
 * \brief Crée un personnage de la classe choisie.
 * \param t_liste * equipe : la liste des personnage ,t_classe classe : la classe du personnage à ajouter,  int joueur : l'identifiant du joueur, int *PE le nombre de PE restant  .
 */

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
		
	}	
	else {
	printf("Vous n'avez pas les PE requis pour ajouter ce personnage !\n");
	sleep(1);
	}
}

void ajout_equipe(t_liste * equipe, int joueur, int * PE) {
/**
 * \fn ajout_equipe(t_liste * equipe, int joueur, int * PE)
 * \brief Ajoute le personnage à l'équipe.
 * \param t_liste * equipe : la liste des personnage, int joueur : l'identifiant du joueur, int *PE le nombre de PE restant.
 */

	int choix, i, erreur= faux;

	do {
		clearScreen();
		/* Affichage du menu et saisie d'une classe */
		printf("Choisissez une classe : \n\n");
		if(erreur) printf("Erreur: votre choix doit être compris entre 1 et %i\n", nb_classes+1);
		erreur = faux;
		if(!liste_vide(equipe)) {
			printf("l'equipe %i est constituée de : ", joueur);
			afficher(equipe);
			printf("(%iPE restant)\n\n", *PE);
		}else {
			printf("l'equipe %i est vide.", joueur);		
			printf("(%iPE restant)\n\n", *PE);
		}

		for(i =1; i <= nb_classes; i++){
			printf(" %i - %s (%iPE)\n", i, tab_classes[i-1].nom, tab_classes[i-1].coutPE);
		}
		printf("\n %i - /!\\ Retour /!\\\n", nb_classes+1);
		printf("\nVotre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		if(choix >= 1 && choix <= nb_classes){
			creer_perso(equipe, tab_classes[choix-1], joueur, PE);
		} else if (choix < 1 || choix > nb_classes+1) erreur = vrai;

	} while (choix != nb_classes+1);
}



void oter_equipe(t_liste * equipe, int joueur, int *PE){
/**
 * \fn  oter_equipe(t_liste * equipe, int joueur, int *PE)
 * \brief Retire un personnage de la liste.
 * \param t_liste * equipe : la liste des personnage, int joueur : l'identifiant du joueur, int *PE le nombre de PE restant.
 */
	int nb_persos = 0, i, choix;

	compter_elts(equipe, &nb_persos);
	
	if(!liste_vide(equipe)){
		en_tete(equipe);
		/* Affichage du menu et saisie du choix */
		for (i =1; i <= nb_persos; i++){
			printf(" %i - Enlever %s de l'equipe %i\n", i, equipe->ec->personnage.classe.nom, joueur);
			suivant(equipe);
		}
		printf("\n %i - /!\\ Retour /!\\\n", nb_persos+1);
		printf("\nVotre choix : ");
		scanf("%d", &choix);
		/* Traitement du choix de l'utilisateur */
		if(choix >= 1 && choix <= nb_persos){
			en_tete(equipe);
			for (i = 1; i < choix; i++){
					suivant(equipe);
			}
			* PE += equipe->ec->personnage.classe.coutPE;
			oter_elt(equipe);
		}else if (choix == nb_persos+1) printf("Personnage non existant.\n");
	}else printf("L'equipe %i est déjà vide.\n", joueur);
	printf("l'equipe %i est constituée de : ", joueur);
	afficher(equipe);
	printf("(%iPE restant)\n", *PE);
}

void init_equipe(t_liste * equipe, int joueur, int * PE) {
/**
 * \fn  init_equipe(t_liste * equipe, int joueur)
 * \brief Menu de création d'équipe.
 * \param t_liste * equipe : la liste des personnage, int joueur : l'identifiant du joueur.
 */	
	int choix, erreur= faux;

	do {
		clearScreen();
		/* Affichage du menu et saisie du choix */
		printf("Menu :\n");
		if(erreur) printf("Erreur: votre choix doit être compris entre 1 et 4\n");
		erreur = faux;
		if(!liste_vide(equipe)) {
			printf("l'equipe %i est constituée de : ", joueur);
			afficher(equipe);
			printf("(%iPE restant)\n\n", *PE);
		}else {
			printf("l'equipe %i est vide.", joueur);		
			printf("(%iPE restant)\n\n", *PE);
		}

		printf(" 1 - Ajouter un personnage dans l'equipe %i\n", joueur);
		printf(" 2 - Supprimer un personnage de l'equipe %i\n", joueur);
		printf(" 3 - Valider l'équipe %i\n", joueur);
		printf("\n 4 - /!\\ Annuler /!\\\n");
		printf("\nVotre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1: ajout_equipe(equipe, joueur, PE); break;
			case 2: oter_equipe(equipe, joueur, PE); break;
			case 3: break;
			case 4: break;
			default: erreur = vrai;
		}
	}
	while(choix!=4 && choix!=3);
}
