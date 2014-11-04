
//
//  main.cpp
//  TP06
//
//  Created by Oncle D. on 24/10/2014.
//  Copyright (c) 2014 Oncle D. All rights reserved.
//

#include <iostream>
#include "arbre.h"
#include "listeChainee.h"
using namespace std;

int main(int argc, const char * argv[]) {

	abin a1, a2, a3;
	struct maillon* listeChainee;

	a1 = arbNouv();
	a2 = arbNouv();
	a3 = arbNouv();

	a1 = enracine('q', NULL, NULL);
	a2 = enracine('b', NULL, NULL);
	a3 = enracine('p', a1, a2);
	a1 = enracine('u', NULL, NULL);
	a2 = enracine('t', a1, a3);
	a1 = enracine('t', NULL, NULL);
	a1 = enracine('s', a1, NULL);
	a3 = enracine('v', NULL, NULL);
	a3 = enracine('r', a3, a1);
	a1 = enracine('a', a3, a2);

	cout << "Hauteur de l'arbre : " << hauteur(a1) << endl;

	cout << "Parcours en profondeur préfixe : " << endl;
	listeChainee = profPrefixe(a1);
	afficherListe(listeChainee);

	cout << endl << "Parcours en profondeur infixe : " << endl;
	listeChainee = profInfixe(a1);
	afficherListe(listeChainee);

	cout << endl << "Parcours en profondeur postfixe : " << endl;
	listeChainee = profPostfixe(a1);
	afficherListe(listeChainee);

	cout << endl << "Parcours en largeur : " << endl;
	listeChainee = largeur(a1);
	afficherListe(listeChainee);

	cout << endl;
	
    return 0;
}
