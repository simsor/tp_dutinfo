//
//  file.h
//  TP03
//
//  Created by Oncle D. on 03/10/2014.
//  Copyright (c) 2014 Oncle D. All rights reserved.
//

#ifndef __TP03__file__
#define __TP03__file__

#include <stdio.h>

struct maillon {
    int numero;
    struct maillon *suivant;
	char nom[80];
};

struct FileAttente {
    struct maillon *debut;
    struct maillon *fin;
};

void init(struct FileAttente &f);
void desInit(struct FileAttente &f);
void ajoutEnQueue( struct FileAttente &f, struct maillon *p);
void supprEnTete( struct FileAttente &f);
struct maillon consulterTete( const struct FileAttente f);
int calculerLongueur( const struct FileAttente f);

#endif /* defined(__TP03__file__) */
