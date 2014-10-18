//
//  listeCirculaire.cpp
//  TP05
//
//  Created by Oncle D. on 15/10/2014.
//  Copyright (c) 2014 Oncle D. All rights reserved.
//

#include "listeCirculaire.h"

void init(struct maillon **pp)
{
    (*pp) = NULL;
}

void desinit(struct maillon **pp)
{
    while ( (*pp) != NULL)
    {
        supp(pp);
    }
}

void supp(struct maillon **pp)
{
    struct maillon *tmp;
    if ((*pp) != NULL) {
        if ( (*(*pp)).suivant != NULL) {
            tmp = (*(*pp)).suivant;
            (*(*pp)).numero = (*tmp).numero;
            (*(*pp)).suivant = (*tmp).suivant;
            delete tmp;
        }
        else {
            delete (*pp);
            (*pp) = NULL;
        }
    }
}

void affiche(struct maillon *p)
{
    struct maillon *tmp;
    tmp = p;
    if (p != NULL) {
        do {
            cout << (*tmp).numero << endl;
            tmp = (*tmp).suivant;
        } while (tmp != p);
    }
}

void rotation(struct maillon **pp)
{
    if ((*pp) != NULL) {
        (*pp) = (*(*pp)).suivant;
    }
}

void ajout(struct maillon **pp, struct maillon nm)
{
    struct maillon *tmp;
    int n;
    
    tmp = &nm;
    
    if ((*pp) != NULL) {
        (*tmp).suivant = (*(*pp)).suivant;
        (*(*pp)).suivant = tmp;
        n = (*(*pp)).numero;
        (*(*pp)).numero = (*tmp).numero;
        (*tmp).numero = n;
    }
    else {
        (*pp) = tmp;
        (*tmp).suivant = tmp;
    }
}

int nbMaillon(struct maillon *p)
{
    struct maillon *tmp;
    int cpt;
    
    if (p != NULL) {
        tmp = p;
        cpt = 0;
        do {
            cpt++;
            tmp = (*tmp).suivant;
        } while (tmp != p);
        return cpt;
    }
    else
        return 0;
}