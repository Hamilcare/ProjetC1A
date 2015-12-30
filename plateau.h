#ifndef PLATEAU_H
	#define PLATEAU_H
	#include "include.h"
	#include "bushi.h"

typedef struct Plateau Plateau;
struct Plateau{
	Bushi pions [N][N];
};

extern Plateau plateau;

void init_plateau(Plateau *plateau);
void init_plateaubis(Plateau *plateau);
void affiche_plateau(Plateau *plateau);
void nouvelle_partie(Plateau *plateau);


void affiche_bis(Plateau *plateau);


Bushi* bushi_joueur(Plateau *plateau, int joueur);
Bushi deplacement_bushi(Plateau *plateau,Bushi *bushi);
int deplacement_singe(Plateau *plateau,Bushi *bushi, Bushi moove[]);
int est_valide(Plateau *plateau,Bushi bushi, int x, int y);
void resetJouable(Plateau *plateau,int joueur);

void tour_joueur(Plateau *plateau,int joueur);

void empty_buffer();
#endif
