/**Contient toutes les fonctions de calculs du projet */

#include"calcul.h"

/** Fonction renvoyant un nombre compris entre a et b*/
int Rand_Int(int a, int b){
	int nombre_aleatoire = 0;
	srand(time(NULL));
    nombre_aleatoire = rand()%(b-a)+a;
	return nombre_aleatoire;
}

