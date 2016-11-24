/**
*\file gest_partie.c
*\brief Ce fichier contient les fonctions permettant le lancement et le déroulement de la partie
*\author Victor Morgant Martin Lebourdais Corentin Petit
*\version 1.0
*\date 14/11/2016
*/
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <math.h>
#include "global.h"
#include "listes_ptr.h"
#include "deplacement.h"
#include "Init_map.h"


int Rand_Int(int a, int b){
/**
 * \fn Rand_Int(int a, int b)
 * \brief Fonction renvoyant un nombre compris entre a et b
 * \param int a, int b : bornes de l'intervalles
 */
	int nombre_aleatoire = 0;
	srand(time(NULL));
    nombre_aleatoire = rand()%(b-a)+a;
	return nombre_aleatoire;
}

void init_partie(t_liste *equipe1,t_liste *equipe2, t_liste * ordre_action){
/**
 * \fn init_partie(t_liste *equipe1,t_liste *equipe2)
 * \brief création de  la liste ordre action avec les personnages triés par initiative
 * \param t_liste *equipe1 : la liste des joueurs de l'équipe 1, t_liste *equipe2 : la liste des joueurs de l'équipe 2
 */
	t_personnage tampon;
	int nb_persos, bien_place = faux;

	*ordre_action = *equipe1;

	en_tete(ordre_action);
	en_tete(equipe2);

	while(!hors_liste(equipe2)){
	/**On ajoute les deux équipes dans ordre action en prenant un joueur sur */
		valeur_elt(equipe2, &tampon);
		ajout_droit(ordre_action,tampon);
		suivant(equipe2);

		suivant(ordre_action);
		suivant(ordre_action);

	}

	/** Tri indirect de la liste pour connaitre l'ordre de jeu */
	
	compter_elts(ordre_action, &nb_persos);
	int i, j;

	for(i=0; i < nb_persos; i++){
		bien_place = faux;

		/** on se place au i ième element de la liste */
		en_tete(ordre_action);
		for (j = 0; j < i; j++) {
			suivant(ordre_action);
		}
		
		j = i;

		/** puis on trie la liste par insertion en fonction de l'initiative des persos*/
		while(j > 0 && !bien_place) {

			bien_place = (  (ordre_action ->ec -> personnage.classe.INI) <= (ordre_action ->ec->pred -> personnage.classe.INI) );

			if( !bien_place) {
				tampon = ordre_action ->ec -> personnage;
				ordre_action ->ec -> personnage = ordre_action ->ec->pred -> personnage;
				ordre_action ->ec->pred -> personnage = tampon;
				j--;
				precedent(ordre_action);
			}
		}
	}	

	afficher(ordre_action);
}

void placer(t_liste *ordre_action,t_map carte){
/**
 * \fn  placer(t_liste *equipe1,t_liste *equipe2,t_map carte)
 * \brief Place les personnages des deux équipes sur la carte.
 * \param t_liste *equipe1 : la liste des joueurs de l'équipe 1, t_liste *equipe2 : la liste des joueurs de l'équipe 2,t_map carte : la carte 
 */
	int x, y;
	
	printf("\n");
	
	en_tete(ordre_action);
	while (!hors_liste(ordre_action)){
		if((ordre_action->ec->personnage.joueur)==1){														//Placer un personnage pour l'equipe 1
			printf("Joueur 1, entrez un x pour votre personnage entre 0 et 9 :\n");
			scanf("%i", &y);
			printf("\n");
			printf("Entrez un y pour votre personnage entre 0 et 4 :\n");
			scanf("%i", &x);
			printf("\n");
		
			while (x > 10 || y > 5 || x < 0 || y < 0 || carte.cell[x][y] != 0){

				if (carte.cell[x][y] != 0){															//On teste si la case est vide
					printf("La case est déjà occupée\n");
					printf("Joueur 1, entrez un x pour votre personnage entre 0 et 9 :\n");
					scanf("%i", &y);
					printf("\n");
					printf("Entrez un y pour votre personnage entre 0 et 4 :\n");
					scanf("%i", &x);
					printf("\n");
					
				}
				else {																			//On teste si on est pas hors map
					printf("Les coordonnées doivent-être des entiers avec un y compris entre 0 et 4\n");
					printf("Joueur 1, entrez un x pour votre personnage entre 0 et 9 :\n");
					scanf("%i", &y);
					printf("\n");
					printf("Entrez un y pour votre personnage entre 0 et 4 :\n");
					scanf("%i", &x);
					printf("\n");
					printf("\n");
				}
			}
			printf("%i\n",carte.cell[x][y]);
			ordre_action->ec->personnage.x = x;
			ordre_action->ec->personnage.y = y;
			carte=actumap(ordre_action, carte);
			printf("Perso n°1 [%i,%i]=%i \n",x,y,carte.cell[x][y]) ;
			afficherMat(carte);
			suivant(ordre_action);
		}
		if((ordre_action->ec->personnage.joueur)==2){													//Placer un personnage pour l'equipe 2;
			printf("Joueur 2, entrez un x pour votre personnage entre 0 et 9 :\n");
			scanf("%i", &y);
			printf("\n");
			printf("Entrez un y pour votre personnage entre 5 et 9 :\n");
			scanf("%i", &x);
			printf("\n");
		
			while (x > 10 || y > 10 || x < 0 || y < 5 || carte.cell[x][y] != 0){

				if (carte.cell[x][y] != 0){
					printf("La case est déjà occupée\n");
					printf("Joueur 2, entrez un x pour votre personnage entre 0 et 9 :\n");
					scanf("%i", &y);
					printf("\n");
					printf("Entrez un y pour votre personnage entre 5 et 9 :\n");
					scanf("%i", &x);
					printf("\n");					
					
				}
				else{
					printf("Les coordonnées doivent-être des entiers avec un y compris entre 5 et 9\n");
					printf("Joueur 1, entrez un x pour votre personnage entre 0 et 9 :\n");
					scanf("%i", &y);
					printf("\n");
					printf("Entrez un y pour votre personnage entre 5 et 9 :\n");
					scanf("%i", &x);
					printf("\n");
				}
			}
		
			ordre_action->ec->personnage.x = x;
			ordre_action->ec->personnage.y = y;
			carte=actumap(ordre_action, carte);
			afficherMat(carte);
			suivant(ordre_action);
		}
	}

}

int est_mort(t_liste *ordre_action,t_personnage cadavre,int *gagnant){
/**
 * \fn  est_mort(t_liste *ordre_action,t_personnage cadavre).
 * \brief Retire le personnage mort de la liste ordre_action
 * \param t_liste *ordre_action : la liste des personnages joués triée t_personnage cadavre : le personnage mort
 */
	int nb_equipe1;
	int nb_equipe2;
	en_tete(ordre_action);
	while(ordre_action->ec->personnage.pv >0 ) {
		suivant(ordre_action);
		if((ordre_action->ec->personnage.joueur)==1){
			nb_equipe1++;	
		}
		else{
			nb_equipe2++;	
		}
	}
		oter_elt(ordre_action);
	
	if( (nb_equipe1 >0) && (nb_equipe2 >0) ){
		return 0;
	}
	else if ( (nb_equipe1 >0) ) {
		return 1;
	}
	else {
		return 2;
	}
}

void passer(t_liste *ordre_action){//passe la main au personnage suivant dans la liste ordre action 
	suivant(ordre_action);
}


void attaquer(t_liste *ordre_action,t_personnage cible, t_attaque attaque,int *gagnant){
	/**exécute l’attaque de l’attaquant vers la cible et actualise les stats et l’état si un personnage meurt appelle la fonction mort*/	
	int degats_max = (attaque.mul_ATQ) * (ordre_action->ec->pred->personnage.classe.ATQ);
	int def=cible.classe.DEF;
	int degats=Rand_Int(0, degats_max)-def;
	if (degats>0){
		cible.pv=(cible.pv)-degats;	
	}
	if ( cible.pv<=0 ){
		*gagnant=est_mort(ordre_action,cible,gagnant);
	}
	
}

void choix_cible(t_liste *ordre_action, t_map carte, t_attaque attaque,int *gagnant){
	/**choix de la cible de l'attaque */ 

	int portee = attaque.portee;
	int i=1;
        int choix;
        t_personnage cible [5];
	cible[0]=ordre_action->ec->personnage;
	suivant(ordre_action);

	while( (ordre_action->ec->personnage.x != cible[0].x) && ((ordre_action->ec->personnage.y) != cible[0].y) ){
		if ( ordre_action->ec->personnage.joueur != cible[i].joueur ){
			if( ( ordre_action->ec->personnage.x >= cible[i].x-portee ) && ( ordre_action->ec->personnage.x <= cible[i].x+portee ) ){
				if( ( ordre_action->ec->personnage.y >= cible[i].y-portee ) && ( ordre_action->ec->personnage.x <= cible[i].y+portee ) ){
					cible[i]=ordre_action->ec->personnage;
					printf("%i - %s PV :%i DEF : %i \n",i,cible[i].classe.nom,cible[i].pv,cible[i].classe.DEF);
					i++;
					
				}
			}
		}
			
			suivant(ordre_action);
	
	}

	printf("Votre choix : ");
	scanf("%d",&choix);

	switch(choix){	case 1: attaquer(ordre_action,cible[1],attaque,gagnant); break;
			case 2: attaquer(ordre_action,cible[2],attaque,gagnant); break;
			case 3: attaquer(ordre_action,cible[3],attaque,gagnant); break;
			case 4: attaquer(ordre_action,cible[4],attaque,gagnant); break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 4\n");
		}
	
}
void choix_competence(t_liste *ordre_action,t_map carte,int *gagnant){

	int choix;
	printf("\nMenu :\n");
	printf(" 1 - %s\n",ordre_action->ec->personnage.classe.atq1.nom);
	printf(" 2 - %s\n",ordre_action->ec->personnage.classe.atq2.nom);
	//printf(" 3 - %s\n",ordre_action->ec->personnage->classe->spe->nom);
	printf("Votre choix : ");
	scanf("%d",&choix);

	switch(choix){	case 1: choix_cible(ordre_action,carte,ordre_action->ec->personnage.classe.atq1,gagnant ); break;
			case 2: choix_cible(ordre_action,carte,ordre_action->ec->personnage.classe.atq2,gagnant); break;
			//case 3: choix_cible(ordre_action,carte,ordre_action->ec->personnage.classe.ulti); break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 2\n");
		}
	
}

void choix_action(t_liste *ordre_action, t_map carte,int *gagnant){
	int choix;
	do{	printf("\nMenu :\n");
		printf(" 1 - Deplacer\n");
		printf(" 2 - Attaquer\n");
		printf(" 3 - Passer\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

		switch(choix){	case 1: deplacement(ordre_action,carte); break;
			case 2: choix_competence(ordre_action,carte,gagnant); break;
			case 3: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}while(choix != 3);
	passer(ordre_action);
}

void gestion_tour(t_liste *ordre_action,int *NbTour,t_map carte,int *gagnant){
/**Joue le tour suivant*/
	NbTour++;
	en_tete(ordre_action);
	while(!hors_liste(ordre_action)){
		ordre_action->ec->personnage.pa += (ordre_action->ec->personnage.classe.gainPA);
		choix_action(ordre_action,carte,gagnant);
	}
}

