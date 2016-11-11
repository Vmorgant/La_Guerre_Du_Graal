/**
*\file main.c
*\brief Menu principal et lancement de la partie
*\version 1.0
*\auteur Victor Morgant
*\date 11/11/2016
*/
#include<stdio.h>
#include<stdlib.h>
#include"listes_ptr.h"
#include"actions.h"
#include"classes.h"

int InitEquipe(void)
{	int choix;
	int PE_MAX = 9;
	t_liste *equipe1;
	t_liste *equipe2;
	t_liste *ordre_action;

/* Initialisation des listes de personnages */
	init_liste(equipe1);
	init_liste(equipe2);
	init_liste(ordre_action);

	do
/* Affichage du menu et saisie du choix */
	{	printf("\nMenu :\n");
		printf(" 1 - Ajouter un personnage dans l'equipe 1\n");
		printf(" 2 - Ajouter un personnage dans l'equipe 2 \n");
		printf(" 3 - Supprimer un personnage dans l'equipe 1\n");
		printf(" 4 - Supprimer un personnage dans l'equipe 2\n");
		printf(" 5 - Effacer l'equipe 1\n");
		printf(" 6 - Effacer l'equipe 2\n");
		printf(" 7 - Valider les deux équipes\n");
		printf(" 8 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: inserer(equipe1);  afficher(equipe1); break;
			case 2: inserer(equipe2);  afficher(equipe2); break;
			case 3: supprimer(equipe1); afficher(equipe1); break;
			case 4: supprimer(equipe2); afficher(equipe2); break;
			case 5: vider_liste(equipe1); afficher(equipe1); break;
			case 6: vider_liste(equipe2); afficher(equipe2); break;
			case 7: InitPartie();
			case 8: break;
			default: printf("Erreur: votre choix doit �tre compris entre 1 et 8\n");
		}
	}
	while(choix!=8);

	printf("Au revoir !\n");
	return EXIT_SUCCESS;
}



int main(void)
{	int choix;
	do
/* Affichage du menu et saisie du choix */
	{	printf("\nMenu :\n");
		printf(" 1 - Mode Duel\n");
		printf(" 2 - Mode Arcade\n");
		printf(" 3 - Mode Histoire\n");
		printf(" 4 - Credits\n");
		printf(" 5 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: InitEquipe(); break;
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
