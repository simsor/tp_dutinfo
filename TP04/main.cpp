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
#include "pile.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    int choix;
    struct maillon *p_maillon;
    struct maillon maillon_temp;
    int numero;
    char nom[80];
    struct FileAttente f;
	struct FileAttente filetemp;
	struct Pile historique;
	struct CompoPile* p_tmpcompo;
	struct CompoPile tmpcompo;
    bool continuer=true;

	initPile(historique);
    init(f);
	
    while (continuer) {
        
        cout << "FILE D'ATTENTE" << endl << endl;
        cout << "1. Ajouter une personne en queue" << endl;
        cout << "2. Retirer la personne en tête" << endl;
        cout << "3. Consulter la personne en tête de file" << endl;
        cout << "4. Calculer la longueur de la file d'attente" << endl;
        cout << "5. Désinitialiser la liste" << endl;
		cout << "6. Undo"<< endl << endl;
        
        cout << "7. QUITTER" << endl;
        
        cout << "Saisir choix : ";
        cin >> choix;

		if (choix == 1 || choix == 2 || choix == 5) { // Choix destructif
			// On sauvegarde la file actuelle
			filetemp = dupFile(f);
			p_tmpcompo = new CompoPile;
			(*p_tmpcompo).contenu = filetemp;
			empiler(historique, p_tmpcompo);
		}
		
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
			
		case 6: // Undo
			if (hauteur(historique) > 0) {
				tmpcompo = obtenirTete(historique);
				f = tmpcompo.contenu;
				depiler(historique);
			}
			else
				cout << "Il n'y a rien à annuler." << endl;
			break;
			
		case 7:
			continuer=false;
			break;
			
		default:
			cout << "Votre choix n'est pas valide" << endl;
			break;
        }

		cout << endl;
    }
    return 0;
}
