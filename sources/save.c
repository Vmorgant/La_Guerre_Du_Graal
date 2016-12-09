#include<stdio.h>
#include<stdlib.h>
#include "global.h"
#include "listes_ptr.h"

/**
*\file save.c
*\brief Ce fichier contient les définitions des fonctions permattant de sauvegarder et charger une partie
*\author Corentin Petit
*\version 1.0
*\date 05/12/2016
*/

int charger_partie( char  nomsave[10], t_liste * ordre_action, int * Nb_tours) {
/**
 * \fn  charger_partie( char  nomsave[10])
 * \brief Charge les données d'une sauvegarde passée en paramètre
 * \param char nomsave[10] : le ,nom de la sauvegarde, t_liste * ordre_action : la liste triés des personnages par ordre de jeu
 */
	int i;
	FILE * nomfic = NULL;
	t_save save;
	nomfic = fopen( nomsave,"r" );
	if( nomfic != NULL ) {
		fread(&save, sizeof(save) , 1 , nomfic );
		
		for(i = 0; i < save.nbpersos; i++){
			en_queue(ordre_action);
			ajout_droit(ordre_action, save.tab_action[i]);
		}
		*Nb_tours = save.nbtours;
		en_tete(ordre_action);
		
		fclose(nomfic);
		return 1;
	} else return 0;
}

int sauver_partie( char  nomsave[10], t_liste * ordre_action, int Nb_tours) {
/**
 * \fn  sauver_partie( char  nomsave[10])
 * \brief Sauvegarde les données d'une parite dans un fichier dont le nom passée en paramètre
 * \param char nomsave[10] : le ,nom de la sauvegarde, t_liste * ordre_action : la liste triés des personnages par ordre de jeu
 */
	FILE * nomfic = NULL;
	int nbpersos, i, j;
	t_personnage persoc;
	t_save save;
	nomfic = fopen( nomsave,"w" );
	if( nomfic != NULL ) {

		compter_elts(ordre_action, &nbpersos);

		t_personnage tab_action[nbpersos];

		en_tete(ordre_action);
		for(i = 0; i < nbpersos; i++) {
			valeur_elt(ordre_action, &persoc);
			save.tab_action[i] = persoc;
			suivant(ordre_action);
		}
		save.nbpersos = nbpersos;
		save.nbtours = Nb_tours;
		fwrite(&save , sizeof(save) , 1 , nomfic);

		fclose(nomfic);
		return 1;
	} else return 0;
}

int choix_save(t_liste * ordre_action, int * Nb_tours) {
/**
 * \fn  choix_save(t_liste * ordre_action, int Nb_tours)
 * \brief demande au joueur si il souhaite vraiment charger une asuvegarde puis la lui fait choisir
 * \param t_liste * ordre_action : la liste triés des personnages par ordre de jeu, int Nb_tours, le nombre de tours actuel de la sauvegarde
 */

	int choix, i, res, erreur= faux;

	do {
		clearScreen();
		/* Affichage du menu et saisie d'une classe */
		printf("Choisissez une sauvegarde : \n\n");
		if(erreur) printf("Erreur: votre choix doit être compris entre 1 et 6\n");
		erreur = faux;

		printf(" 1- Save1.\n");
		printf(" 2- Save2.\n");
		printf(" 3- Save3.\n");
		printf(" 4- Save4.\n");
		printf(" 5- Save5.\n");
		printf("\n 6- /!\\Annuler /!\\.\n");
		printf("\nVotre choix : ");
		scanf("%d", &choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1: res = charger_partie( "Save1.bin", ordre_action, Nb_tours); choix = 6; break;
			case 2: res = charger_partie( "Save2.bin", ordre_action, Nb_tours); choix = 6; break;
			case 3: res = charger_partie( "Save3.bin", ordre_action, Nb_tours); choix = 6; break;
			case 4: res = charger_partie( "Save4.bin", ordre_action, Nb_tours); choix = 6; break;
			case 5: res = charger_partie( "Save5.bin", ordre_action, Nb_tours); choix = 6; break;
			case 6: break;
			default: erreur = vrai;
		}
	} while (choix != 6);
	return res;
}

void quitter_partie(t_liste * ordre_action, int Nb_tours) {
/**
 * \fn  quitter_partie(t_liste * ordre_action, int Nb_tours)
 * \brief demande au joueur si il souhaite vraiment quittez et si il souhaite sauvegarder la partie en cour
 * \param t_liste * ordre_action : la liste triés des personnages par ordre de jeu, int Nb_tours, le nombre de tours actuel de la sauvegarde
 */

	int choix, i, erreur= faux;

	do {
		clearScreen();
		/* Affichage du menu et saisie d'une classe */
		printf("Choisissez une sauvegarde : \n\n");
		if(erreur) printf("Erreur: votre choix doit être compris entre 1 et 6\n");
		erreur = faux;

		printf(" 1- Save1.\n");
		printf(" 2- Save2.\n");
		printf(" 3- Save3.\n");
		printf(" 4- Save4.\n");
		printf(" 5- Save5.\n");
		printf("\n 6- /!\\Annuler /!\\.\n");
		printf("\nVotre choix : ");
		scanf("%d", &choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1:  sauver_partie( "Save1.bin", ordre_action, Nb_tours); exit(0); break;
			case 2:  sauver_partie( "Save2.bin", ordre_action, Nb_tours); exit(0); break;
			case 3:  sauver_partie( "Save3.bin", ordre_action, Nb_tours); exit(0); break;
			case 4:  sauver_partie( "Save4.bin", ordre_action, Nb_tours); exit(0); break;
			case 5:  sauver_partie( "Save5.bin", ordre_action, Nb_tours); exit(0); break;
			case 6: break;
			default: erreur = vrai;
		}
	} while (choix != 2);
}