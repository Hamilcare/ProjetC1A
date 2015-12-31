#ifndef PLATEAU_H
	#define PLATEAU_H
	#include "include.h"
	#include "bushi.h"

typedef struct Plateau Plateau;
struct Plateau{
	Bushi pions [N][N];
	int quiJoue;
};

extern Plateau plateau;

void init_plateau(Plateau *plateau);
void init_plateaubis(Plateau *plateau);
void affiche_plateau(Plateau *plateau);
void affiche_plateau_deplacement(Plateau *plateau,Bushi* bushiBouge,Bushi* tab,int k);
void nouvelle_partie(Plateau *plateau);


void affiche_bis(Plateau *plateau);


Bushi* bushi_joueur(Plateau *plateau, int joueur);
Bushi deplacement_bushi(Plateau *plateau,Bushi *bushi);
int est_valide(Plateau *plateau,Bushi bushi, int x, int y);

int deplacement_singe(Plateau *plateau,Bushi *bushi, Bushi moove[]);
int deplacement_lion(Plateau *plateau,Bushi *bushi, Bushi moove[]);
int deplacement_dragon(Plateau *plateau,Bushi *bushi, Bushi moove[]);

void resetJouable(Plateau *plateau,int joueur,int valeur, Bushi* exception);

void tour_joueur(Plateau *plateau,int joueur);

void empty_buffer();
#endif
