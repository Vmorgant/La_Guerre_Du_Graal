/**
*\file ges_partie.c
*\brief Ce fichier contient les fonctions permettant le lancement et le déroulement de la partie
*\author Victor Morgant Martin Lebourdais Corentin Petit
*\version 1.0
*\date 14/11/2016
*/
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include "global.h"
#include "listes_ptr.h"
#include "deplacement_simp.h"
#include "Init_map.h"
#include "save.h"


float Rand_atq(){
/**
 * \fn Rand_Int(int degat)
 * \brief Fonction renvoyant un nombre aléatoire de degats
 * \param int degat : degat moyen de l'attaque
 * \return valeur aleatoire de degat
 */
	float nombre_aleatoire;
	srand(time(NULL));
	nombre_aleatoire = rand()%50;
	nombre_aleatoire =((75 + nombre_aleatoire )/100);
	return nombre_aleatoire;
}

void init_partie(t_liste *equipe1,t_liste *equipe2, t_liste * ordre_action){
/**
 * \fn init_partie(t_liste *equipe1,t_liste *equipe2, t_liste * ordre_action)
 * \brief concaténation des listes des deux équipes et tri par initiative
 * \param t_liste *equipe1 : la liste des joueurs de l'équipe 1, t_liste *equipe2 : la liste des joueurs de l'équipe 2 t_liste * ordre_action : la liste triée par ordre de jeu.
 */
	t_personnage tampon;
	int nb_persos, bien_place = faux;

	*ordre_action = *equipe1;

	en_tete(ordre_action);
	en_tete(equipe2);

	while(!hors_liste(equipe2)){
	/**On ajoute les deux équipes dans ordre action en alternant les equipes */
		valeur_elt(equipe2, &tampon);
		ajout_droit(ordre_action,tampon);
		suivant(equipe2);

		suivant(ordre_action);
		suivant(ordre_action);
		if(ordre_action->ec == ordre_action->drapeau)
			en_queue(ordre_action);

	}

	/** Tri indirect de la liste pour connaitre l'ordre de jeu */
	
	compter_elts(ordre_action, &nb_persos);
	int i, j;

	for(i=0; i < nb_persos; i++){
		bien_place = faux;

		/** On se place à l'élément i de la liste */
		en_tete(ordre_action);
		for (j = 0; j < i; j++) {
			suivant(ordre_action);
		}
		
		j = i;

		/** Puis on trie la liste par insertion en fonction de l'initiative des personnages*/
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
	printf("\n");
}

void placer(t_liste *ordre_action,t_map * carte){
/**
 * \fn  placer(t_liste *ordre_action,t_map carte)
 * \brief Place les personnages des deux équipes sur la carte.
 * \param t_liste * ordre_action : la liste triés par ordre de jeu, t_map carte : la carte 
 */
	int x, y;
	t_personnage persoc;//Permet de stocker les informations du personnage
	printf("\n");
	
	en_tete(ordre_action);
	while (!hors_liste(ordre_action)){
		valeur_elt(ordre_action, &persoc); 
		if((persoc.joueur)==1){														
		//Placer un personnage pour l'equipe 1
			printf("Joueur 1, entrez un x pour votre %s entre 0 et 9 :\n",persoc.classe.nom);
			scanf("%i", &x);
			printf("\n");
			printf("Entrez un y pour votre %s entre 0 et 2 :\n", persoc.classe.nom);
			scanf("%i", &y);
			printf("\n");
		
			while (x > 9 || y > 2 || x < 0 || y < 0 || carte->cell[x][y] != 0){

				if (carte->cell[x][y] != 0){
				//On teste si la case est vide
					printf("La case est déjà occupée\n");
					printf("Joueur 1, entrez un x pour votre %s entre 0 et 9 :\n", persoc.classe.nom);
					scanf("%i", &x);
					printf("\n");
					printf("Entrez un y pour votre %s entre 0 et 2 :\n", persoc.classe.nom);
					scanf("%i", &y);
					printf("\n");
					
				}
				else{
				//On teste si on est pas hors map
					printf("Les coordonnées doivent-être des entiers avec un y compris entre 0 et 4\n");
					printf("Joueur 1, entrez un x pour votre %s entre 0 et 9 :\n", persoc.classe.nom);
					scanf("%i", &x);
					printf("\n");
					printf("Entrez un y pour votre personnage entre 0 et 2 :\n");
					scanf("%i", &y);
					printf("\n");
					printf("\n");
				}
			}
			
			
		} else if((persoc.joueur)==2){													
		//Placer un personnage pour l'equipe 2;
			printf("Joueur 2, entrez un x pour votre %s entre 0 et 9 :\n", persoc.classe.nom);
			scanf("%i", &x);
			printf("\n");
			printf("Entrez un y pour votre %s entre 7 et 9 :\n", persoc.classe.nom);
			scanf("%i", &y);
			printf("\n");
		
			while (x > 10 || y > 10 || x < 0 || y < 7 || carte->cell[x][y] != 0){

				if (carte->cell[x][y] != 0){
					printf("La case est déjà occupée\n");
					printf("Joueur 2, entrez un x pour votre %s entre 0 et 9 :\n", persoc.classe.nom);
					scanf("%i", &x);
					printf("\n");
					printf("Entrez un y pour votre %s entre 7 et 9 :\n", persoc.classe.nom);
					scanf("%i", &y);
					printf("\n");					
					
				}
				else{
					printf("Les coordonnées doivent-être des entiers avec un y compris entre 7 et 9\n");
					printf("Joueur 1, entrez un x pour votre %s entre 0 et 9 :\n", persoc.classe.nom);
					scanf("%i", &x);
					printf("\n");
					printf("Entrez un y pour votre %s entre 7 et 9 :\n", persoc.classe.nom);
					scanf("%i", &y);
					printf("\n");
				}
			}
		
		}

		persoc.x = x;
		persoc.y = y;
		modif_elt(ordre_action, persoc);
		assert(persoc.x == x); //on vérifie que les coordonnées du personnages sont bien celle entrée par le joueur
		assert(persoc.y == y);

		* carte = actumap(ordre_action, * carte);
		clearScreen();
		afficherMat( * carte);
		suivant(ordre_action);
	}
}

int est_mort(t_liste *ordre_action, t_map * carte){
/**
 * \fn  est_mort(t_liste *ordre_action,t_map * carte).
 * \brief Retire le personnage mort de la liste ordre_action, et de la carte.
 * \param t_liste *ordre_action : la liste des personnages triés par ordre de jeu t_map * carte : la carte.
 * \return le numéro de l'équipe qui a gagnée.
 */
	int i=0;
        int nb_equipe1=0;//permet de stocker le nombre de personnage de l'équipe 1
        int nb_equipe2=0;
	t_element *tampon = ordre_action->ec;
	t_personnage persoc;

	en_tete(ordre_action);
	valeur_elt(ordre_action, &persoc); 
	while(persoc.pv >0 ) {
		suivant(ordre_action);
		valeur_elt(ordre_action, &persoc); 
        }	
	
        oter_elt(ordre_action);
	
 	clearScreen();

	*carte = actumap(ordre_action, *carte);

        en_tete(ordre_action);
        while (!hors_liste(ordre_action)){
		valeur_elt(ordre_action, &persoc); 
                if((persoc.joueur)==1){
			nb_equipe1++;	
		}
		else{
			nb_equipe2++;	
		}
		suivant(ordre_action);
	}
	ordre_action->ec = tampon;
	if ( (nb_equipe2 == 0) ) { 
		return 1;
	}
	if ( (nb_equipe1 == 0) ){ 
		return 2;
	}
	return 0;
}

void passer(t_liste *ordre_action,int *NbTour,t_map * carte){
/**
 * \fn  passer(t_liste *ordre_action,int *NbTour,t_map * carte)
 * \brief Passe la main au joueur suivant
 * \param t_liste *ordre_action : la liste des personnages joués triée int *NbTour le nombre ,t_map * carte
 */
	suivant(ordre_action);
	if(hors_liste(ordre_action)) {// Si l'ensemble des personnages ont joués ont se replace sur le premier de la liste
        	en_tete(ordre_action);
       		(*NbTour)++;
    	}
}


void attaquer(t_liste *ordre_action,t_personnage cible, t_attaque attaque,int *gagnant,t_map * carte, char mretour[100]){
/**
 * \fn  attaquer(t_liste *ordre_action,t_personnage cible, t_attaque attaque,int *gagnant,t_map * carte)
 * \brief exécute l’attaque de l’attaquant vers la cible et actualise les stats et l’état si un personnage meurt appelle la fonction mort
 * \param t_liste *ordre_action : la liste des personnages triés int *NbTour le nombre de tour de jeu ,t_map * carte
 */
	t_personnage persoc;
	t_element * tampon;
	int degats = (attaque.mul_ATQ) * (ordre_action->ec->personnage.classe.ATQ);
	int def=cible.classe.DEF;
	float stock, blocage, pare = faux;
	char message_tampon[100] = "";

	strcpy(mretour,"");

	stock = Rand_atq();

	/*Calcul des pourcentages de blocage, si l'attaquant réussi son attaque le défenseur a moins de chance de la bloquer */
	if(stock <= 0.78)
		blocage = 0.35;
	else if(stock > 0.78 && stock < 1.15){
		blocage = 0.08 * ((100 + def*10)/ 100);
	}else if(stock >= 1.15)
		blocage = 0;
	
	pare = (blocage*100) + (rand()%100);

	if(pare >= 100) {
		sprintf(message_tampon, "\tL'Attaque a ete bloquee !\n");
	} else {
		tampon = ordre_action->ec;
		en_tete(ordre_action);
		valeur_elt(ordre_action, &persoc);
		while( persoc.x != cible.x || persoc.y != cible.y){
			suivant(ordre_action);
			valeur_elt(ordre_action, &persoc);
		}
		degats = (stock*degats) -def;
		persoc.pv = (persoc.pv) - degats;

		if ( persoc.pv<=0 ){
			sprintf(message_tampon, "\tLe personnage %s a été vaincu !\n", persoc.classe.nom);
			*gagnant = est_mort(ordre_action, carte);// on enlève les morts de la liste ordre_action et on vérifie si une équipe a été éliminée
		} else {
			sprintf(message_tampon, "\tLe personnage %s perd %i points de vie !\n", persoc.classe.nom, degats);
		}


		ordre_action->ec= tampon;  
	}
	strcat(mretour,message_tampon);
}

int test_obstacle(t_personnage attaquant,t_personnage cible,int portee, t_map * carte){
/**
 * \fn  test_obstacle(t_personnage attaquant,t_personnage cible,int portee, t_map * carte)
 * \brief vérifie s'il y a un obstacle entre l'attaquant et la cible
 * \param t_liste *ordre_action : la liste des personnages triés int *NbTour le nombre de tour de jeu ,t_map * carte
 * \return vrai s'il y a un obstacle
 */
	int j;
	if(portee >1){
		if(attaquant.x == cible.x){
			if(cible.y > attaquant.y){
				for(j=1+attaquant.y; j < cible.y; j++){
					if(carte->cell[attaquant.x][j]!=0)//on vérifie si la case est bien vide 
						return vrai;		
				}
				return faux;
			}else if(cible.y < attaquant.y){
				for(j=cible.y+1; j < attaquant.y; j++){
					if(carte->cell[attaquant.x][j]!=0)
						return vrai;		
				}
				return faux;
			}
		} else if (attaquant.y == cible.y){
			if(cible.x > attaquant.x){
				for(j=1+attaquant.x; j < cible.x; j++){
					if(carte->cell[j][attaquant.y]!=0)
						return vrai;		
				}
				return faux;
			}else if(cible.x < attaquant.x){
				for(j=cible.x+1; j < attaquant.x; j++){
					if(carte->cell[j][attaquant.y]!=0)
						return vrai;		
				}
				return faux;
			}
		}		
	}else if (portee ==1) return faux;
}

void choix_cible1(t_liste *ordre_action, t_attaque attaque,int *gagnant, t_map * carte, char mretour[100]){
/**
 * \fn choix_cible(t_liste *ordre_action, t_attaque attaque,int *gagnant, t_map * carte)
 * \brief donne la liste des cibles qui sont a portée de l'attaquant
 * \param t_liste *ordre_action : la liste des personnages triés int *NbTour le nombre de tour de jeu ,t_map * carte
 */ 
	
	int portee = attaque.portee;
	int i=0;
	int j;
  	int choix, erreur = faux;
	strcpy(mretour,"\n");
   	t_personnage  cible[4];
    	t_personnage persoc;
	t_element * tampon = ordre_action->ec;
	en_tete(ordre_action);
	while(!hors_liste(ordre_action)){
		valeur_elt(ordre_action, &persoc);
		if ( persoc.x != tampon->personnage.x ||  persoc.y != tampon->personnage.y ){//On vérifie que la cible n'est pas le joueur.
			if (tampon->personnage.joueur != persoc.joueur ){//On vérifie que la cible n'est pas dans l'équipe du joueur.
				if( ( (tampon->personnage.x+portee >= persoc.x && tampon->personnage.x-portee <= persoc.x ) &&  tampon->personnage.y == persoc.y) ||( (tampon->personnage.y+portee >= persoc.y && tampon->personnage.y-portee <= persoc.y) && tampon->personnage.x == persoc.x) ){//On recherche les cibles à porté

					if(!test_obstacle(tampon->personnage,persoc,portee,carte)){//On vérifie qu'il n'y a pas d'obstacle entre le personnage et la cible.
						cible[i]= persoc;
						i++;
					}
				}
			}
		}
		
		suivant(ordre_action);
	}
	
	ordre_action->ec = tampon;
	
	do{
		clearScreen();
		afficherMat(*carte);
		valeur_elt(ordre_action, &persoc);
		if(persoc.joueur == 1)
			couleur("34;1");
		else couleur("31;1");
		printf("%s Equipe :%i %i/%i PV (%iPA) coordonnee %i %i\n",persoc.classe.nom,persoc.joueur, persoc.pv, persoc.classe.PVmax,persoc.pa, persoc.x,persoc.y);
		
		couleur("0");

		printf("\nChoix de la cible :\n");

		if(erreur) {
				couleur("31");
				printf("\t%s",mretour);
				couleur("0");
			} else {
				couleur("32");
				printf("\t%s",mretour);
				couleur("0");
			}
			erreur = faux;
			strcpy(mretour,"\n");


		for( j = 0; j < i; j++)
			printf("%i - %s PV : %i  x : %i y : %i\n",i,cible[j].classe.nom,cible[j].pv,cible[j].x,cible[j].y);

		printf("\n%i - Retour \n",i+1);
	
		printf("\nVotre choix : ");
		scanf("%d",&choix);
	
		if (choix >= 1 && choix <i+1){
			attaquer(ordre_action,cible[choix-1],attaque,gagnant, carte, mretour);
			persoc.pa -= attaque.coutPA;//Soustraction du coup en pa de l'attaque.
			choix = i+1;
		} else if (choix > i+1){
			strcpy(mretour, "Choix indisponible\n");
			erreur = vrai;
		}
	} while(choix != i+1);
}

void choix_cible2(t_liste *ordre_action, t_attaque attaque,int *gagnant, t_map * carte, char mretour[100]){
/**
 * \fn choix_cible(t_liste *ordre_action, t_attaque attaque,int *gagnant, t_map * carte)
 * \brief donne la liste des cibles qui sont a portée de l'attaquant
 * \param t_liste *ordre_action : la liste des personnages triés int *NbTour le nombre de tour de jeu ,t_map * carte
 */ 
	
	int portee = attaque.portee;
	int i, j, k = 0;
	int choix, erreur = faux;
	strcpy(mretour,"\n");
	t_personnage persoc;
	t_personnage  cible[4][portee], tabchoix[4][portee];
	int nbcibles[4] = {0, 0, 0, 0,}, nbchoix[4] = {0, 0, 0, 0,};
    
	t_element * tampon = ordre_action->ec;

	for (i = 1; i <= portee; i++){
		if( ((tampon->personnage.y + i) <= 9) && (carte->cell[tampon->personnage.x][tampon->personnage.y + i] > 0) ){
			en_tete(ordre_action);
			valeur_elt(ordre_action, &persoc);
			while( (persoc.x != tampon->personnage.x || persoc.y != tampon->personnage.y + i) && !hors_liste(ordre_action) ){
				suivant(ordre_action);
				valeur_elt(ordre_action, &persoc);
			}
			if(!hors_liste(ordre_action) && (persoc.joueur != tampon->personnage.joueur) ) {
				cible[0][nbcibles[0]]= ordre_action->ec->personnage;
				nbcibles[0]++;
			}
		}
		if( ((tampon->personnage.y - i) >= 0) && (carte->cell[tampon->personnage.x][tampon->personnage.y - i] > 0) ){
			en_tete(ordre_action);
			valeur_elt(ordre_action, &persoc);
			while( (persoc.x != tampon->personnage.x || persoc.y != tampon->personnage.y - i) && !hors_liste(ordre_action) ){
				suivant(ordre_action);
				valeur_elt(ordre_action, &persoc);
			}
			if(!hors_liste(ordre_action) && (persoc.joueur != tampon->personnage.joueur) ) {
				cible[1][nbcibles[1]]=persoc;
				nbcibles[1]++;
			}
		}
		if( ((tampon->personnage.x + i) <= 9) && (carte->cell[tampon->personnage.x + i][tampon->personnage.y] > 0) ){
			en_tete(ordre_action);
			valeur_elt(ordre_action, &persoc);
			while( (ordre_action->ec->personnage.x != tampon->personnage.x + i || ordre_action->ec->personnage.y != tampon->personnage.y) && !hors_liste(ordre_action) ){
				suivant(ordre_action);
				valeur_elt(ordre_action, &persoc);
			}
			if(!hors_liste(ordre_action) && (persoc.joueur != tampon->personnage.joueur) ) {
				cible[2][nbcibles[2]]= persoc;
				nbcibles[2]++;
			}
		}
		if( ((tampon->personnage.x - i) >= 0) && (carte->cell[tampon->personnage.x - i][tampon->personnage.y] > 0) ){
			en_tete(ordre_action);
			valeur_elt(ordre_action, &persoc);
			while( (persoc.x != tampon->personnage.x - i || persoc.y != tampon->personnage.y) && !hors_liste(ordre_action) ){
				suivant(ordre_action);
				valeur_elt(ordre_action, &persoc);
			}
			if(!hors_liste(ordre_action) && (persoc.joueur != tampon->personnage.joueur) ) {
				cible[3][nbcibles[3]]= persoc;
				nbcibles[3]++;
			}
		}
	}

	ordre_action->ec = tampon;

	do{
		clearScreen();
		afficherMat(*carte);
		valeur_elt(ordre_action, &persoc);
		if(ordre_action->ec->personnage.joueur == 1)
			couleur("34;1");
		else couleur("31;1");
		printf("%s Equipe :%i %i/%i PV (%iPA) coordonnee %i %i\n",persoc.classe.nom,persoc.joueur, persoc.pv, persoc.classe.PVmax,persoc.pa, persoc.x,persoc.y);
		
		couleur("0");

		printf("\nChoix de la cible :\n");

		if(erreur) {
				couleur("31");
				printf("\t%s",mretour);
				couleur("0");
			} else {
				couleur("32");
				printf("\t%s",mretour);
				couleur("0");
			}
			erreur = faux;
			strcpy(mretour,"\n");

		k = 0;
		for(i = 0; i < 4; i++) {	
			if(nbcibles[i] > 0) {
				k++;
				nbchoix[k-1] = nbcibles[i];
				printf("%i - ", k);
				for(j = 0; j < nbcibles[i]; j++){
					printf("%s, %i PV x : %i y : %i ||\t", cible[i][j].classe.nom, cible[i][j].pv,  cible[i][j].x, cible[i][j].y );
					tabchoix[k-1][j] = cible[i][j];
				}
				printf("\n");
			}
		}

		printf("\n%i - Retour \n",  k+1);

		printf("\nVotre choix : ");
		scanf("%d",&choix);

		if(choix > 0 && choix < k+1) {
			for( j = 0; j < nbchoix[choix-1]; j++ ){
				attaquer(ordre_action, tabchoix[choix-1][j], attaque, gagnant, carte, mretour);
			}
			persoc.pa -= attaque.coutPA;//Soustraction du coup en pa de l'attaque.
			choix = k+1;
		} else if (choix > k+1) {
			strcpy(mretour, "\tChoix indisponible\n");
			erreur = vrai;
		}
	} while(choix != k+1);

}

void choix_competence(t_liste *ordre_action,int *gagnant,t_map * carte) {
/**
 * \fn  choix_competence(t_liste *ordre_action,int *gagnant,t_map * carte)
 * \brief Permet de choisir son attaque
 * \param t_liste *ordre_action : la liste des personnages joués triée int *gagnant numero de l'équipe gagnante, t_map * carte
 */

	int choix, erreur = faux;
	char mretour[100] = "\n";
	t_personnage persoc;
	do{
		clearScreen();
		afficherMat(*carte);
		valeur_elt(ordre_action, &persoc);
		if(persoc.joueur == 1)
			couleur("34;1");
		else couleur("31;1");
		printf("%s Equipe :%i %i/%i PV (%iPA) coordonnee %i %i\n",persoc.classe.nom,persoc.joueur, persoc.pv, persoc.classe.PVmax,persoc.pa, persoc.x,persoc.y);
		
		couleur("0");

		printf("\nChoix de la compétence :\n");

		if(erreur) {
				couleur("31");
				printf("%s",mretour);
				couleur("0");
			} else {
				couleur("32");
				printf("%s",mretour);
				couleur("0");
			}
			erreur = faux;
			strcpy(mretour,"\n");

		printf(" 1 - %s (%iPA)\n",persoc.classe.atq1.nom,persoc.classe.atq1.coutPA);
		printf(" 2 - %s (%iPA)\n",persoc.classe.atq2.nom,persoc.classe.atq2.coutPA);
		//printf(" 3 - %s\n",ordre_action->ec->personnage->classe->spe->nom);
		printf("\n 4 - Retour\n");
		printf("\nVotre choix : ");
		scanf("%d",&choix);
		switch(choix){	

				case 1:
					if(persoc.pa >= persoc.classe.atq1.coutPA) {/*On vérifie si le personnage peu lancer l'attaque.*/
						if(persoc.classe.atq1.type == 1)
							choix_cible1(ordre_action,persoc.classe.atq1,gagnant,carte, mretour);
						else choix_cible2(ordre_action,persoc.classe.atq1,gagnant,carte, mretour);
					} else {
						strcpy(mretour, "\tVous n'avez pas assez de PA\n");
						erreur = vrai;
					}
					break;
				case 2: 
					if(persoc.pa >= persoc.classe.atq2.coutPA) {
						if(persoc.classe.atq2.type == 1)
							choix_cible1(ordre_action,persoc.classe.atq2,gagnant,carte, mretour);
						else choix_cible2(ordre_action,persoc.classe.atq2,gagnant,carte, mretour);
					} else {
						strcpy(mretour, "\tVous n'avez pas assez de PA\n");
						erreur = vrai;
					}
					break;
				//case 3: choix_cible(ordre_action,carte,persoc.classe.ulti); break; Préparation de l'implantation des ulti dans une prochaine version.
				case 4 : break;
				default: strcpy(mretour,"\tVotre choix doit etre compris entre 1 et 4\n"); erreur = vrai;
			}
	} while(choix != 4 && *gagnant == 0);	
}

void choix_action(t_liste *ordre_action, t_map * carte,int *gagnant,int *NbTour){
/**
 * \fn choix_action(t_liste *ordre_action, t_map * carte,int *gagnant,int *NbTour)
 * \brief Permet de choisir son action
 * \param t_liste *ordre_action : la liste des personnages joués triée, t_map * carte matrice représentant la carte, int *gagnant numero de l'équipe gagnante,int *NbTour nombre de tour actuel.
 */
	int choix, erreur = faux;
	t_personnage persoc;
	char mretour[100] = "\n";
	do{
		clearScreen();
		afficherMat(*carte);
		valeur_elt(ordre_action, &persoc);
		if(ordre_action->ec->personnage.joueur == 1)
			couleur("34;1");
		else couleur("31;1");
		printf("%s Equipe :%i %i/%i PV (%iPA) coordonnee %i %i\n",persoc.classe.nom,persoc.joueur, persoc.pv, persoc.classe.PVmax,persoc.pa,persoc.x,persoc.y);
		
		couleur("0");

		printf("\nChoix de l'action :\n");

		if(erreur) {
			couleur("31");
			printf("%s",mretour);
			couleur("0");
		} else {
			couleur("32");
			printf("%s",mretour);
			couleur("0");
		}
		erreur = faux;
		strcpy(mretour,"\n");

		printf(" 1 - Deplacer\n");
		printf(" 2 - Attaquer\n");
		printf(" 3 - Passer\n");
		printf(" 4 - Sauvegarder et quitter\n");
		printf("\nVotre choix : ");
		scanf("%d",&choix);
		switch(choix){	
			case 1: deplacement(ordre_action,*carte); break;
			case 2: choix_competence(ordre_action,gagnant,carte); break;
			case 3: break;
			case 4: quitter_partie(ordre_action, *NbTour, gagnant); break;
			default: strcpy(mretour,"\tVotre choix doit etre compris entre 1 et 4\n"); erreur = vrai;
		}
	} while((choix != 3) && *gagnant == 0);
	passer(ordre_action,NbTour,carte);
}

void gestion_tour(t_liste *ordre_action,int *NbTour,t_map * carte,int *gagnant){
/**
 * \fn  gestion_tour(t_liste *ordre_action,int *NbTour,t_map * carte,int *gagnant)
 * \brief Joue le tour
 * \param t_liste *ordre_action : la liste des personnages joués triée int *gagnant numero de l'équipe gagnante, t_map * carte
 */

	t_personnage persoc;
	valeur_elt(ordre_action, &persoc);
	while(*gagnant ==0){
                if ((*NbTour) >1 && persoc.pa < 20){
                	persoc.pa += (persoc.classe.gainPA);
                }
		choix_action(ordre_action,carte,gagnant,NbTour);
		
	}
        
}

