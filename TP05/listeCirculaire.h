//
//  listeCirculaire.h
//  TP05
//
//  Created by Oncle D. on 15/10/2014.
//  Copyright (c) 2014 Oncle D. All rights reserved.
//

#ifndef __TP05__listeCirculaire__
#define __TP05__listeCirculaire__

#include <stdio.h>
#include <iostream>
using namespace std;

struct maillon {
    int numero;
    struct maillon *suivant;
};

void init(struct maillon **pp);
void desinit(struct maillon **pp);
void supp(struct maillon **pp);
void affiche(struct maillon *p);
void rotation(struct maillon **pp);
void ajout(struct maillon **p, struct maillon *nm);
int nbMaillon(struct maillon *p);
#endif /* defined(__TP05__listeCirculaire__) */
