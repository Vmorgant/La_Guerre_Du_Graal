/**
*\file global.h
*\brief Ce fichier contient les définitions des primitives d'acces aux listes
*\author Corentin Petit
*\version 1.0
*\date 18/11/2016
*/


int charger_save( char  nomsave[34], t_liste * ordre_action, int Nb_tours);
int enregistrer_save( char  nomsave[34], t_liste * ordre_action, int * Nb_tours);
void charger_partie(char mbilan[100]);
void nouvelle_partie(char mbilan[100],SDL_Window* Fenetre,SDL_Surface* Fond,TTF_Font *police,SDL_Surface *message,SDL_Surface *message2,SDL_Surface *message3,SDL_Surface *message4,int sdl,SDL_DisplayMode current,int num_menu);
void quitter_partie(t_liste * ordre_action, int Nb_tours, int *gagnant);

void gerer_save(char mbilan[100]);