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
        if ( (*(*pp)).suivant != (*(*pp)).suivant) {
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

void ajout(struct maillon **p, struct maillon *nm)
{
    int n;
    
    if ((*p) != NULL) {
        (*nm).suivant = (*(*p)).suivant;
        (*(*p)).suivant = nm;
        n = (*(*p)).numero;
        (*(*p)).numero = (*nm).numero;
        (*nm).numero = n;
    }
    else {
        (*p) = nm;
        (*nm).suivant = nm;
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
