/**
*\file Init_map.h
*\brief Ce fichier contient les définitions des fonctions permettant la création de la map
*\version 1.0
*\author Martin Lebourdais
*\date 18/11/2016
*/


#define couleur(param) printf("\033[%sm",param)

t_map creerMat();
/**
 * \fn creerMat()
 * \brief Fonction initialisant la matrice 10/10
 * \return une matrice d'entier remplie de 0
 */
t_map actumap(t_liste * ordre_action, t_map map);
/**
 * \fn actumap(t_liste * ordre_action, t_map map)
 * \brief  Fontion qui actualise la map en placant les indices des personnages aux bonnes coordonnées de la matrice
* \param t_liste * ordre_action la liste des personnages triée t_map map une matrice d'entier .
 * \return une matrice d'entier avec les indices des personnages à leurs coordonnées
 */
void afficherMat (t_map mat);
/**
 * \fn afficherMat (t_map mat)
 * \brief  Fontion qui affiche la carte dans le terminal en placant les trois premières lettre du nom de la classe à la case contenant l'indice correspondant
* \param t_liste * ordre_action la liste des personnages triée t_map map une matrice d'entier .
 */
void free_map(t_map map);
/**
 * \fn free_map(t_map map)
 * \brief  Fontion qui libère la mémoire utilisée par la carte.
* \param t_map map une matrice d'entier .
 */