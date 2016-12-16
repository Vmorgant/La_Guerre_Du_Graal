/**
*\file file_chemin.h
*\brief Ce fichier contient les définitions des primitives d'acces aux files de noeuds
*\author Martin Lebourdais
*\version 2.0
*\date 01/12/2016
*/
#include<stdio.h>
#include<stdlib.h>
#include "global.h"




void initfile();
void ajouter(t_noeud i);
void retirer(t_noeud *i);
int filevide();