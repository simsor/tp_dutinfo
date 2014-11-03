//
//  arbre.h
//  TP06
//
//  Created by Oncle D. on 24/10/2014.
//  Copyright (c) 2014 Oncle D. All rights reserved.
//

#ifndef __TP06__arbre__
#define __TP06__arbre__

#include <iostream>
#include "listeChainee.h"

struct noeud {
	char etiquette;
	struct noeud *ag, *ad;
};

typedef struct noeud* abin;

abin arbNouv();
void desinit(abin *a);
abin enracine(char etiq, abin g, abin d);
abin gauche(abin a);
abin droite(abin a);
bool est_vide(abin a);
struct noeud racine(abin a);
int hauteur(abin a);
struct maillon* profPrefixe(abin a);
struct maillon* profInfixe(abin a);
struct maillon* profPostfixe(abin a);
struct maillon* largeur(abin a);
struct maillon* valeursAuNiveau(abin a, int niveau);

#endif /* defined(__TP06__arbre__) */
