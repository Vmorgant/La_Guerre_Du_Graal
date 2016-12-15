/*! \mainpage Projet L2 SPI Martin Lebourdais Corentin Petit Victor Morgant
 *
 * \section intro_sec Présentation du jeu
 * 
 * Ce jeu a été réalisé dans le cadre du projet d’algorithmique de deuxième année de licence SPI. 2 équipes de composées de différents personnage s'affrontent dans un combat à mort.
 * Chaque classe de personnage possède ses forces et faiblesses, ces classes s'inspirent du jeu et de l'animé Fate Stay Night.\n
 * Vous devez utiliser un système unix pour pouvoir utiliser ce programme.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Etape 1 : Téléchargement
 	Télécharger les sources du jeu https://github.com/Vmorgant/Projet_Algo.git\n\n
 	Télécharger les sources de la SDL 2.0 (nécessaire pour la version 2.0) http://libsdl.org/download-2.0.php\n\n
 	Télécharger les sources de la SDL_ttf2 (nécessaire pour la version 2.0)  https://www.libsdl.org/projects/SDL_ttf/\n\n
	Ouvrir un terminal(pour les étapes suivantes).\n\n
 * \subsection step2 Etape 2 : Installation de la SDL 2.0 et sdl 2.ttf (seulement pour la version 2.0)
	Extraire les archives obtenues lors du téléchargement.\n\n
	Entrez la commande "cd" pour vous placer à la racine puis "mkdir SDL" pour créer le dossier de la SDL.\n\n
	Déplacez vous dans le dossier où vous avez extrait l'archive de la SDL2.\n\n
	Entrez la commande :\n
		-"./configure " si vous êtes super-utilisateur \n
		-"./configure --prefix=$HOME/SDL" sinon\n\n
	Entrez la commande "make"\n\n
	Entrez la commande :\n
	-"sudo make install" si vous êtes super-utilisateur \n
	-"make install" sinon\n\n
	Déplacez vous dans le dossier où vous avez extrait l'archive de la SDL_ttf.\n\n
	Entrez la commande :\n
		-"./configure " si vous êtes super-utilisateur 
		-"./configure --prefix=$HOME/SDL" sinon
	Entrez la commande "make"\n\n
	Entrez la commande :\n
	-"sudo make install" si vous êtes super-utilisateur \n
	-"make install" sinon\n\n
\subsection step3 Etape 3 : Installation de la SDL 2.0 et sdl 2.ttf (seulement pour la version 2.0)
	Extraire les archives obtenues lors du téléchargement.\n\n
	Ouvrir un terminal.\n\n
	Entrez la commande "cd" pour vous placer à la racine puis "mkdir SDL" pour créer le dossier de la SDL.\n\n
	Déplacez vous dans le dossier où vous avez extrait l'archive de la SDL2.\n\n
	Entrez la commande :\n
		-"./configure " si vous êtes super-utilisateur\n 
		-"./configure --prefix=$HOME/SDL" sinon\n\n
	Entrez la commande "make"\n\n
	Entrez la commande :\n
	-"sudo make install" si vous êtes super-utilisateur \n
	-"make install" sinon\n\n
	Déplacez vous dans le dossier où vous avez extrait l'archive de la SDL_ttf.\n\n
	Entrez la commande :\n
		-"./configure " si vous êtes super-utilisateur \n
		-"./configure --prefix=$HOME/SDL" sinon\n\n
	Entrez la commande "make"\n\n
	Entrez la commande :\n
	-"sudo make install" si vous êtes super-utilisateur \n
	-"make install" sinon\n\n
* \subsection step4 Etape 4 : Installation du jeu
	Déplacez vous dans le dossier où vous avez extrait l'archive du jeu.\n\n
	Utilisez la commande make.\n\n
	Lancez l'exécutable LGDG.out\n\n
 */
#ifndef GLOBAL_H

#define GLOBAL_H

#include<stdio.h>
#include <unistd.h>
/**
*\file global.h
*\brief Ce fichier contient les définitions de chaque structure globales utilisées dans le projet
*\author Corentin Petit, Martin Lebourdais, Victor Morgant
*\version 1.0
*\date 09/11/2016
*/

void clearScreen();
/**
 * \fn clearScreen
 * \brief Fonction permettant d'effacer l'écran
 */

typedef enum{vrai = 1, faux = 0}t_bool;
/**
*\enum t_bool
*\brief facilite l'identification d'un booleen
*/

typedef enum{mort,vie}t_etat; /*possibilité d'ajouts futurs*/
/**
*\enum t_etat
*\brief facilite l'identification de l'état d'un personnage
*/

typedef struct{int coutPA;float mul_ATQ;int portee;int type;}t_spe;
/**
*\struct t_spe
*\brief boisson alcoolisée saveur tequila
*/

typedef struct{char nom[20];int coutPA;float mul_ATQ;int portee;int type;}t_attaque;
/**
*\struct t_attaque
*\brief contient les caractéristiques d'une attaque
*/

typedef struct{char nom[20]; int coutPE;int PVmax;int gainPA;int ATQ;int DEF;int INI;float poids;t_attaque atq1;t_attaque atq2;/*t_spe spe;*/}t_classe;
/**
*\struct t_classe
*\brief contient les caractéristiques d'une classe de personnage
*/

typedef struct{t_classe classe ; int joueur; int pa; int pv; int x; int y; t_etat etat;}t_personnage;
/**
*\struct t_personnage
*\brief contient les caractéristiques d'un personnage ainsi que son équipe
*/

typedef struct element{t_personnage personnage; struct element* pred; struct element* succ;}t_element;
/**
*\struct t_element
*\brief definition d'une liste de personnage
*/

typedef struct{t_element * drapeau; t_element * ec;}t_liste;
/**
*\struct t_liste
*\brief création du type liste (pour gérer simultanément plusieures listes de type t_personnage
*/

typedef struct{int nlignes; int ncolonnes;int ** cell;}t_map;
/**
*\struct t_map
*\brief défini la carte par son nombre de lignes/colonnes et une matrice.
*/

typedef struct{int x; int y;}t_noeud;
/**
*\struct t_noeud 
*\brief contient les coordonnées d'un noeud
*/

typedef struct{t_personnage tab_action[10]; int nbpersos; int nbtours;}t_save;
/**
*\struct t_save
*\brief contient les données d'une sauvegarde
*/

#define couleur(param) printf("\033[%sm",param)
/*   param devant être un const char *, vide (identique à "0") ou formé
     d'une où plusieurs valeurs séparées par des ; parmi
         0  réinitialisation         1  haute intensité (des caractères)
         5  clignotement             7  video inversé
         30, 31, 32, 33, 34, 35, 36, 37 couleur des caractères
         40, 41, 42, 43, 44, 45, 46, 47 couleur du fond
         les couleurs, suivant la logique RGB, étant respectivement
         noir, rouge, vert, jaune, bleu, magenta, cyan et blanc */

#define nb_classes 7
extern t_classe tab_classes[nb_classes];


#endif
