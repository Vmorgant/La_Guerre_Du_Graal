/**
*\file ges_partie.h
*\brief Ce fichier contient les définitions des primitives de gestion de la parie.
*\author Corentin Petit
*\version 1.0
*\date 18/11/2016
*/

float Rand_atq();
/**
*\fn Rand_atq()
*\brief Renvoi un nombre aléatoire entre 75 et 125
*\return Nombre aléatoire entre 75 et 125
*/


void init_partie(t_liste *equipe1,t_liste *equipe2, t_liste *ordre_action);
/**
 * \fn init_partie(t_liste *equipe1,t_liste *equipe2, t_liste * ordre_action)
 * \brief concaténation des listes des deux équipes et tri par initiative
 * \param t_liste *equipe1 : la liste des joueurs de l'équipe 1, t_liste *equipe2 : la liste des joueurs de l'équipe 2 t_liste * ordre_action : la liste triée par ordre de jeu.
 */
void placer(t_liste *ordre_action,t_map * carte);
/**
 * \fn  placer(t_liste *ordre_action,t_map carte)
 * \brief Place les personnages des deux équipes sur la carte.
 * \param t_liste * ordre_action : la liste triés par ordre de jeu, t_map carte : la carte 
 */
int est_mort(t_liste *ordre_action,int *gagnant, t_map * carte);
/**
 * \fn  est_mort(t_liste *ordre_action,t_map * carte).
 * \brief Retire le personnage mort de la liste ordre_action, et de la carte.
 * \param t_liste *ordre_action : la liste des personnages triés par ordre de jeu t_map * carte : la carte.
 * \return le numéro de l'équipe qui a gagnée.
 */
void passer(t_liste *ordre_action);
/**
 * \fn  passer(t_liste *ordre_action,int *NbTour,t_map * carte)
 * \brief Passe la main au joueur suivant
 * \param t_liste *ordre_action : la liste des personnages joués triée int *NbTour le nombre ,t_map * carte
 */
void attaquer(t_liste *ordre_action,t_personnage * cible, t_attaque attaque,int *gagnant,t_map * carte, char mretour[100]);
/**
 * \fn  attaquer(t_liste *ordre_action,t_personnage cible, t_attaque attaque,int *gagnant,t_map * carte)
 * \brief exécute l’attaque de l’attaquant vers la cible et actualise les stats et l’état si un personnage meurt appelle la fonction mort
 * \param t_liste *ordre_action : la liste des personnages triés int *NbTour le nombre de tour de jeu ,t_map * carte
 */
int test_obstacle(t_personnage attaquant,t_personnage cible,int portee, t_map * carte);
/**
 * \fn  test_obstacle(t_personnage attaquant,t_personnage cible,int portee, t_map * carte)
 * \brief vérifie s'il y a un obstacle entre l'attaquant et la cible
 * \param t_liste *ordre_action : la liste des personnages triés int *NbTour le nombre de tour de jeu ,t_map * carte
 * \return vrai s'il y a un obstacle
 */
void choix_cible1(t_liste *ordre_action,t_attaque attaque,int *gagnant,t_map * carte, char mretour[100]);
/**
 * \fn choix_cible(t_liste *ordre_action, t_attaque attaque,int *gagnant, t_map * carte)
 * \brief donne la liste des cibles qui sont a portée de l'attaquant
 * \param t_liste *ordre_action : la liste des personnages triés int *NbTour le nombre de tour de jeu ,t_map * carte
 */ 

void choix_cible2(t_liste *ordre_action,t_attaque attaque,int *gagnant,t_map * carte, char mretour[100]);
/**
 * \fn choix_cible(t_liste *ordre_action, t_attaque attaque,int *gagnant, t_map * carte)
 * \brief donne la liste des cibles qui sont a portée de l'attaquant
 * \param t_liste *ordre_action : la liste des personnages triés int *NbTour le nombre de tour de jeu ,t_map * carte
 */ 

void choix_competence(t_liste *ordre_action,t_map * carte,int *gagnant);
/**
 * \fn  choix_competence(t_liste *ordre_action,int *gagnant,t_map * carte)
 * \brief Permet de choisir son attaque
 * \param t_liste *ordre_action : la liste des personnages joués triée int *gagnant numero de l'équipe gagnante, t_map * carte
 */

void choix_action(t_liste *ordre_action, t_map * carte,int *gagnant,int *NbTour);
/**
 * \fn choix_action(t_liste *ordre_action, t_map * carte,int *gagnant,int *NbTour)
 * \brief Permet de choisir son action
 * \param t_liste *ordre_action : la liste des personnages joués triée, t_map * carte matrice représentant la carte, int *gagnant numero de l'équipe gagnante,int *NbTour nombre de tour actuel.
 */

void gestion_tour(t_liste *ordre_action,int *NbTour,t_map * carte,int *gagnant);
/**
 * \fn  gestion_tour(t_liste *ordre_action,int *NbTour,t_map * carte,int *gagnant)
 * \brief Joue le tour
 * \param t_liste *ordre_action : la liste des personnages joués triée int *gagnant numero de l'équipe gagnante, t_map * carte
 */







