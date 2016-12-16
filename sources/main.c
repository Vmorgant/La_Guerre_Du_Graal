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
#include "../includes/global.h"
#include"../includes/ges_equipes.h"
#include"../includes/listes_ptr.h"
#include"../includes/file_chemin.h"
#include"../includes/Init_map.h"
#include"../includes/deplacement_simp.h"
#include"../includes/ges_partie.h"
#include "../includes/save.h"
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
void scanclav(char chaine[200], int i){
/**
 * \fn clearScreen
 * \brief Fonction pour recupérer une saisie clavier
 * \param char chaine[200] : chiane dans laqulle ont stocke la saisie, int i : taille maximum de la chaine à lire
 */
	char *p, c;

	if(c = fgets(chaine, i+1, stdin) != NULL){}; /* recupère la chaine */
	if(strchr(chaine, '\n') == NULL){ /* revide le buffer au cas ou il y ai plus de 30 caractères */
		while ((c = getchar()) != '\n' &&  c != EOF){} 
	}
	p = strchr(chaine, '\n'); /* cherche le '\n' à la fin */
	if (p) *p = 0; /* enleve le '\n' à la fin */
}

void clearScreen(){
/**
 * \fn clearScreen
 * \brief Fonction permettant d'effacer l'écran
 */
	system("clear");
}


int main(void) {
	int choix, erreur = faux,sdl = 0,i,num_menu =0;;
	sdl=init_SDL();
	SDL_Event event;
	SDL_DisplayMode current;
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);/*stockage de l'état des touches du clavier*/
	SDL_Surface* Fond =SDL_LoadBMP("./Ressources/images/menu_principal.bmp");// chargement de l'image du menu principal
	TTF_Font *police=NULL; //stockage de la police
	police = TTF_OpenFont("./Ressources/police/angelina.ttf", 63);
	SDL_Color textColor = {255,255,255,255};//blanc
	SDL_Surface *message=NULL, *message2= NULL,*message3= NULL,*message4= NULL; 

	char mretour[100]="\n";
	char chaine[30];
	char* fin = NULL;
	char temp[50];

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
					choix=5;				
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
				else if (keystates[SDL_SCANCODE_SPACE]) { 
					if(num_menu==1){
                       				Fond =SDL_LoadBMP("./Ressources/images/menu2.bmp");
						SDL_BlitSurface(Fond,NULL,SDL_GetWindowSurface(Fenetre),&HG);
						message = TTF_RenderText_Solid( police, "1 - Mode Duel", textColor ); 
						SDL_Rect C = {(current.w)/2-message->w/2,(current.h)/2-message->h/2,0,0};/* centrage du texte*/
						SDL_BlitSurface(message,NULL,SDL_GetWindowSurface(Fenetre),&C);
						message2 = TTF_RenderText_Solid( police, "2 - Charger partie ", textColor );
						SDL_Rect msg_2= {(current.w)/2-message->w/2,(current.h)/2-message2->h/2 + 50,0,0};
						SDL_BlitSurface(message2,NULL,SDL_GetWindowSurface(Fenetre),&msg_2); 
						message3 = TTF_RenderText_Solid( police, "3 - Gestion des sauvegardes.", textColor ); 
						SDL_Rect msg_3= {(current.w)/2-message->w/2,(current.h)/2-message3->h/2 + 100,0,0};
						SDL_BlitSurface(message3,NULL,SDL_GetWindowSurface(Fenetre),&msg_3);
						message4 = TTF_RenderText_Solid( police, "4 - Credits ", textColor );
						SDL_Rect msg_4= {(current.w)/2-message->w/2,(current.h)/2-message4->h/2 + 150,0,0};
						SDL_BlitSurface(message4,NULL,SDL_GetWindowSurface(Fenetre),&msg_4); 
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
			couleur("33;1");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t __          ___           _______  __    __   _______ .______      .______       _______     _______   __    __       _______ .______          ___           ___       __      \n");
			printf("\t\t\t|  |        /   \\         /  _____||  |  |  | |   ____||   _  \\     |   _  \\     |   ____|   |       \\ |  |  |  |     /  _____||   _  \\        /   \\         /   \\     |  |     \n");
			printf("\t\t\t|  |       /  ^  \\       |  |  __  |  |  |  | |  |__   |  |_)  |    |  |_)  |    |  |__      |  .--.  ||  |  |  |    |  |  __  |  |_)  |      /  ^  \\       /  ^  \\    |  |     \n");
			printf("\t\t\t|  |      /  /_\\  \\      |  | |_ | |  |  |  | |   __|  |      /     |      /     |   __|     |  |  |  ||  |  |  |    |  | |_ | |      /      /  /_\\  \\     /  /_\\  \\   |  |     \n");
			printf("\t\t\t|  `----./  _____  \\     |  |__| | |  `--'  | |  |____ |  |\\  \\----.|  |\\  \\----.|  |____    |  '--'  ||  `--'  |    |  |__| | |  |\\  \\----./  _____  \\   /  _____  \\  |  `----.\n");
			printf("\t\t\t|_______/__/     \\__\\     \\______|  \\______/  |_______|| _| `._____|| _| `._____||_______|   |_______/  \\______/      \\______| | _| `._____/__/     \\__\\ /__/     \\__\\ |_______|\n");

			printf("\n\n");
			couleur("0");
			printf("\t\t\t\t\t\t\t\t\t\t\t Appuyez sur Entrée pour continuer ");
			scanclav(mretour, 0);
			clearScreen();	
	
			printf("Menu :\n");
			if(erreur) {
				couleur("31");
				printf("%s", mretour);
				couleur("0");
			} else {
				couleur("32");
				printf("%s", mretour);
				couleur("0");
			}
			strcpy(mretour, "\n");
			erreur = faux;
			/* Affichage du menu et saisie du choix */
		
			printf(" 1 - Nouvelle Partie\n");
			printf(" 2 - Charger une partie\n");
			printf(" 3 - Gestion des sauvegardes\n");
			printf(" 4 - Credits\n");
			printf(" 5 - Quitter\n");
			printf("\nVotre choix : ");
			scanclav(chaine, 30);
			choix = strtol(chaine, &fin, 10);
		}
		/* Traitement du choix de l'utilisateur */
		switch(choix) {
			case 1: nouvelle_partie(mretour,Fenetre,Fond,police,message,message2,message3,message4,sdl,current,num_menu); break;
			case 2: charger_partie(mretour); break;
			case 3: gerer_save(mretour); break;
			case 4: strcpy(mretour, "\tJeu realise par Corentin Petit Martin Lebourdais et Victor Morgant \n retrouvez nous sur github https://github.com/Vmorgant/Projet_Algo ou sur gitter https://gitter.im/La-Guerre-du-Graal-L2-SPI"); break;
			case 5: break;
			default: strcpy(mretour, "\tErreur: votre choix doit etre compris entre 1 et 3\n"); erreur = vrai;
		}
	
	}
	while(choix!=5);

	printf("Au revoir !\n");
	sleep(2);
	clearScreen();
	return EXIT_SUCCESS;
}
