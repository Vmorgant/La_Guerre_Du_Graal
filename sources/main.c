/**
*\file main.c
*\brief Menu principal et lancement de la partie
*\version 1.0
*\auteur Corentin Petit
*\date 11/11/2016
*/
#include<stdio.h>
#include<stdlib.h> 
#include <unistd.h>
#include <string.h>
#include "global.h"
#include"ges_equipes.h"
#include"listes_ptr.h"
#include"file_chemin.h"
#include"Init_map.h"
#include"deplacement_simp.h"
#include"ges_partie.h"
#include "save.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int init_SDL(){
/**
 * \fn init_SDL
 * \brief Fonction initialisant les différents modules de la SDL utilisés dans le jeu
 */
	if (SDL_Init(SDL_INIT_VIDEO) != 0 ){
       		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
		return -1;
	}
	if( TTF_Init() !=0){
		fprintf(stdout,"Échec de l'initialisation de la SDLttf (%s)\n",TTF_GetError()); 
		return -2;
	}
	fprintf(stdout,"Init OK\n"); 
	return 1;
}
void clearScreen(){
	system("clear");
}
void lancer1v1(SDL_Window* Fenetre,SDL_Surface* Fond,TTF_Font *police,SDL_Surface *message,SDL_Surface *message2,int sdl,SDL_DisplayMode current,int num_menu) {

	t_liste equipe1;
	t_liste equipe2;
	t_liste ordre_action;
	t_map carte=creerMat();

	int choix, erreur = faux;
	int NbTour=1;
	int gagnant=0; 
	int PE1 = 10;
	int PE2 = 10;
	char mretour[100] = "\n";
	police = TTF_OpenFont("../Ressources/police/angelina.ttf", 63);
	SDL_Color textColor = {255,255,255,255};//blanc
	SDL_Event event;
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);/*stockage de l'état des touches du clavier*/
	SDL_Surface *message3=NULL, *message4= NULL,*message5 = NULL;

	/* Initialisation des listes de personnages */
	init_liste(&equipe1);
	init_liste(&equipe2);
	init_liste(&ordre_action);

			
	
	/* Affichage du menu et saisie du choix */
	do  {
		if(sdl==1){
			if (num_menu ==2){
				SDL_Rect HG = {0,0,0,0};/* Coin haut gauche du sprite en haut à gauche de la fenêtre*/
       				SDL_BlitSurface(Fond,NULL,SDL_GetWindowSurface(Fenetre),&HG);

				message = TTF_RenderText_Solid( police, "1- Editer equipe 1", textColor ); 
				SDL_Rect C = {(current.w)/2-message->w/2,(current.h)/2-message->h/2,0,0};
				SDL_BlitSurface(message,NULL,SDL_GetWindowSurface(Fenetre),&C);

				message2 = TTF_RenderText_Solid( police, "2- Editer equipe 2 ", textColor );
				SDL_Rect msg_2= {(current.w)/2-message->w/2,(current.h)/2-message2->h/2 + 50,0,0};
				SDL_BlitSurface(message2,NULL,SDL_GetWindowSurface(Fenetre),&msg_2);

				message3 = TTF_RenderText_Solid( police, "3- Charger une sauvegarde.", textColor ); 
				SDL_Rect msg_3= {(current.w)/2-message->w/2,(current.h)/2-message3->h/2 + 100,0,0};
				SDL_BlitSurface(message3,NULL,SDL_GetWindowSurface(Fenetre),&msg_3);

				message4 = TTF_RenderText_Solid( police, "4- Lancer Partie. ", textColor );
				SDL_Rect msg_4= {(current.w)/2-message->w/2,(current.h)/2-message4->h/2 + 150,0,0};
				SDL_BlitSurface(message4,NULL,SDL_GetWindowSurface(Fenetre),&msg_4); 

				message5 = TTF_RenderText_Solid( police, "5- Retour. ", textColor );
				SDL_Rect msg_5= {(current.w)/2-message->w/2,(current.h)/2-message5->h/2 + 200,0,0};
				SDL_BlitSurface(message5,NULL,SDL_GetWindowSurface(Fenetre),&msg_5); 

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
					SDL_Quit();
					//Fermeture des Fonts qu'on a utilisé
					TTF_CloseFont(police); 
					//On quitte SDL_ttf 
					TTF_Quit();
                    		}
				else if(keystates[SDL_SCANCODE_1]){
					sdl=0;
					choix=1;
					SDL_DestroyWindow(Fenetre);
					SDL_FreeSurface(Fond);
					SDL_FreeSurface(message);
					SDL_FreeSurface(message2);
					SDL_Quit();
					//Fermeture des Fonts qu'on a utilisé
					TTF_CloseFont(police); 
					//On quitte SDL_ttf 
					TTF_Quit();
				}
				else if(keystates[SDL_SCANCODE_2]){
					sdl=0;
					choix=2;
					SDL_DestroyWindow(Fenetre);
					SDL_FreeSurface(Fond);
					SDL_FreeSurface(message);
					SDL_FreeSurface(message2);
					SDL_Quit();
					//Fermeture des Fonts qu'on a utilisé
					TTF_CloseFont(police); 
					//On quitte SDL_ttf 
					TTF_Quit();
				}
				else if(keystates[SDL_SCANCODE_3])
					choix=3;
				else if(keystates[SDL_SCANCODE_4])
					choix=4;
				else if(keystates[SDL_SCANCODE_5])
					choix=5;
					num_menu--;
					sdl=0;
					SDL_DestroyWindow(Fenetre);
					SDL_FreeSurface(Fond);
					SDL_FreeSurface(message);
					SDL_FreeSurface(message2);
					SDL_Quit();
					//Fermeture des Fonts qu'on a utilisé
					TTF_CloseFont(police); 
					//On quitte SDL_ttf 
					TTF_Quit();
                	}	

			
		}
		
		else{
			clearScreen();
			printf("Menu :\n");
			if(erreur) {
				couleur("31");
				printf("%s", mretour);
				couleur("0");
			}else printf("\n");
			erreur = faux;
			printf(" 1- Editer equipe 1.\t\t");
			if(!liste_vide(&equipe1)) {
				printf("L'equipe 1 est constituée de : ");
				couleur("34;1");
				afficher(&equipe1);
				couleur("0");
				printf("(%iPE restant)\n", PE1);
			}else {
				printf("L'equipe 1 est vide.");		
				printf("(%iPE restant)\n", PE1);
			}

			printf(" 2- Editer equipe 2.\t\t");
			if(!liste_vide(&equipe2)) {
				printf("L'equipe 2 est constituée de : ");
				couleur("31;1");
				afficher(&equipe2);
				couleur("0");
				printf("(%iPE restant)\n", PE2);
			}else {
				printf("L'equipe 2 est vide.");		
				printf("(%iPE restant)\n", PE2);
			}

			printf(" 3- Charger une sauvegarde.\n");
			printf(" 4- Lancer Partie.\n");
			printf("\n 5- Retour.\n");
			printf("\nVotre choix : ");
			scanf("%d", &choix);
		}
		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1: init_equipe(&equipe1, 1, &PE1); break;
			case 2: init_equipe(&equipe2, 2, &PE2);  break;
			case 3: if(choix_save(&ordre_action, &NbTour)) {
					carte = actumap(&ordre_action,carte);
					afficherMat(carte);
					while (gagnant == 0){
						gestion_tour(&ordre_action,&NbTour, &carte,&gagnant);
					}
					printf("Le joueur %i a gagné en %i tours\n",gagnant,NbTour);
		                               sleep(1);
					choix = 5;
				} else { 
					printf("Cette sauvegarde est vide\n"); 
					sleep(1); 
				}
				break;
			case 4: if(liste_vide(&equipe1) || liste_vide(&equipe2) ){
					strcpy(mretour, "\tLes deux equipes ne doivent pas etre vides\n");
					erreur = vrai;
					break;
				}
				else{			
					init_partie(&equipe1,&equipe2,&ordre_action);
					placer(&ordre_action, &carte);
					carte=actumap(&ordre_action, carte);
					afficherMat(carte);
					while (gagnant == 0){
						gestion_tour(&ordre_action,&NbTour, &carte,&gagnant);
					}
					printf("Le joueur %i a gagné en %i tours\n",gagnant,NbTour);
                                        sleep(1);
					choix = 5;
					break;
				}
			default: strcpy(mretour, "\tVotre choix doit être compris entre 1 et 4\n"); erreur = vrai;
		}
	
	}while(choix!=5);
	
	supprimer(&equipe1);
	supprimer(&equipe2);
	supprimer(&ordre_action);
	free_map(carte);
	SDL_FreeSurface(message4);
	SDL_FreeSurface(message5);
}


int main(void) {
	int choix, erreur = faux,sdl = 0,i,num_menu =0;
	sdl=init_SDL();
	SDL_Event event;
	SDL_DisplayMode current;
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);/*stockage de l'état des touches du clavier*/
	SDL_Surface* Fond =SDL_LoadBMP("../Ressources/images/menu_principal.bmp");// chargement de l'image du menu principal
	TTF_Font *police=NULL; //stockage de la police
	police = TTF_OpenFont("../Ressources/police/angelina.ttf", 63);
	SDL_Color textColor = {255,255,255,255};//blanc
	SDL_Surface *message=NULL, *message2= NULL; 

	/*Chargement de la résolution courante de l'écran*/
	for(i = 0; i < SDL_GetNumVideoDisplays(); ++i){
		int error = SDL_GetCurrentDisplayMode(i, &current);
			if(error != 0)
      				SDL_Log("Could not get display mode for video display #%d: %s", i, SDL_GetError());
				SDL_Log("Display #%d: current display mode is %dx%dpx @ %dhz.", i, current.w, current.h, current.refresh_rate);

  			}

      	/* Création de la fenêtre a la résolution actuelle de l'écran  */
        SDL_Window* Fenetre = NULL;
       	Fenetre = SDL_CreateWindow("LGDG",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,current.w,current.h,SDL_WINDOW_SHOWN);
	message = TTF_RenderText_Solid( police, "La Guerre Du Graal", textColor ); 
	message2 = TTF_RenderText_Solid( police, "Appuyez sur espace pour continuer ou echap pour quitter", textColor );
	SDL_Rect HG = {0,0,0,0};/* Coin haut gauche du sprite en haut à gauche de la fenêtre*/
	SDL_Rect C = {(current.w)/2-message->w/2,(current.h)/2-message->h/2,0,0};/* centrage du texte*/
	SDL_Rect msg_2= {(current.w)/2-message2->w/2,(current.h)/2-message->h/2+50,0,0} ;
       

	do {	
		if(num_menu==0){
			SDL_BlitSurface(Fond,NULL,SDL_GetWindowSurface(Fenetre),&HG);/*copie dans la fenetre parametre : source,région de la source à copier(NULL si toute la source,surface de destination,emplacement */
			SDL_BlitSurface(message,NULL,SDL_GetWindowSurface(Fenetre),&C);
			SDL_UpdateWindowSurface(Fenetre);/*mise à jour de la fenêtre*/
			SDL_Delay(1000);
			SDL_BlitSurface(message2,NULL,SDL_GetWindowSurface(Fenetre),&msg_2);
			SDL_UpdateWindowSurface(Fenetre);
			num_menu++;
		}
		if(sdl==1){
			while ( SDL_PollEvent(&event) ){
				if(keystates[SDL_SCANCODE_ESCAPE] ||event.window.event == SDL_WINDOWEVENT_CLOSE){
					choix=3;				
					SDL_DestroyWindow(Fenetre);
					SDL_FreeSurface(Fond);
					SDL_FreeSurface(message);
					SDL_FreeSurface(message2);
					SDL_Quit();
					//Fermeture des Fonts qu'on a utilisé 
					TTF_CloseFont(police); 
					//On quitte SDL_ttf 
					TTF_Quit();
                    		}
				else if (keystates[SDL_SCANCODE_SPACE]) { 
					if(num_menu==1){
                       				Fond =SDL_LoadBMP("../Ressources/images/menu2.bmp");
						SDL_BlitSurface(Fond,NULL,SDL_GetWindowSurface(Fenetre),&HG);
						message = TTF_RenderText_Solid( police, "1 - Mode Duel", textColor ); 
						SDL_Rect C = {(current.w)/2-message->w/2,(current.h)/2-message->h/2,0,0};/* centrage du texte*/
						SDL_BlitSurface(message,NULL,SDL_GetWindowSurface(Fenetre),&C);
						message2 = TTF_RenderText_Solid( police, "2 - Credits ", textColor );
						SDL_Rect msg_2= {(current.w)/2-message2->w/2,(current.h)/2-message2->h/2 + 50,0,0};
						SDL_BlitSurface(message2,NULL,SDL_GetWindowSurface(Fenetre),&msg_2); 
						SDL_UpdateWindowSurface(Fenetre);
						num_menu++;
					}
				
                    		}
				if(keystates[SDL_SCANCODE_1])
					choix=1;
				if(keystates[SDL_SCANCODE_2])
					choix=2;
                	}	
			
		}
			
		else{	
			clearScreen();	
	
			printf("Menu :\n");
			if(erreur) {
				couleur("31");
				printf("\tErreur: votre choix doit etre compris entre 1 et 3\n");
				couleur("0");
			} else printf("\n");
			erreur = faux;
			/* Affichage du menu et saisie du choix */
		
			printf(" 1 - Mode Duel\n");
			printf(" 2 - Credits\n");
			printf(" 3 - Quitter\n");
			printf("\nVotre choix : ");
			scanf("%d",&choix);
		}
		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1: lancer1v1(Fenetre,Fond,police,message,message2,sdl,current,num_menu); choix = 3; break;
			case 2: printf("\nJeux realise par Corentin Petit Martin Lebourdais et Victor Morgant \n retrouvez nous sur github https://github.com/Vmorgant/Projet_Algo ou sur gitter https://gitter.im/La-Guerre-du-Graal-L2-SPI"); break;
			case 3: break;
			default: erreur = vrai;
		}
	
	}
	while(choix!=3);

	printf("Au revoir !\n");
	sleep(2);
	clearScreen();
	return EXIT_SUCCESS;
}
