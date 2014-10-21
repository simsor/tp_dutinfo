//
//  main.cpp
//  TP05
//
//  Created by Oncle D. on 15/10/2014.
//  Copyright (c) 2014 Oncle D. All rights reserved.
//

#include <iostream>
#include "listeCirculaire.h"

int main(int argc, const char * argv[]) {

    struct maillon *p;
    struct maillon *tmp;
    bool continuer;
    int choix;
    int nbr;
    int numero;
    
    continuer = true;
    init(&p);
    
    while (continuer) {
        cout << "1. Afficher la liste" << endl;
        cout << "2. Ajouter un élément" << endl;
        cout << "3. Compter le nombre de maillon" << endl;
        cout << "4. Faire une rotation" << endl;
        cout << "5. Désinitialiser la liste" << endl;
        cout << "6. QUITTER" << endl;
        
        cout << "Saisir choix : ";
        cin >> choix;
        
        switch (choix) {
            case 1:
                affiche(p);
                break;
                
            case 2:
                cout << "Numéro de l'élément : ";
                cin >> numero;
				tmp = new struct maillon;
                (*tmp).numero = numero;
                ajout(&p, tmp);
				break;
            
            case 3:
                nbr = nbMaillon(p);
				cout << "Il y a " << nbr << " éléments dans la liste" << endl;
				break;

		    case 4:
				if (nbMaillon(p) > 0) {
					rotation(&p);
					cout << "Rotation effectuée." << endl;
				}
				else
					cout << "La liste est vide, impossible de faire une rotation." << endl;
			    break;

		    case 5:
			    desinit(&p);
			    cout << "Liste désinitialisée." << endl;
			    break;

		    case 6:
				continuer = false;
				break;
				
            default:
                break;
        }
    }
    
    return 0;
}
