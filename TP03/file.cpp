//
//  file.cpp
//  TP03
//
//  Created by Oncle D. on 03/10/2014.
//  Copyright (c) 2014 Oncle D. All rights reserved.
//

#include "file.h"


//Initialisation d'une file d'attente
//Paramètre de sortie : Un file d'attente
//Post-condition : La file d'attente est initialisée
void init(struct FileAttente &f)
{
    f.debut=NULL;
    f.fin=NULL;
}

// Procédure permettant de désinitialiser une liste d'attente
// Paramètre d'entrée : une liste d'attente
// Paramètre de sortie : une liste d'attente
// Pré-condition : la liste est initialisée
// Post-condition : la liste est vidée et désinitialisée
void desInit(struct FileAttente &f)
{
    struct maillon *tmp;
    tmp = f.debut;
    
    // while ((*tmp).suivant != NULL) {
    //     tmp = (*tmp).suivant;
    //     supprEnTete(f);
    // }

	while (f.debut != NULL) {
		supprEnTete(f);
	}
    
    f.debut = NULL;
    f.fin = NULL;
}

//Procédure permettant l'ajout d'un élément en queue de file
//Paramètres d'entrée : Une file d'attente
//						Un pointeur de maillon
//Paramètres de sortie : Une file d'attente ayant un élément en plus
//Pré-conditions : La file est initialisée
//Post-conditions : La file a l'élément passé en paramètre en queue
void ajoutEnQueue( struct FileAttente &f, struct maillon *p)
{
    if (f.fin != NULL)
    {
        (*(f.fin)).suivant=p;
        (f.fin) = p;
    }
    else
    {
        f.fin = p;
        f.debut = p;
    }
}

// Procédure permettant de retirer l'élément en tête de file
// Paramètres d'entrée : Une file d'attente
// Paramètre de sortie : Une file d'attente sans l'élément de tête
// Pré-condition : file initialisée
// Post-condition : L'élément de tête a été supprimé
void supprEnTete(struct FileAttente &f)
{
    struct maillon *tmp;
    tmp = f.debut;
    
    if (tmp != NULL)
    {
        tmp = (*tmp).suivant;
		
		if (f.debut == f.fin) { // Il n'y a qu'un élément
			delete f.debut;
			f.debut = NULL;
			f.fin = NULL;
		}
		else {
			delete f.debut;
			f.debut = tmp;
		}
    }
}

//Fonction permettant de consulter la personne en tête de file
//Paramètres d'entrée : Une file d'attente
//Valeur retournée : La personne en tête
//Pré-conditions : file initialisée
//                 file ayant une tête (l > 0)
struct maillon consulterTete( const struct FileAttente f)
{
    return *(f.debut);
}

//Fonction permettant de calculer la longueur de la file d'attente
//Paramètres d'entrée : une file d'attente
//Valeur retournée : la taille de la file
//Pré-conditions : la file est initialisée
int calculerLongueur(const struct FileAttente f)
{
    int n;
    struct maillon *p;
    n = 0;
    p = f.debut;
    
    while (p != NULL)
    {
        n++;
        p = (*p).suivant;
    }
    
    return n;
}
