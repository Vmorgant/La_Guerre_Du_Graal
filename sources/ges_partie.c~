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
typedef struct{int nlignes,ncolonnes;int ** cell;}t_map;
t_map creerMat(){
	/*Initialisation de la matrice map à 0*/
    t_map matrice;
    int i, j;
    matrice.cell = (int**) malloc(10 * sizeof(int*));
    for (i=0; i < 10; i++){
        matrice.cell[i] = (int*) malloc(10 * sizeof(int));
        for (j=0; j < 10; j++){    	
        	matrice.cell[i][j] = 0;
        }
            
    }
    return matrice;
}

void permuter(t_noeud *actuel,t_noeud *suivant){
	t_noeud tampon;
	tampon = *actuel;
	*actuel = *suivant;
	*suivant = tampon;
}
t_map actumap(t_personnage * ordre_action, t_map map){
   //Fontion qui actualise la map en place le perso de l'élement courant
       	 
    
    if (ordre_action->ec.equipe == 1){     
        		if (ordre_action->ec.classe.nom == "Saber") map.cell[ordre_action->ec.x][ordre_action->ec.y] = 1; // On place le personnage de la classe indiquée dans l'élément courant à ses coordonées dans la matrice.
        	}
    if (ordre_action->ec.equipe == 2){
        		if (ordre_action->ec.classe.nom == "Saber") map.cell[ordre_action->ec.x][ordre_action->ec.y] = 2;
        	}
    
    return map;
}
void afficherMat (t_map mat){
    int i, j;
    clearscreen();					 //Effacer le terminal
    mat.cell[1][1]=2;
    mat.cell[1][1]=1;
    for (i=0; i < 10; i++){
	    printf("|");
	    for (j=0; j < 10; j++){
	    	if(mat.cell[i][j] == 0) printf(" --- "); 
	    	if(mat.cell[i][j] == 1) {				 //Si la case contient une "Saber" Bleue
	    		couleur("34;1");					 //On écrit en bleu et en gras
	    		printf(" SAB ");					
	    		couleur("0");						 //On réinitialise le système de couleur
	    		
	    	}
	    	if(mat.cell[i][j] == 2) {				 //Si la case contient une "Saber" Rouge
	    		couleur("31;1");					 //On écrit en rouge et en gras
	    		printf(" SAB ");
	    		couleur("0");
	    	}
			
	    }
	printf("|\n");
    }
        printf("\n");
}
void init_liste(t_liste_noeud * p) {
	p->drapeau =  malloc (sizeof(t_element_noeud));
	p->ec =  malloc (sizeof(t_element_noeud));
	p->drapeau -> pred = p->drapeau;
	p->drapeau -> succ = p->drapeau;
	p->ec = p->drapeau;
}
/*Primitives de liste*/
int liste_vide (t_liste_noeud * p) {
	if(p->drapeau -> pred == p->drapeau)
		return 1;
	else return 0;
}

int hors_liste (t_liste_noeud * p) {
	if(p->ec == p->drapeau)
		return 1;
	else return 0;
}

void en_tete (t_liste_noeud * p) {
	p->ec = p->drapeau -> succ;
}

void en_queue (t_liste_noeud * p) {
	p->ec = p->drapeau -> pred;
}

void suivant(t_liste_noeud * p) {
	if (!hors_liste(p)){
		p->ec = p->ec -> succ;
	}
}

void precedent(t_liste_noeud * p) {
	if (!hors_liste(p)){
		p->ec = p->ec -> pred;
	}
}

void valeur_elt(t_liste_noeud * p, t_noeud * v) {
	if(!hors_liste(&p))
		*v = p->ec -> noeud;
}

void modif_elt(t_liste_noeud * p, t_noeud v) {
	if(!hors_liste(&p))
		p->ec -> noeud = v;
}

void oter_elt(t_liste_noeud * p) {
	if(!hors_liste(p)) {
		t_element * temp;
		temp = malloc (sizeof(t_element));
		temp = p->ec;
		suivant(p);
		p->ec -> pred = temp -> pred;
		precedent(p);
		p->ec -> succ = temp -> succ;
		free(temp);
	}
}

void ajout_droit(t_liste_noeud * p, t_noeud v) {
	if (liste_vide(p) || !hors_liste(p) ) {
		t_element * nouv;
		nouv = malloc (sizeof(t_element));
		nouv -> noeud = v;
		nouv -> succ = p->ec -> succ;
		nouv -> pred = p->ec;
		p->ec -> succ = nouv;
		p->(ec -> succ) -> pred = nouv;
	}
}

void ajout_gauche(t_liste_noeud * p, t_noeud v) {
	if (liste_vide(p) || !hors_liste(p) ) {
		t_element * nouv;
		nouv = malloc (sizeof(t_element));
		nouv -> noeud = v;
		nouv -> succ = p->ec;
		nouv -> pred = p->ec -> pred;
		p->ec -> pred = nouv;
		p->(ec -> pred) -> succ = nouv;
	}
}
/*Fin des primitives de liste*/

int existinf(t_liste_noeud liste,t_noeud valeur){
/**Fonction qui teste si il existe le même noeud avec un cout inferieur à la valeur entrée en paramètre dans la liste en paramètre.*/
	en_tete(&liste);
	t_noeud vcour;
	while(!hors_liste(&liste)){
		valeur_elt(&liste,&vcour);
		if ((vcour.x==valeur.x) && (vcour.y==valeur.y) && (vcour.cout<valeur.cout)) return 1;/*On compare les coordonnées pour savoir si le noeud est le même*/
		suivant(&liste);
	}
	return 0;
}
int distance(int x,int y,int objx,int objy){
	/**Calcul de la distance entre le point et l'objectif*/
	int distance =sqrt((objx-x)*(objx-x)+(objy-y)*(objy-y));
	return distance;
}


void pathfinding(int x, int y,int objx,int objy){
    t_noeud depart={x,y,0,0};
    t_liste openlist;				/*Liste des noeuds à tester*/
    t_liste closedlist;				/*Liste des noeuds testés*/
    init_liste(&openlist);
    init_liste(&closedlist);
    ajout_droit(&openlist,depart);
	en_tete(&openlist);
	en_tete(&closedlist);
	t_noeud q;	
	while(!liste_vide(&openlist)){  
			
		valeur_elt(&openlist,&q);
		oter_elt(&openlist);
		if (q.x == objx && q.y == objy){			/*On teste si on est arrivé*/
			en_tete(&openlist);
			while(!hors_liste(&openlist)){
				printf("[%i,%i]\n",openlist.ec->noeud.x,openlist.ec->noeud.y);			
			}
			
			break ;
		}
		t_noeud v1 = {q.x+1,q.y,0,0};
		t_noeud v2 = {q.x,q.y+1,0,0};
		t_noeud v3 = {q.x-1,q.y,0,0};
		t_noeud v4 = {q.x,q.y-1,0,0};
		
		if (existinf(openlist,v1)||existinf(closedlist,v1));				/*On cherche pour chaque voisin de la case si on l'a déjà testée.*/
		else{
			v1.cout=q.cout+1;
			v1.heuristique = v1.cout + distance(v1.x,v1.y,objx,objy);
			ajout_droit(&openlist,v1);
		}

		if (existinf(openlist,v2)||existinf(closedlist,v2));
		else{
			v2.cout=q.cout+1;
			v2.heuristique = v2.cout + distance(v2.x,v2.y,objx,objy);
			ajout_droit(&openlist,v2);
		}

		if (existinf(openlist,v3)||existinf(closedlist,v3));
		else{
			v3.cout=q.cout+1;
			v3.heuristique = v3.cout + distance(v3.x,v3.y,objx,objy);
			ajout_droit(&openlist,v3);
		}
		if (existinf(openlist,v4)||existinf(closedlist,v4));
		else{
			v4.cout=q.cout+1;
			v4.heuristique = v4.cout + distance(v4.x,v4.y,objx,objy);
			ajout_droit(&openlist,v4);
		}
		
		ajout_droit(&closedlist,q); /*On ajoute la case que l'on vient de tester à la liste*/
	
	}	
	
	printf("Fin du programme\n");	
		
	
    
}
void deplacement(t_liste ordre_action, t_map map){
	/** demande les nouvelles coordonnés, vérifie si le déplacement est valide, indique le cout en PA et demande confirmation puis exécute le déplacement*/
	printf("Rentrez des coordonnées séparées par une vigule\n");
	scanf("%i,%i",xobj,yobj);
	printf("\n");
	
	t_liste_noeud openlist;
	t_liste_noeud closedlist;
	init_list(&openlist);
	init_list(&closedlist);
	pathfinding(ordre_action->ec->personnage.x,ordre_action->ec->personnage.y,xobj,yobj,&openlist,&closedlist);     //On cherche le openlist le plus court
	en_tete(&openlist);
	while(openlist.ec->personnage.x != xobj || openlist.ec->personnage.y != yobj){
		
	permuter(openlist.ec,openlist.ec->succ->ec);        //On permute avec la case suivante dans le openlist défini
	ordre_action->ec->personnage.x = openlist.ec->personnage.x;   //On actualise les coordonnées dans les structures des persos
	ordre_action->ec->personnage.y = openlist.ec->personnage.y;
	actumap(ordre_action,map);					  //On actualise la map
	afficherMat(map);							  //On affiche la map
	}

	
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

