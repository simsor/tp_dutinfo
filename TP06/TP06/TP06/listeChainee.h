#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H

#include <iostream>

struct maillon {
	char contenu;
	struct maillon* suivant;
};

// Procédure permettant d'initialiser une liste chaînée
// Paramètre de sortie : une liste 
// Post-condition : la liste est initialisée
void initListe(struct maillon **p);

// Procédure permettant de désinitialiser une liste chaînée
// Paramètre d'entrée : la liste à désinitialiser
// Paramètre de sortie : la liste désinitialisée
// Pré-condition : la liste est initialisée
// Post-condition : la liste est désinitialisée
void desinitListe(struct maillon **p);

// Procédure permettant d'ajouter un élément en queue de liste
// Paramètres d'entrée : une liste et un maillon
// Paramètres de sortie : la liste ayant le maillon en queue
// Pré-condition : la liste est initialisée et l'élément n'est pas nul
// Post-condition : la liste possède l'élément passé en paramètre en queue
void ajoutEnQueue(struct maillon **p, struct maillon *nouv);

//Procédure permettant de concaténer deux listes
//Paramètre d'entrée : Deux listes chainées
//Paramètre de sortie : une liste chainée composée des deux précédentes
//Pré-condition : les listes sont initialisées
//Post-condition : la deuxième liste est ajoutée à la fin de la première
void concatListe(struct maillon ** l1, struct maillon *l2);

// Procédure permettant de supprimer l'élément en queue de liste
// Paramètre d'entrée : la liste
// Paramètre de sortie : la liste avec un élément en moins
// Pré-condition : la liste est initialisée
// Post-condition : la liste a perdu son dernier élément
void supprQueue(struct maillon **p);

// Fonction permettant de connaître la longueur de la liste
// Paramètre d'entrée : la liste
// Valeur retournée : la longueur de la liste
// Pré-condition : la liste est initialisée
int longueurListe(struct maillon *p);

// Fonction permettant d'observer la queue de la liste
// Paramètre d'entrée : la liste
// Valeur retournée : la queue de la liste
// Pré-condition : la liste est initialisée et possède au moins 1 élément
struct maillon queueListe(struct maillon *p);

// Procédure permettant d'afficher la liste
// Paramètre d'entrée : une liste
// Pré-condition : la liste est initialisée
void afficherListe(struct maillon *p);

#endif /* LISTECHAINEE_H */
