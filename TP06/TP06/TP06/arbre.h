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

//Fonction permettant de créer un arbre
//Valeur retournée : un nouvel arbre
abin arbNouv();

//Procédure permettant de désinitialiser un arbre
//Paramètre d'entrée : un arbre
//Paramètre de sortie : un arbre désinitialisé
//Pré-condition : l'arbre est initialisé
//Post-condition : l'arbre est vide et désinitialisé
void desinit(abin *a);

//Fonction permettant d'enraciner deux arbres à un noeud donné
//Paramètres d'entrée : Deux arbres gauche et droit
//						Un noeud
//Valeur retournée : un arbre composé du noeud donné comme racine et des arbres
//					 droit et gauche
abin enracine(char etiq, abin g, abin d);

//Fonction retournant le sous-arbre gauche
//Paramètre d'entrée : un arbre
//Valeur retournée : le sous-arbre gauche
//Pré-condition : l'arbre est initialisé
abin gauche(abin a);

//Fonction retournant le sous-arbre droit
//Paramètre d'entrée : un arbre
//Valeur retournée : le sous-arbre droit
//Pré-condition : l'arbre est initialisé
abin droite(abin a);

//Fonction permettant de savoir si un arbre est vide
//Paramètre d'entrée : un arbre
//Valeur retournée : un booléen indiquant si l'arbre est vide
//Pré-condition : L'arbre est initialisé
bool est_vide(abin a);

//Fonction retournant la racine
//Paramètre d'entrée : un arbre
//Valeur retournée : la racine
//Pré-condition : l'arbre est initialisé et il a une racine
struct noeud racine(abin a);

//Fonction permettant de calculer la hauteur
//Paramètre d'entrée : un arbre
//Valeur retournée : la hauteur de l'arbre
//Pré-condition : l'arbre est initialisé
int hauteur(abin a);

//Fonction parcourant l'arbre en profondeur (préfixe)
//Paramètre d'entrée : un arbre
//Valeur retournée : une liste chainée
//Pré-condition : l'arbre est initialisé
struct maillon* profPrefixe(abin a);

//Fonction parcourant l'arbre en profondeur (infixe)
//Paramètre d'entrée : un arbre
//Valeur retournée : une liste chainée
//Pré-condition : l'arbre est initialisé
struct maillon* profInfixe(abin a);

//Fonction parcourant l'arbre en profondeur (postfixe)
//Paramètre d'entrée : un arbre
//Valeur retournée : une liste chainée
//Pré-condition : l'arbre est initialisé
struct maillon* profPostfixe(abin a);

//Fonction parcourant l'arbre en largeur
//Paramètre d'entrée : un arbre
//Valeur retournée : une liste chainée
//Pré-condition : l'arbre est initialisé
struct maillon* largeur(abin a);

// Fonction retournant une liste chainée contenant les etiquettes au niveau donnée
// Paramètres d'entrée : un arbre et un niveau
// Valeur retournée : une liste chainée contenant les étiquettes
// Pré-condition : l'arbre est initialisé, le niveau est >= 0
struct maillon* valeursAuNiveau(abin a, int niveau);

#endif /* defined(__TP06__arbre__) */
