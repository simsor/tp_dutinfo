#include "listeChainee.h"

void initListe(struct maillon **p)
{
	(*p) = NULL;
}

void desinitListe(struct maillon **pp)
{
	if ((*pp) != NULL) {
		desinitListe(&(*(*pp)).suivant);
		delete (*pp);
	}
}

void ajoutEnQueue(struct maillon **pp, struct maillon *nouv)
{
	struct maillon *tmp;
	tmp = (*pp);

	if (tmp != NULL) {
		while ((*tmp).suivant != NULL) {
			tmp = (*tmp).suivant;
		}

		(*tmp).suivant = nouv;
		(*nouv).suivant = NULL;
	}
	else {
		(*pp) = nouv;
		(*(*pp)).suivant = NULL;
	}
}

void concatListe(struct maillon **l1, struct maillon *l2)
{
	struct maillon *tmp;
	tmp = (*l1);

	if (tmp != NULL) {
		while ( (*tmp).suivant != NULL) {
			tmp = (*tmp).suivant;
		}

		(*tmp).suivant = l2;
	}
	else {
		(*l1) = l2;
	}
}

void supprQueue(struct maillon **pp)
{
	struct maillon *tmp, *avantdernier;
	tmp = (*pp);
	avantdernier = NULL;

	if (tmp != NULL) {
		while ((*tmp).suivant != NULL) {
			avantdernier = tmp;
			tmp = (*tmp).suivant;
		}

		delete tmp;
		if (avantdernier != NULL) {
			(*avantdernier).suivant = NULL;
		}
		else {
			(*pp) = NULL;
		}
	}
}

int longueurListe(struct maillon *p)
{
	int n;
	struct maillon *tmp;

	n = 0;
	tmp = p;
	while (tmp != NULL) {
		tmp = (*tmp).suivant;
		n++;
	}

	return n;
}

struct maillon queueListe(struct maillon *p)
{
	return (*p);
}

void afficherListe(struct maillon *p)
{
	struct maillon *tmp;
	tmp = p;
	while (tmp != NULL) {
		std::cout << (*tmp).contenu << " ";
		tmp = (*tmp).suivant;
	}
}
