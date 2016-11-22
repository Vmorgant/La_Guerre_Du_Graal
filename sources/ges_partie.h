/**
*\file global.h
*\brief Ce fichier contient les définitions des primitives d'acces aux listes
*\author Corentin Petit
*\version 1.0
*\date 18/11/2016
*/

int Rand_Int(int a, int b);
void init_partie(t_liste *equipe1,t_liste *equipe2, t_liste *ordre_action);
void placer(t_liste equipe1,t_liste equipe2,t_map carte);
int est_mort(t_liste *ordre_action,t_personnage cadavre,int *gagnant);
void passer(t_liste *ordre_action);
void attaquer(t_liste *ordre_action,t_personnage cible, t_attaque attaque,int *gagnant);
void choix_cible(t_liste *ordre_action, t_map carte, t_attaque attaque,int *gagnant);
void choix_competence(t_liste *ordre_action,t_map carte,int *gagnant);
void gestion_tour(t_liste *ordre_action,int *NbTour,t_map carte,int *gagnant);