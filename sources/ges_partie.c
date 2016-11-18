#include<stdio.h>


/**
*\file gest_partie.c
*\brief Ce fichier contient les fonctions permettant le lancement et le déroulement de la partie
*\author Victor Morgant
*\version 1.0
*\date 14/11/2016
*/
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <math.h>
#include "global.h"
#include "listes_ptr.h"

/** Fonction renvoyant un nombre compris entre a et b*/
int Rand_Int(int a, int b){
	int nombre_aleatoire = 0;
	srand(time(NULL));
    nombre_aleatoire = rand()%(b-a)+a;
	return nombre_aleatoire;
}

void init_partie(t_liste *equipe1,t_liste *equipe2){
/**création de  la liste ordre action avec les personnages triés par initiative*/
	t_personnage *tampon;
	t_liste *ordre_action;
	init_liste(ordre_action);
	en_tete(equipe1);
	en_tete(equipe2);
	int bienplace=0;
	while(!hors_liste(equipe1) && (!hors_liste(equipe2))){
	/**On ajoute les deux équipes dans ordre action en prenant un joueur sur */
		valeur_elt(equipe1,tampon);
		ajout_droit(ordre_action,*tampon);
		valeur_elt(equipe2,tampon);
		ajout_droit(ordre_action,*tampon);
	}
		en_queue(ordre_action);
		while(!hors_liste(ordre_action)){
			valeur_elt(ordre_action,tampon);
			bienplace=( (tampon->classe.INI) >= (ordre_action->ec->pred->personnage.classe.INI) );
			if(!bienplace && ordre_action->ec->pred != ordre_action->drapeau){
				oter_elt(ordre_action);
				ajout_gauche(ordre_action,*tampon);
			}
			else
				suivant(ordre_action);	
		}
		
}

void placer(t_liste personnages equipe1,t_liste personnages equipe2,t_map carte){
/**Place les personnages des deux équipes sur la carte.*/

}

int mort(t_liste *ordre_action,t_personnage cadavre){
/**Retire le cadavre de la liste ordre_action puis renvoie 0 s'il reste des joueurs dans les deux équipes et le numéro de l'équipe gagnante sinon.*/
	int nb_equipe1;
	int nb_equipe2;
	en_tete(ordre_action);
	while( (ordre_action->ec->personnage.PV) >0) && (!hors_liste(ordre_action) ){
		suivant(ordre_action);
		if((ordre_action->ec->personnage.joueur)==1){
			nb_equipe1++;	
		}
		else{
			nb_equipe2++;	
		}
	}
	if(!hors_liste(ordre_action)){
		oter_element(ordre_action);	
	}
	if( (nb_equipe1 >0) && (nb_equipe2 >0) ){
		return 0;
	}
	else if ( (nb_equipe1 >0) {
		return 1;
	}
	else ( (nb_equipe2 >0) {
		return 2;
	}
}

void passer(t_liste ordre_action){//passe la main au personnage suivant dans la liste ordre action 
	suivant(ordre_action);
}


void attaque(t_liste ordre_action,t_personnage cible, t_attaque attaque){
	/**exécute l’attaque de l’attaquant vers la cible et actualise les stats et l’état si un personnage meurt appelle la fonction mort*/	
	int degats_max = (attaque.mul_ATQ) * (ordre_action->ec->pred->personnage.classe.ATQ);
	int def=cible.classe.DEF;
	int degats=Rand_Int(0, degats_max)-def;
	if (degats>0){
		cible.PV=(cible.PV)-degats;	
	}
	if ((cible.PV)==0)){
		mort(ordre_action,cible);
	}
}

void deplacement(t_liste ordre_action, t_map carte){
	/** demande les nouvelles coordonnés, vérifie si le déplacement est valide, indique le cout en PA et demande confirmation puis exécute le déplacement
*/	
}

void choix_competence(t_liste ordre_action){
	int choix;
	do{	printf("\nMenu :\n");
		printf(" 1 - %s\n",ordre_action->ec->personnage->classe->atq1->nom);
		printf(" 2 - %s\n",ordre_action->ec->personnage->classe->atq1->nom);
		//printf(" 3 - %s\n",ordre_action->ec->personnage->classe->spe->nom);
		printf("Votre choix : ");
		scanf("%d",&choix);

		switch(choix){	case 1: choix_cible(ordre_action); break;
			case 2: choix_cible(ordre_action); break;
			//case 3: passer(ordre_action); break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 2\n");
		}
	}while(ordre_action->ec->personnage.PA >0);
}
void choix_action(t_liste ordre_action){
	int choix;
	do{	printf("\nMenu :\n");
		printf(" 1 - Deplacer\n");
		printf(" 2 - Attaquer\n");
		printf(" 3 - Passer\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

		switch(choix){	case 1: deplacement(ordre_action,carte; break;
			case 2: choix_competence(ordre_action); break;
			case 3: passer(ordre_action); break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}while(ordre_action->ec->personnage.PA >0);
}

void gestion_tour(t_liste ordre_action,*NbTour){
/**Joue le tour suivant*/
	&NbTour++;
	en_tete(ordre_action);
	while(!hors_liste(ordre_action)){
		ordre_action->ec->personnage.PA = (ordre_action->ec->personnage.PA)+ (ordre_action->ec->personnage->classe.gainPA);
		choix_action(t_liste ordre_action);
	}
}

