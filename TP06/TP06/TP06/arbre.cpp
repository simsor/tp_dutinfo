//
//  arbre.cpp
//  TP06
//
//  Created by Oncle D. on 24/10/2014.
//  Copyright (c) 2014 Oncle D. All rights reserved.
//

#include "arbre.h"
#include "listeChainee.h"

abin arbNouv()
{
	return NULL;
}

void desinit(abin *a)
{
	if ( (*a) != NULL) {
		desinit(&(*(*a)).ag);
		desinit(&(*(*a)).ad);
		(*(*a)).ag = NULL;
		(*(*a)).ad = NULL;
		delete (*a);
	}
}

abin enracine(char etiq, abin g, abin d)
{
	abin nd;
	nd = new struct noeud;

	(*nd).etiquette = etiq;
	(*nd).ag = g;
	(*nd).ad = d;
	return nd;
}

abin gauche(abin a)
{
	if (a != NULL)
		return (*a).ag;
	else
		return NULL;
}

abin droite(abin a)
{
	if (a != NULL)
		return (*a).ad;
	else
		return NULL;
}

bool est_vide(abin a)
{
	return (a == NULL);
}

struct noeud racine(abin a)
{
	return (*a);
}

int hauteur(abin a)
{
	int gauche, droite;
	gauche = 0;
	droite = 0;

	if (a != NULL) {
		gauche = hauteur((*a).ag);
		droite = hauteur((*a).ad);
		return (1 + ((gauche > droite) ? gauche : droite));
	}
	else
		return 0;
}

struct maillon* profPrefixe(abin a)
{
	struct maillon *np, *m_etiq;

	if (a != NULL) {
		initListe(&np);
		m_etiq = new struct maillon;
		(*m_etiq).contenu = (*a).etiquette;
		ajoutEnQueue(&np, m_etiq);
		concatListe(&np, profPrefixe((*a).ag));
		concatListe(&np, profPrefixe((*a).ad));
		return np;
	}
	else
		return NULL;
}

struct maillon* profInfixe(abin a)
{
	struct maillon *np, *m_etiq;

	if (a != NULL) {
		initListe(&np);
		m_etiq = new struct maillon;
		(*m_etiq).contenu = (*a).etiquette;
		concatListe(&np, profInfixe((*a).ag));
		ajoutEnQueue(&np, m_etiq);
		concatListe(&np, profInfixe((*a).ad));
		return np;
	}
	else
		return NULL;
}

struct maillon* profPostfixe(abin a)
{
	struct maillon *np, *m_etiq;

	if (a != NULL) {
		initListe(&np);
		m_etiq = new struct maillon;
		(*m_etiq).contenu = (*a).etiquette;
		concatListe(&np, profPostfixe((*a).ag));
		concatListe(&np, profPostfixe((*a).ad));
		ajoutEnQueue(&np, m_etiq);
		return np;
	}
	else
		return NULL;
}

struct maillon *largeur(abin a)
{
	struct maillon *np;
	int hauteurArbre, i;

	if (a != NULL) {
		initListe(&np);
		hauteurArbre = hauteur(a);
		for (i = 0; i < hauteurArbre; i++) {
			concatListe(&np, valeursAuNiveau(a, i));
		}
		return np;
	}
	else
		return NULL;
}

struct maillon* valeursAuNiveau(abin a, int niveau)
{
	struct maillon *np, *m_etiq;
	initListe(&np);
	if (a != NULL) {
		if (niveau == 0) {
			m_etiq = new struct maillon;
			(*m_etiq).contenu = (*a).etiquette;
			ajoutEnQueue(&np, m_etiq);
		}
		else {
			concatListe(&np, valeursAuNiveau((*a).ag, niveau - 1));
			concatListe(&np, valeursAuNiveau((*a).ad, niveau - 1));
		}
	}

	return np;
}
