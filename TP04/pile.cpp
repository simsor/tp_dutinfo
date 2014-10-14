//
//  pile.cpp
//  TP03
//
//  Created by Oncle D. on 10/10/2014.
//  Copyright (c) 2014 Oncle D. All rights reserved.
//

#include "pile.h"

//Procédure permettant d'initialiser une pile.
//Paramètres de sortie : un pile initialisée
//Post-condition : la pile est initialisée
void initPile(struct Pile &p)
{
    p.tete = NULL;
}

//Procédure permettant de désinitialiser une pile.
//Paramètres d'entrée : une pile
//Paramètres de sortie : une pile
//Pré-condition : la pile est initialisée
//Post-condition : la pile est vide et désinitialisée
void desinitPile(struct Pile &p)
{
    while (p.tete != NULL)
    {
        depiler(p);
    }
    p.tete = NULL;
}

//Procédure permettant d'empiler un élément sur la pile
//Paramètres Entrée : une pile et un élément de pile à ajouter
//Paramètre de sortie : la pile ayant l'élément en tête
//Pré-condition : la pile est initialisée
//Post-condition : la pile possède l'élément ajouté en tête
void empiler(struct Pile &p, struct CompoPile *cp)
{
    struct CompoPile *tmp;
    tmp = p.tete;
    p.tete = cp;
    if (p.tete == NULL)
        (*p.tete).suivant = tmp;
}

//Procédure permettant de dépiler un élément sur la pile
//Paramètres Entrée : une pile
//Paramètre de sortie : la pile ayant l'élément en tête supprimé
//Pré-condition : la pile est initialisée et non vide
//Post-condition : la pile avec l'élément de tête en moins
void depiler(struct Pile &p)
{
    struct CompoPile *tmp;
    tmp = (*p.tete).suivant;
    delete p.tete;
    p.tete = tmp;
}

//Fonction permettant d'obtenir la tête de la pile
//Paramètres Entrée : une pile
//Valeur retournée : Le composant de pile (CompoPile) en tête
//Pré-condition : la pile est initialisée et non-vide
struct CompoPile obtenirTete(struct Pile p)
{
    return *p.tete;
}

//Fonction permettant d'obtenir la hauteur de la pile
//Paramètres d'entrée : un pile
//Valeur retournée : la hauteur de la pile
//Pré-condition : La pile est initialisée
int hauteur(struct Pile p)
{
    struct CompoPile *tmp;
    int cpt = 0;
    tmp = p.tete;
    while (tmp != NULL) {
        cpt = cpt + 1;
        tmp = (*tmp).suivant;
    }
    return cpt;
}