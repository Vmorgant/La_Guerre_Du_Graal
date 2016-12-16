/**
*\file ges_equipes.c
*\brief Ce fichier contient les fonctions permettant de modifier les équipes.
*\author Corentin Petit
*\version 1.0
*\date 16/11/2016
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include "../includes/global.h"
#include "../includes/ges_equipes.h"
#include"../includes/listes_ptr.h"
	
int creer_perso(t_liste * equipe, t_classe classe, int joueur, int * PE, char mretour[100]) {
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
	strcpy(mretour, "\tVous n'avez pas les PE requis pour ajouter ce personnage !\n");
	}
}

void ajout_equipe(t_liste * equipe, int joueur, int * PE,SDL_Window* Fenetre,SDL_Surface* Fond,TTF_Font *police,SDL_Surface *message,SDL_Surface *message2,SDL_Surface *message3,SDL_Surface *message4,int sdl,SDL_DisplayMode current,int num_menu) {
/**
 * \fn ajout_equipe(t_liste * equipe, int joueur, int * PE)
 * \brief Ajoute le personnage à l'équipe.
 * \param t_liste * equipe : la liste des personnage, int joueur : l'identifiant du joueur, int *PE le nombre de PE restant.
 */

	int choix, i, erreur= faux,x,y;
	char mretour[100] = "\n";
	char chaine[30];
	char* fin = NULL;
	police = TTF_OpenFont("./Ressources/police/angelina.ttf", 63);
	SDL_Surface* classe =SDL_LoadBMP("./Ressources/images/classe.bmp");//chargement de l'image représentant les classes
	SDL_Color textColor = {255,255,255,255};//blanc
	SDL_Event event;
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);/*stockage de l'état des touches du clavier*/
	SDL_Rect select,pos_equipe;
	pos_equipe.x = current.w/2;
	pos_equipe.y = 0;
	do {	
		if(sdl==1){
			if (num_menu ==4){
				SDL_Rect HG = {0,0,0,0};/* Coin haut gauche du sprite en haut à gauche de la fenêtre*/
       				
				message = TTF_RenderText_Solid( police, "Cliquez sur le personnage a ajouter dans votre equipe ", textColor ); 
				SDL_Rect C = {(current.w)/2-message->w/2,(current.h)/2-message->h/2,0,0};
				SDL_BlitSurface(Fond,NULL,SDL_GetWindowSurface(Fenetre),&HG);
				SDL_BlitSurface(classe,NULL,SDL_GetWindowSurface(Fenetre),&HG); 
				SDL_BlitSurface(message,NULL,SDL_GetWindowSurface(Fenetre),&C);
				message2 = TTF_RenderText_Solid( police, "L'equipe est composee de", textColor );
				SDL_BlitSurface(message2,NULL,SDL_GetWindowSurface(Fenetre),&pos_equipe);
				SDL_UpdateWindowSurface(Fenetre);
				num_menu++;
			}
			while ( SDL_PollEvent(&event) ){
				if(SDL_GetMouseState(&x,&y) & SDL_BUTTON(1)) {//si on clique gauche
					if (pos_equipe.y+50+160 < current.h/2 )
						pos_equipe.y=pos_equipe.y+50;	
					else {
						pos_equipe.y=50;
						pos_equipe.x = pos_equipe.x+220;
					}
	   				 if (x < 213) { 
						if(y <160){
		                			choix=1;//Saber
							SDL_Delay(500);
							select.x=0;
							select.y=0;
							select.w=213;
							select.h=160;
							SDL_BlitSurface(classe,&select,SDL_GetWindowSurface(Fenetre),&pos_equipe);
							SDL_UpdateWindowSurface(Fenetre);
						}
						else if (y < 320) { 
							choix=2;//Archer
				 			SDL_Delay(500);
							select.x=0;
							select.y=160;
							select.w=213;
							select.h=160;
							SDL_BlitSurface(classe,&select,SDL_GetWindowSurface(Fenetre),&pos_equipe);;
							SDL_UpdateWindowSurface(Fenetre);
		               				
						}
						else if (y <480){
							choix=4;//Berserker
							SDL_Delay(500);
							select.x=0;
							select.y=320;
							select.w=213;
							select.h=160;
							SDL_BlitSurface(classe,&select,SDL_GetWindowSurface(Fenetre),&pos_equipe);
							SDL_UpdateWindowSurface(Fenetre);

						}
		                 
		            		}
				
					else if (x < 426) { 
						if(y <160){
		                			choix=5;//Lancer 
							SDL_Delay(500);
							select.x=213;
							select.y=0;
							select.w=213;
							select.h=160;
							SDL_BlitSurface(classe,&select,SDL_GetWindowSurface(Fenetre),&pos_equipe);
							SDL_UpdateWindowSurface(Fenetre);
							
						}
						else if (y < 320) { 
		               				choix=3;//Caster
							SDL_Delay(500);
							select.x=213;
							select.y=160;
							select.w=213;
							select.h=160;
							SDL_BlitSurface(classe,&select,SDL_GetWindowSurface(Fenetre),&pos_equipe);
							SDL_UpdateWindowSurface(Fenetre);
							
						}
						else if (y < 480) { 
		               				choix=6;//Rider 
							SDL_Delay(500);
							select.x=213;
							select.y=320;
							select.w=213;
							select.h=160;
							SDL_BlitSurface(classe,&select,SDL_GetWindowSurface(Fenetre),&pos_equipe);
							SDL_UpdateWindowSurface(Fenetre);
								
		            			}
		                
		            		}
					else if(x <640){
						if(y <160){
		                			choix=7;//Assassin 
							SDL_Delay(500);
							select.x=426;
							select.y=0;
							select.w=213;
							select.h=160;
							SDL_BlitSurface(classe,&select,SDL_GetWindowSurface(Fenetre),&pos_equipe);
							SDL_UpdateWindowSurface(Fenetre);
								
						}
					
					}
				}
			}
		}
		else{
			clearScreen();
			/* Affichage du menu et saisie d'une classe */
			printf("Choisissez une classe : \n");
			if(erreur) {
				couleur("31");				//Ecris en rouge
				printf("%s", mretour);
				couleur("0");
			} else {
				couleur("32");				//Ecris en vert
				printf("%s", mretour);
				couleur("0");
			}	
			strcpy(mretour, "\n");	
			erreur = faux;		

			if(!liste_vide(equipe)) {
				printf("l'equipe %i est constituée de : ", joueur);
				if(joueur == 1)
					couleur("34;1");
				else couleur("31;1");
					afficher(equipe);
					couleur("0");
					printf("(%iPE restant)\n\n", *PE);
				}else {
					printf("l'equipe %i est vide.", joueur);		
					printf("(%iPE restant)\n\n", *PE);
				}
		
		
			for(i =1; i <= nb_classes; i++){
				printf(" %i - %s (%iPE)\n", i, tab_classes[i-1].nom, tab_classes[i-1].coutPE);
			}
			printf("\n %i - Retour\n", nb_classes+1);
			printf("\nVotre choix : ");
			scanclav(chaine, 30);				//Scanf sécurisé pour éviter les erreurs de frappes
			choix = strtol(chaine, &fin, 10);		//Conversion de la chaine de caractère en int
		}
		/* Traitement du choix de l'utilisateur */
		if(choix >= 1 && choix <= nb_classes){
			erreur = creer_perso(equipe, tab_classes[choix-1], joueur, PE, mretour);
		} else if (choix < 1 || choix > nb_classes+1) {
			sprintf(mretour, "\tVotre choix doit être compris entre 1 et %i\n", nb_classes+1);
			erreur = vrai;			
		}

	} while (choix != nb_classes+1);
}



void oter_equipe(t_liste * equipe, int joueur, int *PE){
/**
 * \fn  oter_equipe(t_liste * equipe, int joueur, int *PE)
 * \brief Retire un personnage de la liste.
 * \param t_liste * equipe : la liste des personnage, int joueur : l'identifiant du joueur, int *PE le nombre de PE restant.
 */
	int nb_persos = 0, i, choix, erreur = faux;
	char chaine[30];
	char mretour[100] = "\n";
	char* fin = NULL;
	t_personnage persoc;

	do {
		clearScreen();

		compter_elts(equipe, &nb_persos);

		/* Affichage du menu et saisie du choix */
		printf("Edition de l'équipe %i :\n", joueur);
		if(erreur) {
			couleur("31");
			printf("%s", mretour);
			couleur("0");
		} else {
			couleur("32");
			printf("%s", mretour);
			couleur("0");
		}
		erreur = faux;
		strcpy(mretour, "\n");

		if(!liste_vide(equipe)){
			en_tete(equipe);
			/* Affichage du menu et saisie du choix */
			for (i =1; i <= nb_persos; i++){
				valeur_elt(equipe, &persoc);
				printf(" %i - Enlever %s de l'equipe %i\n", i, persoc.classe.nom, joueur);
				suivant(equipe);
			}
			printf("\n %i - Retour\n", nb_persos+1);
			printf("\nVotre choix : ");
			scanclav(chaine, 30);
			choix = strtol(chaine, &fin, 10);

			/* Traitement du choix de l'utilisateur */
			if(choix >= 1 && choix <= nb_persos){
				en_tete(equipe);
				for (i = 1; i < choix; i++){
					suivant(equipe);
				}
				valeur_elt(equipe, &persoc);
				* PE += persoc.classe.coutPE;
				sprintf(mretour, "\t%s a été retiré de l'equipe.\n", persoc.classe.nom);
				oter_elt(equipe);
			}else if(choix > nb_persos+1) { 
				strcpy(mretour, "\tPersonnage non existant.\n");
				erreur = vrai;
			}
		} else break;
		/*Affichage de l'équipe après modification*/
		printf("l'equipe %i est constituée de : ", joueur);
		afficher(equipe);
		printf("(%iPE restant)\n", *PE);
	} while (choix != nb_persos+1);
}

void init_equipe(t_liste * equipe, int joueur, int * PE,SDL_Window* Fenetre,SDL_Surface* Fond,TTF_Font *police,SDL_Surface *message,SDL_Surface *message2,SDL_Surface *message3,SDL_Surface *message4,int sdl,SDL_DisplayMode current,int num_menu) {
/**
 * \fn  init_equipe(t_liste * equipe, int joueur)
 * \brief Menu de création d'équipe.
 * \param t_liste * equipe : la liste des personnage, int joueur : l'identifiant du joueur,int *PE le nombre de PE restant.
 */	
	int choix, erreur= faux;
	char mretour[100] = "\n";
	char chaine[30];
	char* fin = NULL;
	police = TTF_OpenFont("./Ressources/police/angelina.ttf", 63);
	SDL_Color textColor = {255,255,255,255};//blanc
	SDL_Event event;
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);/*stockage de l'état des touches du clavier*/
		
	do {
	
		if(sdl==1){
			if (num_menu ==3){
				SDL_Rect HG = {0,0,0,0};/* Coin haut gauche du sprite en haut à gauche de la fenêtre*/
       				SDL_BlitSurface(Fond,NULL,SDL_GetWindowSurface(Fenetre),&HG);

				message = TTF_RenderText_Solid( police, "1 - Ajouter un personnage dans l'equipe", textColor ); 
				SDL_Rect C = {(current.w)/2-message->w/2,(current.h)/2-message->h/2,0,0};
				SDL_BlitSurface(message,NULL,SDL_GetWindowSurface(Fenetre),&C);

				message2 = TTF_RenderText_Solid( police, "2 - Supprimer un personnage de l'equipe", textColor );
				SDL_Rect msg_2= {(current.w)/2-message->w/2,(current.h)/2-message2->h/2 + 50,0,0};
				SDL_BlitSurface(message2,NULL,SDL_GetWindowSurface(Fenetre),&msg_2);

				message3 = TTF_RenderText_Solid( police, "3 - Valider l'equipe ", textColor ); 
				SDL_Rect msg_3= {(current.w)/2-message->w/2,(current.h)/2-message3->h/2 + 100,0,0};
				SDL_BlitSurface(message3,NULL,SDL_GetWindowSurface(Fenetre),&msg_3);

				message4 = TTF_RenderText_Solid( police, "4 - Annuler ", textColor );
				SDL_Rect msg_4= {(current.w)/2-message->w/2,(current.h)/2-message4->h/2 + 150,0,0};
				SDL_BlitSurface(message4,NULL,SDL_GetWindowSurface(Fenetre),&msg_4); 

				SDL_UpdateWindowSurface(Fenetre);
				num_menu++;
			}
			
			while ( SDL_PollEvent(&event) ){
				if(keystates[SDL_SCANCODE_ESCAPE] ||event.window.event == SDL_WINDOWEVENT_CLOSE){
					choix=3;				
					SDL_DestroyWindow(Fenetre);
					SDL_FreeSurface(Fond);
					SDL_FreeSurface(message);
					SDL_FreeSurface(message2);
					SDL_FreeSurface(message3);
					SDL_FreeSurface(message4);
					SDL_Quit();
					//Fermeture des Fonts qu'on a utilisé
					TTF_CloseFont(police); 
					//On quitte SDL_ttf 
					TTF_Quit();
                    		}
				else if(keystates[SDL_SCANCODE_1]){
					choix=1;
				}
				else if(keystates[SDL_SCANCODE_2]){
					sdl=0;
					choix=2;
					SDL_DestroyWindow(Fenetre);
					SDL_FreeSurface(Fond);
					SDL_FreeSurface(message);
					SDL_FreeSurface(message2);
					SDL_FreeSurface(message3);
					SDL_FreeSurface(message4);
					SDL_Quit();
					//Fermeture des Fonts qu'on a utilisé
					TTF_CloseFont(police); 
					//On quitte SDL_ttf 
					TTF_Quit();
				}
				else if(keystates[SDL_SCANCODE_3]){
					choix=3;
					SDL_DestroyWindow(Fenetre);
					SDL_FreeSurface(Fond);
					SDL_FreeSurface(message);
					SDL_FreeSurface(message2);
					SDL_FreeSurface(message3);
					SDL_FreeSurface(message4);
					SDL_Quit();
					//Fermeture des Fonts qu'on a utilisé
					TTF_CloseFont(police); 
					//On quitte SDL_ttf 
					TTF_Quit();
				}
				else if(keystates[SDL_SCANCODE_4]){
					choix=4;
					SDL_DestroyWindow(Fenetre);
					SDL_FreeSurface(Fond);
					SDL_FreeSurface(message);
					SDL_FreeSurface(message2);
					SDL_FreeSurface(message3);
					SDL_FreeSurface(message4);
					SDL_Quit();
					//Fermeture des Fonts qu'on a utilisé
					TTF_CloseFont(police); 
					//On quitte SDL_ttf 
					TTF_Quit();
				}
			}
		}
		
		else{
			clearScreen();
			/* Affichage du menu et saisie du choix */
			printf("Edition de l'équipe %i :\n", joueur);
			if(erreur) {
				couleur("31");
				printf("%s", mretour);
				couleur("0");
			} else {
				couleur("32");
				printf("%s", mretour);
				couleur("0");
			}
			erreur = faux;
			strcpy(mretour, "\n");
	
			if(!liste_vide(equipe)) {	
				printf("l'equipe %i est constituée de : ", joueur);
				if(joueur == 1)
					couleur("34;1");
				else couleur("31;1");
				afficher(equipe);
				couleur("0");
				printf("(%iPE restant)\n\n", *PE);
			}else {
				printf("l'equipe %i est vide.", joueur);		
				printf("(%iPE restant)\n\n", *PE);
			}
			/*Menu*/
			printf(" 1 - Ajouter un personnage dans l'equipe %i\n", joueur);
			printf(" 2 - Supprimer un personnage de l'equipe %i\n", joueur);
			couleur("32");
			printf(" 3 - Valider l'equipe %i\n", joueur);
			couleur("0");
			printf("\n 4 - Annuler\n");

			printf("\nVotre choix : ");
			scanclav(chaine, 30);
			choix = strtol(chaine, &fin, 10);
		}
		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1: ajout_equipe(equipe, joueur, PE,Fenetre,Fond,police,message,message2,message3,message4,sdl,current,num_menu); break;
			case 2: oter_equipe(equipe, joueur, PE); break;
			case 3: break;
			case 4: vider(equipe); *PE = 10; choix = 3; break;
			default: strcpy(mretour, "\tVotre choix doit être un entier compris entre 1 et 4\n"); erreur = vrai;// On garde le message d'erreur affiché
		}
	} while(choix!=3);/*Validation de l'équipe*/
}
