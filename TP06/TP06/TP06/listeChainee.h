#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H

#include <iostream>

struct maillon {
	char contenu;
	struct maillon* suivant;
};

void initListe(struct maillon **p);
void desinitListe(struct maillon **p);
void ajoutEnQueue(struct maillon **p, struct maillon *nouv);
void concatListe(struct maillon ** l1, struct maillon *l2);
void supprQueue(struct maillon **p);
int longueurListe(struct maillon *p);
struct maillon queueListe(struct maillon *p);
void afficherListe(struct maillon *p);

#endif /* LISTECHAINEE_H */
