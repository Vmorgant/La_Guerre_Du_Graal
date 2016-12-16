/**
*\file ges_equipes.h
*\brief Ce fichier contient les définitions des fonctions permettant de modifier les équipes.
*\author Corentin Petit
*\version 1.0
*\date 16/11/2016
*/

int creer_perso(t_liste * equipe, t_classe classe, int joueur, int * PE, char mretour[100]);
/**
 * \fn creer_perso(t_liste * equipe, t_classe classe, int joueur, int * PE)
 * \brief Crée un personnage de la classe choisie.
 * \param t_liste * equipe : la liste des personnage ,t_classe classe : la classe du personnage à ajouter,  int joueur : l'identifiant du joueur, int *PE le nombre de PE restant  .
 */
void ajout_equipe(t_liste * equipe, int joueur, int * PE,SDL_Window* Fenetre,SDL_Surface* Fond,TTF_Font *police,SDL_Surface *message,SDL_Surface *message2,SDL_Surface *message3,SDL_Surface *message4,int sdl,SDL_DisplayMode current,int num_menu);
/**
 * \fn ajout_equipe(t_liste * equipe, int joueur, int * PE)
 * \brief Ajoute le personnage à l'équipe.
 * \param t_liste * equipe : la liste des personnage, int joueur : l'identifiant du joueur, int *PE le nombre de PE restant.
 */
void oter_equipe(t_liste * equipe, int joueur, int* PE);
/**
 * \fn  oter_equipe(t_liste * equipe, int joueur, int *PE)
 * \brief Retire un personnage de la liste.
 * \param t_liste * equipe : la liste des personnage, int joueur : l'identifiant du joueur, int *PE le nombre de PE restant.
 */
void init_equipe(t_liste * equipe, int joueur, int * PE,SDL_Window* Fenetre,SDL_Surface* Fond,TTF_Font *police,SDL_Surface *message,SDL_Surface *message2,SDL_Surface *message3,SDL_Surface *message4,int sdl,SDL_DisplayMode current,int num_menu);
/**
 * \fn  init_equipe(t_liste * equipe, int joueur)
 * \brief Menu de création d'équipe.
 * \param t_liste * equipe : la liste des personnage, int joueur : l'identifiant du joueur,int *PE le nombre de PE restant.
 */