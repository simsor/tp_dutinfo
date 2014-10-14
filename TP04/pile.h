//
//  pile.h
//  TP03
//
//  Created by Oncle D. on 10/10/2014.
//  Copyright (c) 2014 Oncle D. All rights reserved.
//

#ifndef __TP03__pile__
#define __TP03__pile__

#include "file.h"

struct Pile
{
    struct CompoPile *tete;
};

struct CompoPile
{
    FileAttente contenu;
    struct CompoPile *suivant;
};

void initPile( struct Pile &p);
void desinitPile(struct Pile &p);
void empiler(struct Pile &p, struct CompoPile *cp);
void depiler(struct Pile &p);
struct CompoPile obtenirTete(struct Pile p);
int hauteur(struct Pile p);

#endif /* defined(__TP03__pile__) */