//
//  main.cpp
//  TP03
//
//  Created by Oncle D. on 03/10/2014.
//  Copyright (c) 2014 Oncle D. All rights reserved.
//

#include <iostream>
#include <string.h>
#include "file.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    int choix;
    struct maillon *p_maillon;
	struct maillon maillon_temp;
    int numero;
	char nom[80];
    struct FileAttente f;
    init(f);
    bool continuer=true;
    
    while (continuer) {
        
        cout << "FILE D'ATTENTE" << endl << endl;
        cout << "1. Ajouter une personne en queue" << endl;
        cout << "2. Retirer la personne en tête" << endl;
        cout << "3. Consulter la personne en tête de file" << endl;
        cout << "4. Calculer la longueur de la file d'attente" << endl;
		cout << "5. Désinitialiser la liste" << endl << endl;
		
        cout << "6. QUITTER" << endl;
    
        cout << "Saisir choix : ";
        cin >> choix;
        switch (choix) {
		case 1:
			cout << "Entrez le numéro de la personne : ";
			cin >> numero;
			cout << "Entrez son nom : ";
			cin >> nom;
			p_maillon = new maillon;
			(*p_maillon).numero = numero;
			strcpy((*p_maillon).nom, nom);
			(*p_maillon).suivant = NULL;
			ajoutEnQueue(f, p_maillon);
			break;
		case 2:
			supprEnTete(f);
			break;
		case 3:
			if (calculerLongueur(f) > 0) {
				maillon_temp = consulterTete(f);
				cout << "Le numéro de la personne est : " << maillon_temp.numero << endl;
				cout << "Son nom est : " << maillon_temp.nom << endl;
			}
			else
				cout << "La liste est vide, il n'y a pas de tête." << endl;
			break;
		case 4:
			cout << "Longueur de la file d'attente : " << calculerLongueur(f) << endl;
			break;
		case 5:
			desInit(f);
			cout << "Liste désinitialisée." << endl;
			break;
		case 6:
			continuer=false;
			break;
		default:
			cout << "Votre choix n'est pas valide" << endl;
			break;
        }
    }
    return 0;
}

