//
//  main.cpp
//  TP03
//
//  Created by Oncle D. on 03/10/2014.
//  Copyright (c) 2014 Oncle D. All rights reserved.
//

#include <iostream>
#include "file.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    int choix;
    struct maillon tmp;
    int numero;
    struct FileAttente f;
    init(f);
    bool continuer=true;
    
    while (continuer) {
        
        cout << "FILE D'ATTENTE" << endl << endl;
        cout << "1. Ajouter une personne en queue" << endl;
        cout << "2. Retirer la personne en tête" << endl;
        cout << "3. Consulter la personne en tête de file" << endl;
        cout << "4. Calculer la longueur de la file d'attente" << endl << endl;
        cout << "5. QUITTER" << endl;
    
        cout << "Saisir choix : ";
        cin >> choix;
        switch (choix) {
            case 1:
                cout << "Entrez le numéro de la personne : ";
                cin >> numero;
                tmp.numero=numero;
                ajoutEnQueue(f, &tmp);
                break;
            case 2:
                supprEnTete(f);
                break;
            case 3:
                tmp = consulterTete(f);
                cout << "Le numéro de la personne est : " << tmp.numero << endl;
                break;
            case 4:
                cout << "Longueur de la file d'attente : " << calculerLongueur(f) << endl;
                break;
            case 5:
                continuer=false;
                break;
            default:
                cout << "Votre choix n'est pas valide" << endl;
                break;
        }
    }
    return 0;
}

