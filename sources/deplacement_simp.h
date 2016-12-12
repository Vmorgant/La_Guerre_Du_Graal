/**
*\file deplacement_simp.h
*\brief Ce fichier contient les en-tête de la version simplifiée des fonctions de déplacement sur la carte.
*\author Martin Lebourdais
*\version 1.0
*\date 22/11/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"
#include "liste_chemin.h"
#include "Init_map.h"

int deplacement_simp(t_liste *ordre_action,t_map map, char** mretour);